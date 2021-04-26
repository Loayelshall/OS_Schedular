#include "avgwaiting.h"
#include "mainwindow.h"
#include "ui_avgwaiting.h"

avgWaiting::avgWaiting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::avgWaiting)
{
    ui->setupUi(this);
    ui->avgWaitLabel->setText(label);
}


avgWaiting::~avgWaiting()
{
    delete ui;
}
