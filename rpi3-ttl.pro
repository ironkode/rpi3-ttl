TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ttl.cpp \
    errorrep.cpp

HEADERS += \
    ttl.h \
    errorrep.h

DISTFILES += \
    README.md
