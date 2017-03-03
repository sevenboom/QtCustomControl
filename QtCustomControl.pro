#-------------------------------------------------
#
# Project created by QtCreator 2017-02-21T14:10:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtCustomControl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    MessageBox.cpp \
    indicator.cpp \
	ComboBox/combobox.cpp \
    ComboBox/popuplistview.cpp

HEADERS  += mainwindow.h \
    MessageBox.h \
    indicator.h \
	ComboBox/combobox.h \
    ComboBox/popuplistview.h

DEFINES += $$PWD\
		+= $$PWD/ComboBox

RESOURCES += \
    controlsource.qrc
