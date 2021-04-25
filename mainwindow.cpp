#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector2D>

#include <QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
QT_CHARTS_USE_NAMESPACE
#include <QtCharts/QHorizontalStackedBarSeries>


QVector<QVector<QString>> processes;

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
    QVector<QString> temp;
    temp.push_back(processName);
    temp.push_back(arrivalTime);
    temp.push_back(burstTime);
    processes.push_back(temp);
    ui->textBrowser->append("Process: " + temp[0]);
    ui->textBrowser->append("Arrival Time: " + temp[1]);
    ui->textBrowser->append("Burst Time: " + temp[2]);
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



    QBarSet *set0 = new QBarSet("Altuve");
    QBarSet *set1 = new QBarSet("Martinez");
    QBarSet *set2 = new QBarSet("Segura");
    QBarSet *set3 = new QBarSet("Simmons");
    QBarSet *set4 = new QBarSet("Trout");


    *set0 << 283 ;
    *set1 << 250 ;
    *set2 << 294 ;
    *set3 << 248 ;
    *set4 << 323 ;


     QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();


//    chart->addSeries(series);



    chart->setAnimationOptions(QChart::AllAnimations);

    QStringList categories;
    categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";




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




