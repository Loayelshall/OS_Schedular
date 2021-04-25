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


QVector<QVector<QString>> processes;
//QStringList processes;
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
    temp.append(processName);
    temp.append(arrivalTime);
    temp.append(burstTime);
    processes.append(temp);
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



    QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();


    for (int i=0; i<processes.size() ;i++ ) {
          QBarSet *set0 = new QBarSet(processes[i][0]);
           *set0 << processes[i][2].toInt() ;
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




