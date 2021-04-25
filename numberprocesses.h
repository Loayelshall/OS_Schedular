#ifndef NUMBERPROCESSES_H
#define NUMBERPROCESSES_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class numberProcesses;
}

class numberProcesses : public QDialog
{
    Q_OBJECT

public:
    explicit numberProcesses(QWidget *parent = nullptr);
    ~numberProcesses();

private slots:
    void on_noProAction_clicked();


private:
    Ui::numberProcesses *ui;
    MainWindow w;
};

#endif // NUMBERPROCESSES_H
