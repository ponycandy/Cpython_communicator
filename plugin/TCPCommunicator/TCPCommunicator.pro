QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = lib
DEFINES += TCPCOMMUNICATOR_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = ../../build

INCLUDEPATH += ../../build/config
INCLUDEPATH += ../../include
INCLUDEPATH += ../../

SOURCES += \
    TCPCommunicatorActivator.cpp \
    tcpclient.cpp \
    tcpmanager.cpp



HEADERS += \
    TCPCommunicatorActivator.h \
    tcpclient.h \
    tcpmanager.h


