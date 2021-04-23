#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector2D>


QVector<QVector<QString>> processes;
QString test = "test";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



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

    // Display Chart


}

