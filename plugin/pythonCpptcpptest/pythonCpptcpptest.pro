QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = lib
DEFINES += PYTHONCPPTCPPTEST_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = ../../build
QMAKE_CXXFLAGS += /arch:AVX
QMAKE_CXXFLAGS_DEBUG += /arch:AVX

INCLUDEPATH += ../../build/config
INCLUDEPATH += ../../include
INCLUDEPATH += ../../
INCLUDEPATH += ../../3rdlib

SOURCES += \
    form.cpp \
    pythonCpptcpptestActivator.cpp \
    sendermain.cpp



HEADERS += \
    form.h \
    pythonCpptcpptestActivator.h \
    sendermain.h

FORMS += \
    form.ui


