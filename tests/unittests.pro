TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += $(GTEST_DIR) \
    $(GTEST_DIR)/include
LIBS += -pthread
SOURCES += main.cpp \
    $(GTEST_DIR)/src/gtest-all.cc \
    test_AnalyzeParameters.cpp \
    test_HtmlCreator.cpp \
    ../src/AnalyzeParameters.cpp \
    ../src/HtmlCreator.cpp \
    ../src/HtmlWriter.cpp \

