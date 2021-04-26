#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <algorithm>
#include <SJF.h>

#include <QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
QT_CHARTS_USE_NAMESPACE
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLineSeries>


// Processes number

int chartIndex;

int currentIndex = 0;


// Calculating avg waiting time
float calculateAvgWaitingTime(QVector<process> processes){
    float avgWaiting = 0;
    QVector<process> unique;
    unique.append(processes[0]);
    for (int i = 1; i<processes.size() ;i++ ) {
        int didFind = 0;
        for(int j = 0; j < unique.size() ; j++){
            if(processes[i].arrival_time == unique[j].arrival_time &&
                    processes[i].process_num == unique[j].process_num &&
                        processes[i].burst_time == unique[j].burst_time){
                didFind = 1;
            }
        }
        if(didFind == 0){
            unique.append(processes[i]);
        }
    }

    for (int i = 0; i < unique.size() ; i++) {
        avgWaiting = unique[i].start_time - unique[i].arrival_time;
    }

    return avgWaiting/unique.size();
}


// Processes main vector
QVector<process> processes;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->quantumPeriod->hide();
    ui->piSameType->hide();
    ui->pioLabel->hide();
    ui->preLabel->hide();
    ui->preBox->hide();
    ui->simulateButton->setEnabled(false);
    ui->table2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_2->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(currentIndex < numberProccess){
        // Taking input from user and saving it in a vector
        process tempSt;
        tempSt.burst_time = ui->burstTime->text().toInt();
        tempSt.process_num = currentIndex;
        tempSt.arrival_time = ui->arrivalTime->text().toInt();
        processes.append(tempSt);

        currentIndex++;

        ui->textBrowser->append("Process: " + QString::number(tempSt.process_num));
        ui->textBrowser->append("Arrival Time: " + QString::number(tempSt.arrival_time));
        ui->textBrowser->append("Burst Time: " + QString::number(tempSt.burst_time));
        ui->textBrowser->append(" ");

        ui->simulateButton->setEnabled(true);
    }



}




void MainWindow::on_schedularType_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "RR"){
        ui->quantumPeriod->show();
        ui->piSameType->hide();
        ui->preBox->hide();

    } else if(arg1 == "Priority"){
        ui->quantumPeriod->hide();
        ui->piSameType->show();
        ui->preBox->show();
        ui->pioLabel->show();
        ui->preLabel->show();

    } else if(arg1 == "SJF"){
        ui->quantumPeriod->hide();
        ui->piSameType->hide();
        ui->preBox->show();
        ui->pioLabel->hide();
        ui->preLabel->show();
    } else {
        ui->quantumPeriod->hide();
        ui->piSameType->hide();
        ui->preBox->hide();
        ui->pioLabel->hide();
        ui->preLabel->hide();
    }
}




void MainWindow::on_simulateButton_clicked()
{

    // Hide process inputs
    ui->arrivalTime->hide();
    ui->burstTime->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->textBrowser->hide();
    ui->pushButton->hide();
    ui->simulateButton->hide();
    ui->label_5->hide();
    ui->table2->show();
    ui->schedularType->hide();
    ui->preBox->hide();
    ui->piSameType->hide();
    ui->quantumPeriod->hide();
    ui->preLabel->hide();
    ui->pioLabel->hide();
    ui->pushButton_2->show();
    ui->pushButton_3->show();


    QWidget *firstPageWidget = new QWidget;
    QWidget *secondPageWidget = new QWidget;

    QStackedWidget *stackedWidget = ui->stackedWidget;
       stackedWidget->addWidget(firstPageWidget);
       stackedWidget->addWidget(secondPageWidget);







    // Display Options
    QVector<process> drawingVec;

    if(ui->schedularType->currentText() == "SJF"){
        if(ui->preBox->currentText() == "Preemptive"){
            SJF::calc_new_order_p(processes, drawingVec, processes.size());
        } else if(ui->preBox->currentText() == "Non-Preemptive"){
            SJF::calc_new_order_np(processes, drawingVec, processes.size());
        }
    }


    float avgTime = calculateAvgWaitingTime(drawingVec);
    ui->table2->append("Average Waiting Time : " + QString::number(avgTime) + "%");
    ui->table2->append(" ");

    ui->table2->append("Scheduled Processes Details:");

    QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
    QValueAxis *axisX = new QValueAxis();
    QBarCategoryAxis *axisY = new QBarCategoryAxis;




    int max = 0;
    QChart *chart = new QChart();
    for (int i=0; i<drawingVec.size() ;i++ ) {
            if(i != 0){
                int prev = drawingVec[i-1].start_time+drawingVec[i-1].burst_time;
                if(drawingVec[i].start_time > prev){
                    QBarSet *set0 = new QBarSet("Empty");
                    *set0 << drawingVec[i].start_time - prev;
                    series->append(set0);
                    QColor color = 0x687980;
                    set0->setColor(color);

                }
            }
//
            QBarSet *set0 = new QBarSet("P" + QString::number(drawingVec[i].process_num));
            *set0 << drawingVec[i].burst_time;
            series->append(set0);
            QColor color = 0xfffff - (drawingVec[i].process_num)*50;
            set0->setColor(color);
            set0->setLabel("P" + QString::number(drawingVec[i].process_num));
            set0->setPen(QPen(Qt::black, 2));
            axisY->insert(drawingVec[i].start_time,"P" + QString::number(drawingVec[i].process_num));
            axisX->setLabelsVisible(true);
            if(max < drawingVec[i].start_time+drawingVec[i].burst_time){
                max = drawingVec[i].start_time+drawingVec[i].burst_time;
            }
        QPoint point(0, drawingVec[i].start_time+drawingVec[i].burst_time);

        chart->mapToPosition(point);
        ui->table2->append("   -P" + QString::number(drawingVec[i].process_num));
        ui->table2->append("   -Start Time: " + QString::number(drawingVec[i].start_time));
        ui->table2->append("   -End Time: " + QString::number(drawingVec[i].start_time + drawingVec[i].burst_time));
        ui->table2->append(" ");

    }



    axisX->setMinorTickCount(10);
    axisX->setRange(0,max);
    axisX->setGridLineVisible(true);

    series->attachAxis(axisX);

    chart->setAnimationOptions(QChart::AllAnimations);

    series->setLabelsVisible(true);
    chart->setAcceptHoverEvents(true);
    chart->setToolTip("Processes");
//    chart->addAxis(axisY, Qt::AlignBottom);
    chart->addAxis(axisX, Qt::AlignBottom);

    chart->createDefaultAxes();



    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QPalette pal = qApp->palette();

    pal.setColor(QPalette::Window, QRgb(0x02475e));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));

    qApp->setPalette(pal);



    chart->addSeries(series);
    chart->setTitle("Processes");


//    setMouseTracking(true);


//    setCentralWidget(chartView);

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->addWidget(chartView);

    ui->stackedWidget->setCurrentWidget(chartView);
    chartIndex =  ui->stackedWidget->currentIndex();

    show();

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(chartIndex);
}
