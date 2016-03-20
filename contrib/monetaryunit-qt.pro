#-------------------------------------------------
#
# Project created by QtCreator 2016-03-19T01:16:11
#
#-------------------------------------------------

QT       += core gui network webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport webkitwidgets

TARGET = MonetaryUnit
TEMPLATE = app


SOURCES += ../src/*.cpp \
        ../src/qt/*.cpp \
        ../src/script/*.cpp \
        ../src/json/*.cpp \

HEADERS  += ../src/*.h \
         ../src/qt/*.h

FORMS += ../src/qt/forms/*.ui

RESOURCES += \
    ../src/qt/bitcoin.qrc
