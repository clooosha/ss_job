TEMPLATE = app
CONFIG += console
CONFIG -= qt
DESTDIR = ../bin
SOURCES += main.cpp \
    AnalyzeParameters.cpp \
    HtmlCreator.cpp \
    HtmlWriter.cpp

HEADERS += \
    AnalyzeParameters.h \
    HtmlCreator.h \
    HtmlWriter.h

