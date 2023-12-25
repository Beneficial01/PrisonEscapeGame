QT       += core gui
QT       += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    HealthPackCpp/healthpackcontroller.cpp \
    HealthPackCpp/healthpackmodel.cpp \
    HealthPackCpp/healthpackviewgraphical.cpp \
    TileCpp/tilecontroller.cpp \
    TileCpp/tilemodel.cpp \
    TileCpp/tileviewgraphical.cpp \
    commandtrienode.cpp \
    easylevel.cpp \
    easylevelfactory.cpp \
    enemycontroller.cpp \
    enemymodel.cpp \
    enemyviewgraphical.cpp \
    enemyviewtext.cpp \
    gamecontroller.cpp \
    gameview.cpp \
    gameviewfactory.cpp \
    graphicalgameview.cpp \
    graphicgameviewfactory.cpp \
    hardlevel.cpp \
    hardlevelfactory.cpp \
    healthpackviewtext.cpp \
    levelfactory.cpp \
    main.cpp \
    mediumlevel.cpp \
    mediumlevelfactory.cpp \
    penemymodel.cpp \
    penemytimer.cpp \
    penemyviewgraphical.cpp \
    penemyviewtext.cpp \
    protagonistcontroller.cpp \
    protagonistmodel.cpp \
 #   protagonisttimer.cpp \
    protagonistviewgraphical.cpp \
    mainwindow.cpp \
    protagonistviewtext.cpp \
    textgameview.cpp \
    textgameviewfactory.cpp \
    tileviewtext.cpp



HEADERS += \
    HealthPackH/healthpackcontroller.h \
    HealthPackH/healthpackmodel.h \
    HealthPackH/healthpackview.h \
    HealthPackH/healthpackviewgraphical.h \
    TileH/tileviewgraphical.h \
    TileH/tilecontroller.h \
    TileH/tilemodel.h \
    TileH/tileview.h \
    TileH/tileviewgraphical.h \
    commandtrienode.h \
    easylevel.h \
    easylevelfactory.h \
    enemycontroller.h \
    enemymodelinterface.h \
    enemyview.h \
    enemyviewgraphical.h \
    enemyviewinterface.h \
    enemyviewtext.h \
    gamecontroller.h \
    gameview.h \
    gameviewfactory.h \
    graphicalgameview.h \
    graphicgameviewfactory.h \
    hardlevel.h \
    hardlevelfactory.h \
    healthpackviewtext.h \
    level.h \
    levelfactory.h \
    mainwindow.h \
    mediumlevel.h \
    mediumlevelfactory.h \
    penemymodel.h \
    penemytimer.h \
    penemyview.h \
    penemyviewgraphical.h \
    penemyviewtext.h \
    protagonistcontroller.h \
    protagonistmodel.h \
#    protagonisttimer.h \
    protagonistview.h \
    protagonistviewgraphical.h \
    constants.h \
    protagonistviewtext.h \
    textgameview.h \
    textgameviewfactory.h \
    tileviewtext.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    Maps.qrc \
    Protagonist.qrc \
    HealthPack.qrc \
    Enemies.qrc \
    tiles.qrc




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../CompiledLib/ -lworl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../CompiledLib/ -lworld

INCLUDEPATH += $$PWD/../CompiledLib/inc
DEPENDPATH += $$PWD/../CompiledLib/inc

unix:!macx: LIBS += -L$$PWD/../worldlib/ -lworld




INCLUDEPATH += $$PWD/../APT_fp_resources/worldsource
DEPENDPATH += $$PWD/../APT_fp_resources/worldsource


INCLUDEPATH += $$PWD/../worldlib
DEPENDPATH += $$PWD/../worldlib
