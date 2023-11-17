QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    easylevel.cpp \
    easylevelfactory.cpp \
    gamecontroller.cpp \
    levelfactory.cpp \
    main.cpp \
    mainwindow.cpp \
    tilecontroller.cpp \
    tilemodel.cpp \
    tileviewgraphical.cpp

HEADERS += \
    easylevel.h \
    easylevelfactory.h \
    gamecontroller.h \
    level.h \
    levelfactory.h \
    mainwindow.h \
    tilecontroller.h \
    tilemodel.h \
    tileview.h \
    tileviewgraphical.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    Maps.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/CompiledWorld/ -lworl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/CompiledWorld/ -lworld
else:unix: LIBS += -L$$PWD/CompiledWorld/ -lworl

INCLUDEPATH += $$PWD/CompiledWorld
DEPENDPATH += $$PWD/CompiledWorld
