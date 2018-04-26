TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ModelBase.cpp \
    PrintModel.cpp \
    ControllerBase.cpp \
    PrintController.cpp \
    ViewBase.cpp \
    PrintView.cpp \
    ThreadBase.cpp

HEADERS += \
    ModelBase.h \
    PrintModel.h \
    Observer.h \
    ControllerBase.h \
    PrintController.h \
    ViewBase.h \
    PrintView.h \
    ThreadBase.h


QMAKE_CXXFLAGS += -std=c++11
LIBS += -pthread
