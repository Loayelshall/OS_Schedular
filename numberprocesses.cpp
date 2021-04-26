#include "numberprocesses.h"
#include "mainwindow.h"
#include "ui_numberprocesses.h"

numberProcesses::numberProcesses(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::numberProcesses)
{
    ui->setupUi(this);
}

numberProcesses::~numberProcesses()
{
    delete ui;
}

void numberProcesses::on_noProAction_clicked()
{
    if(ui->numberOfProcesses->text() != ""){
        numberProcesses::close();
        w.numberProccess = ui->numberOfProcesses->text().toInt();
        w.show();

    }

}
