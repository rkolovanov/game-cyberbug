#include <QApplication>
#include <iostream>
#include "classes/gui/mainwindow.h"
#include "classes/gui/texturemanager.h"
#include "classes/common/settings.h"
#include "classes/common/time.h"
#include "classes/game/gamecontroller.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Settings settings("./settings.txt");

    if (settings.isInvalid()) {
        std::cerr << "Cannot open settings file: ./settings.txt\n";
        std::cerr << "Using default settings.\n";
        settings.setDefault();
    }

    pLoggingListener logger(new LoggingListener);
    pLogger fileLogger(new FileLogger(settings["logs_path"] + Time().getCurrentDateTime() + ".log"));
    pLogger consoleLogger(new ConsoleLogger(std::cout));

    logger->addLogger(fileLogger);
    logger->addLogger(consoleLogger);

    TextureManager::initTextures();

    pGameController controller(new GameController(logger));
    MainWindow window(controller, logger);

    window.show();

    return app.exec();
}
