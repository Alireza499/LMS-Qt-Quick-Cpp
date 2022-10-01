QT += quick

QMAKE_CXXFLAGS += -std=c++11

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Azmoon.cpp \
        Daneshjoo.cpp \
        Dars.cpp \
        Handler.cpp \
        Karbar.cpp \
        Karname.cpp \
        Ostad.cpp \
        Soual.cpp \
        darslist.cpp \
        azmoonlist.cpp\
        azmoonmodel.cpp\
        darsmodel.cpp \
        daneshjoolist.cpp\
        daneshjoomodel.cpp\
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Azmoon.h \
    Daneshjoo.h \
    Karname.h \
    daneshjoolist.h \
    daneshjoomodel.h \
    azmoonlist.h \
    azmoonmodel.h \
    Dars.h \
    Handler.h \
    Karbar.h \
    Ostad.h \
    Soual.h \
    darslist.h \
    darsmodel.h
