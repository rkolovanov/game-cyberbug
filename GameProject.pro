QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    sources/commands/attackplayercommand.cpp \
    sources/commands/loadgamecommand.cpp \
    sources/commands/savegamecommand.cpp \
    sources/common/eventmanager.cpp \
    sources/common/exception.cpp \
    sources/common/point2d.cpp \
    sources/common/settings.cpp \
    sources/common/time.cpp \
    sources/game/cell.cpp \
    sources/commands/command.cpp \
    sources/commands/interactplayercommand.cpp \
    sources/commands/moveplayercommand.cpp \
    sources/commands/startlevelcommand.cpp \
    sources/game/enemiesturnstate.cpp \
    sources/game/field.cpp \
    sources/game/fieldmemento.cpp \
    sources/game/gamecontroller.cpp \
    sources/game/gameloader.cpp \
    sources/game/gamesaver.cpp \
    sources/game/interactions/interactionnone.cpp \
    sources/game/interactions/interactionuse.cpp \
    sources/game/levelgenerator.cpp \
    sources/game/objects/armor/armor.cpp \
    sources/game/objects/armor/armorfactory.cpp \
    sources/game/objects/creatures/creature.cpp \
    sources/game/objects/creatures/distanceattackbehavior.cpp \
    sources/game/objects/creatures/enemies/enemymemento.cpp \
    sources/game/objects/creatures/meleeattackbehavior.cpp \
    sources/game/objects/creatures/player/player.cpp \
    sources/game/objects/creatures/player/playermemento.cpp \
    sources/game/objects/creatures/standmovementbehavior.cpp \
    sources/game/objects/creatures/walkmovementbehavior.cpp \
    sources/game/objects/levelpassobject/levelpassobject.cpp \
    sources/game/objects/levelpassobject/levelpassobjectfactory.cpp \
    sources/game/objects/medicines/medicines.cpp \
    sources/game/objects/medicines/medicinesfactory.cpp \
    sources/game/objects/object.cpp \
    sources/game/objects/weapon/weapon.cpp \
    sources/game/objects/weapon/weaponfactory.cpp \
    sources/game/playerturnstate.cpp \
    sources/gui/levelpainter.cpp \
    sources/gui/mainwindow.cpp \
    sources/gui/texturemanager.cpp \
    sources/logging/consolelogger.cpp \
    sources/logging/consoleloggerimplementation.cpp \
    sources/logging/filelogger.cpp \
    sources/logging/fileloggerimplementation.cpp \
    sources/logging/logger.cpp \
    sources/logging/logginglistener.cpp \
    sources/main.cpp \

HEADERS += \
    sources/commands/attackplayercommand.h \
    sources/commands/loadgamecommand.h \
    sources/commands/savegamecommand.h \
    sources/common/eventlistener.h \
    sources/common/eventmanager.h \
    sources/common/exception.h \
    sources/common/imemento.h \
    sources/common/point2d.h \
    sources/common/settings.h \
    sources/common/time.h \
    sources/game/celltype.h \
    sources/commands/commandtype.h \
    sources/common/direction.h \
    sources/game/enemiesturnstate.h \
    sources/game/fieldmemento.h \
    sources/game/gameloader.h \
    sources/game/gamesaver.h \
    sources/game/gamestate.h \
    sources/game/interactions/interactiontype.h \
    sources/game/objects/creatures/attackbehavior.h \
    sources/game/objects/creatures/distanceattackbehavior.h \
    sources/game/objects/creatures/enemies/abstractenemy.h \
    sources/game/objects/creatures/enemies/enemymemento.h \
    sources/game/objects/creatures/meleeattackbehavior.h \
    sources/game/objects/creatures/movementbehavior.h \
    sources/game/objects/creatures/player/playermemento.h \
    sources/game/objects/creatures/standmovementbehavior.h \
    sources/game/objects/creatures/walkmovementbehavior.h \
    sources/game/playerturnstate.h \
    sources/game/roomtype.h \
    sources/gui/texture.h \
    sources/game/cell.h \
    sources/commands/command.h \
    sources/commands/interactplayercommand.h \
    sources/commands/moveplayercommand.h \
    sources/commands/startlevelcommand.h \
    sources/game/field.h \
    sources/game/gamecontroller.h \
    sources/game/interactions/interactionnone.h \
    sources/game/interactions/interactionstrategy.h \
    sources/game/interactions/interactionuse.h \
    sources/game/levelgenerator.h \
    sources/game/objects/armor/armor.h \
    sources/game/objects/armor/armorfactory.h \
    sources/game/objects/creatures/creature.h \
    sources/game/objects/creatures/enemies/enemy.h \
    sources/game/objects/creatures/player/player.h \
    sources/game/objects/levelpassobject/levelpassobject.h \
    sources/game/objects/levelpassobject/levelpassobjectfactory.h \
    sources/game/objects/medicines/medicines.h \
    sources/game/objects/medicines/medicinesfactory.h \
    sources/game/objects/object.h \
    sources/game/objects/objectfactory.h \
    sources/game/objects/weapon/weapon.h \
    sources/game/objects/weapon/weaponfactory.h \
    sources/gui/levelpainter.h \
    sources/gui/mainwindow.h \
    sources/gui/texturemanager.h \
    sources/logging/consolelogger.h \
    sources/logging/consoleloggerimplementation.h \
    sources/logging/filelogger.h \
    sources/logging/fileloggerimplementation.h \
    sources/logging/logger.h \
    sources/logging/loggerimplementation.h \
    sources/logging/logginglistener.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

first.depends = $(first)

QMAKE_EXTRA_TARGETS += first

RESOURCES += \
    textures.qrc

DISTFILES +=
