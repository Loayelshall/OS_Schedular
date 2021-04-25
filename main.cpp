#include "mainwindow.h"

#include <QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>

QT_CHARTS_USE_NAMESPACE
#include <QtCharts/QHorizontalStackedBarSeries>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    w.show();


//            QBarSet *set0 = new QBarSet("Altuve");
//            QBarSet *set1 = new QBarSet("Martinez");
//            QBarSet *set2 = new QBarSet("Segura");
//            QBarSet *set3 = new QBarSet("Simmons");
//            QBarSet *set4 = new QBarSet("Trout");


//            *set0 << 283 ;
//            *set1 << 250 ;
//            *set2 << 294 ;
//            *set3 << 248 ;
//            *set4 << 323 ;


//             QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
//            series->append(set0);
//            series->append(set1);
//            series->append(set2);
//            series->append(set3);
//            series->append(set4);

//            QChart *chart = new QChart();


//            chart->addSeries(series);



//            chart->setAnimationOptions(QChart::AllAnimations);

//            QStringList categories;
//            categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";




//            chart->legend()->setVisible(true);
//            chart->legend()->setAlignment(Qt::AlignBottom);

//            QChartView *chartView = new QChartView(chart);
//            chartView->setRenderHint(QPainter::Antialiasing);

//            QPalette pal = qApp->palette();

//            pal.setColor(QPalette::Window, QRgb(0xffffff));
//            pal.setColor(QPalette::WindowText, QRgb(0x404044));

//            qApp->setPalette(pal);



//            chart->addSeries(series);
//            chart->setTitle("Processes");
//            chart->legend()->hide();

//            chartView->setRenderHint(QPainter::Antialiasing);




//            w.setCentralWidget(chartView);
            w.show();
    return a.exec();
}
