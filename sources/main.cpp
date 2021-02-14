#include <QApplication>
#include <iostream>

#include "sources/gui/mainwindow.h"
#include "sources/gui/texturemanager.h"
#include "sources/game/settings.h"
#include "sources/application/time.h"
#include "sources/game/gamecontroller.h"


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    game::Settings settings("./settings.txt");

    if (settings.isInvalid()) {
        std::cerr << "Cannot open settings file: ./settings.txt\n";
        std::cout << "Using default settings.\n";

        settings["console_logger"] = "true";
        settings["file_logger"] = "true";
        settings["logs_path"] = "./";
    }

    logging::sharedLoggingListener logger(new logging::LoggingListener);
    logger->addLogger(std::make_shared<logging::ConsoleLogger>(std::cout));

    std::string logging_file_path = settings["logs_path"] + application::Time().getCurrentDateTime() + ".log";
    logging::sharedFileLogger file_logger = std::make_shared<logging::FileLogger>(logging_file_path);

    if (file_logger->isInvalid()) {
        std::cerr << "Cannot open logging file: " + logging_file_path << "\n";
    } else {
        logger->addLogger(file_logger);
    }

    gui::TextureManager::initTextures();

    game::sharedGameController controller = std::make_shared<game::GameController>(logger);
    gui::MainWindow window(controller, logger);

    window.show();

    return app.exec();
}
