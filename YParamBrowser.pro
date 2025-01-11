QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 utf8_source

include (qtpropertybrowser/qtpropertybrowser.pri)
include (YParamBrowser/YParamBrowser.pri)
SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui
