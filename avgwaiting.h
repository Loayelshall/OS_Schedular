#ifndef AVGWAITING_H
#define AVGWAITING_H

#include <QDialog>


namespace Ui {
class avgWaiting;
}

class avgWaiting : public QDialog
{
    Q_OBJECT

public:
    explicit avgWaiting(QWidget *parent = nullptr);
    ~avgWaiting();


    void setLabel(QString temp){
        label = temp;
    }


private:
    Ui::avgWaiting *ui;
    QString label;
};

#endif // AVGWAITING_H
