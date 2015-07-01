TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += $(GTEST_ROOT) \
    $(GTEST_ROOT)/include
LIBS += -pthread
SOURCES += main.cpp \
    $(GTEST_ROOT)/src/gtest-all.cc \
    test_AnalyzeParameters.cpp \
    test_HtmlCreator.cpp \
    ../src/AnalyzeParameters.cpp \
    ../src/HtmlCreator.cpp \
    ../src/HtmlWriter.cpp \

