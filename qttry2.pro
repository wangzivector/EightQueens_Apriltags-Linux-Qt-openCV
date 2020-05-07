#-------------------------------------------------
#
# Project created by QtCreator 2019-10-05T00:36:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qttry2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chessforview.cpp \
    showlabel.cpp \
    game.cpp \
    bahuanghou.cpp

HEADERS  += mainwindow.h \
    chessforview.h \
    showlabel.h \
    game.h \
    bahuanghou.h

FORMS    += mainwindow.ui

RESOURCES += \
    img.qrc

OTHER_FILES += \
    img/base.png \
    img/chess.png \
    img/sample.png \
    img/tagchess.png
