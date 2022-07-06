#-------------------------------------------------
#
# Project created by QtCreator 2014-01-06T22:51:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Paint
TEMPLATE = app


SOURCES += main.cpp\
    circle.cpp \
    instruction.cpp \
        mainwindow.cpp \
    scribblearea.cpp \
    shape.cpp \
    ellipse.cpp \
    rectangle.cpp \
    scribble.cpp \
    command.cpp \
    square.cpp \
    triangle.cpp

HEADERS  += mainwindow.h \
    circle.h \
    ellipse.h \
    instruction.h \
    rectangle.h \
    scribble.h \
    scribblearea.h \
    shape.h \
    command.h \
    square.h \
    triangle.h

OTHER_FILES += \
    README.md \
    UNLICENSE.txt \
    LICENSE.GPL
