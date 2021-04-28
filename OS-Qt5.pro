QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    avgwaiting.cpp \
    main.cpp \
    mainwindow.cpp \
    numberprocesses.cpp \
    SJF.cpp \
    callout.cpp \
    view.cpp \
    PRI.cpp \
    FCFS.cpp \
    RR.cpp \
    avg_time.cpp


HEADERS += \
    avgwaiting.h \
    mainwindow.h \
    numberprocesses.h \
    SJF.h \
    types.h \
    callout.h \
    view.h \
    PRI.h \
    FCFS.h \
    RR.h \
    avg_time.h


FORMS += \
    avgwaiting.ui \
    mainwindow.ui \
    numberprocesses.ui \
    view.ui
QT += charts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
