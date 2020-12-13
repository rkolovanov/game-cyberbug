#include <QMap>
#include <QString>
#include <iostream>
#include <QKeyEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sources/game/field.h"
#include "sources/game/objects/medicines/medicines.h"
#include "sources/game/objects/armor/armor.h"
#include "sources/game/objects/weapon/weapon.h"
#include "sources/game/objects/levelpassobject/levelpassobject.h"
#include "sources/gui/commands/moveplayercommand.h"
#include "sources/gui/commands/interactplayercommand.h"
#include "sources/gui/commands/startlevelcommand.h"
#include "sources/gui/commands/attackplayercommand.h"
#include "sources/gui/commands/savegamecommand.h"
#include "sources/gui/commands/loadgamecommand.h"
#include "sources/gui/commands/newgamecommand.h"

namespace gui {


gui::MainWindow::MainWindow(const game::sharedGameController& controller, const logging::sharedLoggingListener& logger, QWidget* parent): QMainWindow(parent), ui_(new Ui::MainWindow), logger_(logger), controller_(controller) {
    ui_->setupUi(this);

    view_ = std::make_shared<QGraphicsView>(this);
    scene_ = std::make_shared<QGraphicsScene>(this);
    levelLabel_ = std::make_shared<QLabel>(this);
    healthLabel_ = std::make_shared<QLabel>(this);
    maxHealthLabel_ = std::make_shared<QLabel>(this);
    attackLabel_ = std::make_shared<QLabel>(this);
    armorLabel_ = std::make_shared<QLabel>(this);

    commands_[CommandType::MovePlayerTop] = std::make_shared<MovePlayerCommand>(controller, Direction::Top);
    commands_[CommandType::MovePlayerBottom] = std::make_shared<MovePlayerCommand>(controller, Direction::Bottom);
    commands_[CommandType::MovePlayerLeft] = std::make_shared<MovePlayerCommand>(controller, Direction::Left);
    commands_[CommandType::MovePlayerRight] = std::make_shared<MovePlayerCommand>(controller, Direction::Right);
    commands_[CommandType::InteractPlayer] = std::make_shared<InteractPlayerCommand>(controller);
    commands_[CommandType::AttackPlayer] = std::make_shared<AttackPlayerCommand>(controller);
    commands_[CommandType::StartLevel] = std::make_shared<StartLevelCommand>(controller);
    commands_[CommandType::SaveGame] = std::make_shared<SaveGameCommand>(controller);
    commands_[CommandType::LoadGame] = std::make_shared<LoadGameCommand>(controller);
    commands_[CommandType::NewGame] = std::make_shared<NewGameCommand>(controller);

    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    view_->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    view_->setStyleSheet("background-color: black;");
    view_->setScene(scene_.get());

    levelLabel_->move(10, 25);
    healthLabel_->move(10, 45);
    maxHealthLabel_->move(10, 65);
    attackLabel_->move(10, 85);
    armorLabel_->move(10, 105);

    levelLabel_->resize(200, 20);
    healthLabel_->resize(200, 20);
    maxHealthLabel_->resize(200, 20);
    attackLabel_->resize(200, 20);
    armorLabel_->resize(200, 20);

    levelLabel_->setStyleSheet("QLabel { font-weight: bold; font-size: 14px; color: white; }");
    healthLabel_->setStyleSheet("QLabel { font-weight: bold; font-size: 14px; color: white; }");
    maxHealthLabel_->setStyleSheet("QLabel { font-weight: bold; font-size: 14px; color: white; }");
    attackLabel_->setStyleSheet("QLabel { font-weight: bold; font-size: 14px; color: white; }");
    armorLabel_->setStyleSheet("QLabel { font-weight: bold; font-size: 14px; color: white; }");

    if (!screenPinning_) {
        view_->setDragMode(QGraphicsView::ScrollHandDrag);
    }

    commands_[CommandType::NewGame]->execute();
    updateScene();

    setCentralWidget(view_.get());
}


void gui::MainWindow::updateScene(bool move_view) {
    game::sharedConstPlayer player = controller_->getPlayer();

    levelLabel_->setText("Floor: " + QString::number(controller_->getLevelNumber()));
    healthLabel_->setText("Health: " + QString::number(player->getHealth()));
    maxHealthLabel_->setText("Max Health: " + QString::number(player->getMaxHealth()));
    attackLabel_->setText("Attack: " + QString::number(player->getAttackDamage()));
    armorLabel_->setText("Armor: " + QString::number(player->getProtection()));

    controller_->getLevelPixmap(fieldPixelMap_);

    scene_->clear();
    scene_->addPixmap(*fieldPixelMap_);
    view_->setSceneRect(fieldPixelMap_->rect());

    if (screenPinning_ || move_view) {
        view_->centerOn(player->getPosition().x * 64 + 32, player->getPosition().y * 64 + 32);
    }
}


void gui::MainWindow::keyPressEvent(QKeyEvent* event) {
    if (!isPressed_) {
        CommandType command = CommandType::None;
        isPressed_ = true;

        if (event->key() == Qt::Key_W) {
            command = CommandType::MovePlayerTop;
        } else if (event->key() == Qt::Key_S) {
            command = CommandType::MovePlayerBottom;
        } else if (event->key() == Qt::Key_A) {
            command = CommandType::MovePlayerLeft;
        } else if (event->key() == Qt::Key_D) {
            command = CommandType::MovePlayerRight;
        } else if (event->key() == Qt::Key_E) {
            command = CommandType::InteractPlayer;
        } else if (event->key() == Qt::Key_F) {
            command = CommandType::AttackPlayer;
        }

        if (command != CommandType::None) {
            commands_[command]->execute();
            updateScene();
        }

        if (controller_->isPlayerDead()) {
            logger_->update("Player has died. Game over.");
            QMessageBox::information(this, "Game over", "You died!");
        } else if (controller_->isLevelComplete()) {
            logger_->update("Player has reached the end of the level.");
            QMessageBox::information(this, "Level complete", "Great job, level passed!");
            commands_[CommandType::StartLevel]->execute();
            updateScene();

            view_->centerOn(0, 0);
            isPressed_ = false;
        }
    }
}


void gui::MainWindow::keyReleaseEvent(QKeyEvent* event) {
    if (!event->isAutoRepeat()) {
        isPressed_ = false;
    }
}


void gui::MainWindow::quit() {
    logger_->update("Quitting the game...");
    QApplication::exit();
}


void gui::MainWindow::on_action_new_triggered() {
    logger_->update("Strating the game...");
    commands_[CommandType::NewGame]->execute();
    updateScene();
}


void gui::MainWindow::on_action_save_triggered() {
    QString filepath = QFileDialog::getSaveFileName(this, "Choose file to save");
    SaveGameCommand& command = dynamic_cast<SaveGameCommand&>(*commands_[CommandType::SaveGame]);
    command.setPath(filepath.toStdString());
    command.execute();
}


void gui::MainWindow::on_action_load_triggered() {
    QString filepath = QFileDialog::getOpenFileName(this, "Choose file to load");
    LoadGameCommand& command = dynamic_cast<LoadGameCommand&>(*commands_[CommandType::LoadGame]);
    command.setPath(filepath.toStdString());
    command.execute();
    updateScene(true);
}


void gui::MainWindow::on_action_exit_triggered() {
    QMessageBox::StandardButton button = QMessageBox::question(this, "Quit", "Are you sure you want to quit the game?");

    if (button == QMessageBox::StandardButton::Yes) {
        quit();
    }
}


};
