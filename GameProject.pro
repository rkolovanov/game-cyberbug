QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    classes/common/eventmanager.cpp \
    classes/common/exception.cpp \
    classes/common/point2d.cpp \
    classes/common/settings.cpp \
    classes/common/time.cpp \
    classes/game/cell.cpp \
    classes/game/commands/command.cpp \
    classes/game/commands/interactplayercommand.cpp \
    classes/game/commands/moveplayercommand.cpp \
    classes/game/commands/startlevelcommand.cpp \
    classes/game/field.cpp \
    classes/game/gamecontroller.cpp \
    classes/game/interaction/interactionnone.cpp \
    classes/game/interaction/interactionuse.cpp \
    classes/game/levelgenerator.cpp \
    classes/game/objects/armor/armor.cpp \
    classes/game/objects/armor/armorfactory.cpp \
    classes/game/objects/creatures/creature.cpp \
    classes/game/objects/creatures/player/player.cpp \
    classes/game/objects/levelpassobject/levelpassobject.cpp \
    classes/game/objects/levelpassobject/levelpassobjectfactory.cpp \
    classes/game/objects/medicines/medicines.cpp \
    classes/game/objects/medicines/medicinesfactory.cpp \
    classes/game/objects/object.cpp \
    classes/game/objects/weapon/weapon.cpp \
    classes/game/objects/weapon/weaponfactory.cpp \
    classes/gui/levelpainter.cpp \
    classes/gui/mainwindow.cpp \
    classes/gui/texturemanager.cpp \
    classes/logging/consolelogger.cpp \
    classes/logging/consoleloggerimplementation.cpp \
    classes/logging/filelogger.cpp \
    classes/logging/fileloggerimplementation.cpp \
    classes/logging/logger.cpp \
    classes/logging/logginglistener.cpp \
    main.cpp \

HEADERS += \
    classes/common/eventlistener.h \
    classes/common/eventmanager.h \
    classes/common/exception.h \
    classes/common/point2d.h \
    classes/common/settings.h \
    classes/common/time.h \
    classes/enumerations/celltype.h \
    classes/enumerations/commandtype.h \
    classes/enumerations/direction.h \
    classes/enumerations/roomtype.h \
    classes/enumerations/texture.h \
    classes/game/cell.h \
    classes/game/commands/command.h \
    classes/game/commands/interactplayercommand.h \
    classes/game/commands/moveplayercommand.h \
    classes/game/commands/startlevelcommand.h \
    classes/game/field.h \
    classes/game/gamecontroller.h \
    classes/game/interaction/interactionnone.h \
    classes/game/interaction/interactionstrategy.h \
    classes/game/interaction/interactionuse.h \
    classes/game/levelgenerator.h \
    classes/game/objects/armor/armor.h \
    classes/game/objects/armor/armorfactory.h \
    classes/game/objects/creatures/creature.h \
    classes/game/objects/creatures/player/player.h \
    classes/game/objects/levelpassobject/levelpassobject.h \
    classes/game/objects/levelpassobject/levelpassobjectfactory.h \
    classes/game/objects/medicines/medicines.h \
    classes/game/objects/medicines/medicinesfactory.h \
    classes/game/objects/object.h \
    classes/game/objects/objectfactory.h \
    classes/game/objects/weapon/weapon.h \
    classes/game/objects/weapon/weaponfactory.h \
    classes/gui/levelpainter.h \
    classes/gui/mainwindow.h \
    classes/gui/texturemanager.h \
    classes/logging/consolelogger.h \
    classes/logging/consoleloggerimplementation.h \
    classes/logging/filelogger.h \
    classes/logging/fileloggerimplementation.h \
    classes/logging/logger.h \
    classes/logging/loggerimplementation.h \
    classes/logging/logginglistener.h \

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
