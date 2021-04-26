#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector2D>

#include <QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
QT_CHARTS_USE_NAMESPACE
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

// Main Struct
struct process
{
    int burst_time, process_num, waiting_time, arrival_time, remaining_time, start_time;
};

// Processes number
int processesNo;

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


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // Taking input from user and saving it in a vector
    QString processName = ui->proccesName->text();
    QString arrivalTime = ui->arrivalTime->text();
    QString burstTime = ui->burstTime->text();

    process tempSt;
    tempSt.burst_time = ui->burstTime->text().toInt();
    tempSt.process_num = ui->proccesName->text().toInt();
    tempSt.arrival_time = ui->arrivalTime->text().toInt();
    processes.append(tempSt);


    ui->textBrowser->append("Process: " + QString::number(tempSt.process_num));
    ui->textBrowser->append("Arrival Time: " + QString::number(tempSt.arrival_time));
    ui->textBrowser->append("Burst Time: " + QString::number(tempSt.burst_time));
    ui->textBrowser->append(" ");

    ui->simulateButton->setEnabled(true);


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
    ui->proccesName->hide();
    ui->arrivalTime->hide();
    ui->burstTime->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->textBrowser->hide();
    ui->pushButton->hide();
    ui->simulateButton->hide();
    ui->label_5->hide();




    // Display Options



    QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
    QValueAxis *axisX = new QValueAxis();


    int max = 0;
    for (int i=0; i<processes.size() ;i++ ) {
            if(i != 0){
                int prev = processes[i-1].arrival_time+processes[i-1].burst_time;
                if(processes[i].arrival_time > prev){
                    QBarSet *set0 = new QBarSet("Empty");
                    *set0 << processes[i].arrival_time - prev;
                    series->append(set0);
                    QColor color = 0xffffff;
                    set0->setColor(color);

                }
            }

            QBarSet *set0 = new QBarSet(QString::number(processes[i].process_num));
            *set0 << processes[i].burst_time;
            series->append(set0);
            QColor color = 0xfffff - (processes[i].process_num)*50;
            set0->setColor(color);

            if(max < processes[i].arrival_time+processes[i].burst_time){
                max = processes[i].arrival_time+processes[i].burst_time;
            }
    }

    QChart *chart = new QChart();

    axisX->setRange(0,max);
    series->attachAxis(axisX);

    chart->setAnimationOptions(QChart::AllAnimations);


    chart->addAxis(axisX, Qt::AlignBottom);





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






    setCentralWidget(chartView);
    show();

}
