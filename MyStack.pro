TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CMyStack.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    CMyStack.h

