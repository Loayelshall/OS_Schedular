#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "avgwaiting.h"
#include "types.h"
#include "view.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QQVector<process> processes;
    int numberProccess;



private slots:
    void on_pushButton_clicked();

    void on_schedularType_currentIndexChanged(const QString &arg1);

    void on_simulateButton_clicked();




    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    avgWaiting w;
    View chartUI;
};
#endif // MAINWINDOW_H
