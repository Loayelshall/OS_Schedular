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
    int burst_time, process_num, waiting_time, arrival_time, remaining_time;
};


// Processes main vector
QVector<process> processes;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->quantumPeriod->hide();


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



}

void MainWindow::on_pushButton_2_clicked()
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
    ui->pushButton_2->hide();
    ui->fcfs->hide();
    ui->rr->hide();
    ui->sjf->hide();
    ui->radioButton_4->hide();
    ui->label_5->hide();

    // Display Options



    QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();


    for (int i=0; i<processes.size() ;i++ ) {
          QBarSet *set0 = new QBarSet(QString::number(processes[i].process_num));
           *set0 << processes[i].burst_time;
           series->append(set0);
    }

    QChart *chart = new QChart();





    chart->setAnimationOptions(QChart::AllAnimations);


    QValueAxis *axisX = new QValueAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);




    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QPalette pal = qApp->palette();

    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));

    qApp->setPalette(pal);



    chart->addSeries(series);
    chart->setTitle("Processes");
    chart->legend()->hide();

    chartView->setRenderHint(QPainter::Antialiasing);


//MainWindow w;
setCentralWidget(chartView);
show();


}




void MainWindow::on_rr_toggled(bool checked)
{
    if(checked){
        ui->rr->setChecked(true);
        ui->quantumPeriod->show();
    } else {
        ui->rr->setChecked(false);
        ui->quantumPeriod->hide();
    }

}

void MainWindow::on_rr_clicked(bool checked)
{
    if(checked){
        ui->rr->setChecked(true);
        ui->quantumPeriod->show();
    } else {
        ui->rr->setChecked(false);
        ui->quantumPeriod->hide();
    }
}




