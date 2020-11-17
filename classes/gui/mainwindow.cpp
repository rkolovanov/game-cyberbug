#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMap>
#include <QKeyEvent>
#include <QMessageBox>
#include <QString>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "classes/game/field.h"
#include "classes/game/objects/medicines/medicines.h"
#include "classes/game/objects/armor/armor.h"
#include "classes/game/objects/weapon/weapon.h"
#include "classes/game/objects/levelpassobject/levelpassobject.h"
#include "classes/game/commands/moveplayercommand.h"
#include "classes/game/commands/interactplayercommand.h"
#include "classes/game/commands/startlevelcommand.h"

MainWindow::MainWindow(pGameController& controller, pLoggingListener& logger, QWidget* parent): QMainWindow(parent), ui_(new Ui::MainWindow), logger_(logger), controller_(controller) {
    ui_->setupUi(this);

    view_ = pQGraphicsView(new QGraphicsView(this));
    scene_ = pQGraphicsScene(new QGraphicsScene(this));
    levelLabel_ = pQLabel(new QLabel(this));
    healthLabel_ = pQLabel(new QLabel(this));
    attackLabel_ = pQLabel(new QLabel(this));
    armorLabel_ = pQLabel(new QLabel(this));

    commands_[CommandType::MovePlayerTop] = pCommand(new MovePlayerCommand(controller, Direction::Top));
    commands_[CommandType::MovePlayerBottom] = pCommand(new MovePlayerCommand(controller, Direction::Bottom));
    commands_[CommandType::MovePlayerLeft] = pCommand(new MovePlayerCommand(controller, Direction::Left));
    commands_[CommandType::MovePlayerRight] = pCommand(new MovePlayerCommand(controller, Direction::Right));
    commands_[CommandType::InteractPlayer] = pCommand(new InteractPlayerCommand(controller));
    commands_[CommandType::StartLevel] = pCommand(new StartLevelCommand(controller));

    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    view_->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    view_->setStyleSheet("background-color: black;");
    view_->setScene(scene_.get());

    levelLabel_->move(25, 25);
    healthLabel_->move(25, 45);
    attackLabel_->move(25, 65);
    armorLabel_->move(25, 85);
    levelLabel_->setStyleSheet("QLabel { font-weight: bold; font-size: 16px; color: white; }");
    healthLabel_->setStyleSheet("QLabel { font-weight: bold; font-size: 16px; color: white; }");
    attackLabel_->setStyleSheet("QLabel { font-weight: bold; font-size: 16px; color: white; }");
    armorLabel_->setStyleSheet("QLabel { font-weight: bold; font-size: 16px; color: white; }");

    if (!screenPinning_) {
        view_->setDragMode(QGraphicsView::ScrollHandDrag);
    }

    commands_[CommandType::StartLevel]->execute();

    updateScene();
    setCentralWidget(view_.get());
}

void MainWindow::updateScene() {
    pConstPlayer player = controller_->getPlayer();

    levelLabel_->setText("Floor: " + QString::number(controller_->getLevelNumber()));
    healthLabel_->setText("Health: " + QString::number(player->getHealth()));
    attackLabel_->setText("Attack: " + QString::number(player->getAttackDamage()));
    armorLabel_->setText("Armor: " + QString::number(player->getProtection()));

    controller_->getLevelPixmap(fieldPixelMap_);

    scene_->clear();
    scene_->addPixmap(*fieldPixelMap_);

    if (screenPinning_) {
        view_->centerOn(player->getPosition().x * 64 + 32, player->getPosition().y * 64 + 32);
    }
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
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
        } else if (event->key() == Qt::Key_Q) {
            QMessageBox::StandardButton button = QMessageBox::question(this, "Quit", "Are you sure you want to quit the game?");

            if (button == QMessageBox::StandardButton::Yes) {
                logger_->update("Quitting the game...\n");
                QApplication::exit();
            }

            isPressed_ = false;
        }

        if (command != CommandType::None) {
            commands_[command]->execute();
            updateScene();
        }

        if (controller_->isLevelComplete()) {
            logger_->update("Player has reached the end of the level.\n");
            QMessageBox::information(this, "Level complete", "Great job, level passed!");

            commands_[CommandType::StartLevel]->execute();
            updateScene();

            view_->centerOn(0, 0);
            isPressed_ = false;
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent* event) {
    if (!event->isAutoRepeat()) {
        isPressed_ = false;
    }
}
