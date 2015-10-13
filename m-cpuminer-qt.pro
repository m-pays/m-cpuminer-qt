TEMPLATE = app
TARGET = m-cpuminer-qt
VERSION = 0.1
CONFIG += static
QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets
}

win32:QMAKE_LFLAGS *= -static

SOURCES += main.cpp\
        mainwindow.cpp \
    poolparse.cpp \
    json.cpp

HEADERS  += mainwindow.h \
    poolparse.h \
    json.h

FORMS    += mainwindow.ui

RESOURCES += \
    icon.qrc


