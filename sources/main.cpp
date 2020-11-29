#include <QApplication>
#include <iostream>

#include "sources/gui/mainwindow.h"
#include "sources/gui/texturemanager.h"
#include "sources/common/settings.h"
#include "sources/common/time.h"
#include "sources/game/gamecontroller.h"


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Settings settings("./settings.txt");

    if (settings.isInvalid()) {
        std::cerr << "Cannot open settings file: ./settings.txt\n";
        std::cerr << "Using default settings.\n";

        settings["console_logger"] = "true";
        settings["file_logger"] = "true";
        settings["logs_path"] = "./";
    }

    sharedLoggingListener logger(new LoggingListener);
    logger->addLogger(std::make_shared<ConsoleLogger>(std::cout));

    std::string logging_file_path = settings["logs_path"] + Time().getCurrentDateTime() + ".log";
    sharedFileLogger file_logger = std::make_shared<FileLogger>(logging_file_path);

    if (file_logger->isInvalid()) {
        std::cerr << "Cannot open logging file: " + logging_file_path << "\n";
    } else {
        logger->addLogger(file_logger);
    }

    gui::TextureManager::initTextures();

    sharedGameController controller = std::make_shared<GameController>(logger);
    gui::MainWindow window(controller, logger);

    window.show();

    return app.exec();
}
