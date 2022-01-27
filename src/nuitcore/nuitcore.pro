CONFIG -= qt

TEMPLATE = lib
CONFIG += staticlib

include(../../config.pri)

HEADERS += \
    board.h \
    color.hpp \
    game.h \
    place.hpp \
    player.hpp\
    gameState.hpp \
    tools/observer.h\
    tools/observable.h

SOURCES += \
    board.cpp \
    game.cpp

DISTFILES += \
        nuitcore.pri
