QT += testlib
QT += gui
QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_testenemymodel.cpp \
            ../../src/enemy/EnemyModel.cpp

INCLUDEPATH += $$PWD/../../include \
               $$PWD/../../include/CompiledWorld \
               $$PWD/../../include/enemy \
               $$PWD/../../include/game \
               $$PWD/../../include/gameview \
               $$PWD/../../include/healthpack \
               $$PWD/../../include/level \
               $$PWD/../../include/mainwindow \
               $$PWD/../../include/protagonist \
               $$PWD/../../include/tile \
               $$PWD/../../include/trie \


INCLUDEPATH += $$PWD/../../../worldlib
DEPENDPATH += $$PWD/../../../worldlib


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../CompiledLib/ -lworl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../CompiledLib/ -lworld

INCLUDEPATH += $$PWD/../../../CompiledLib/inc
DEPENDPATH += $$PWD/../../../CompiledLib/inc
