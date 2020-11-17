#include <QMap>
#include "classes/game/gamecontroller.h"
#include "classes/game/levelgenerator.h"
#include "classes/gui/levelpainter.h"

GameController::GameController(pLoggingListener& logger): logger_(logger) {
    pEventListener listener(logger);

    player_ = pPlayer(new Player(Position2D(0, 0)));
    player_->setMaxHealth(100);
    player_->setHealth(73);
    player_->setAttackDamage(3);
    player_->setProtection(0);
    player_->getEventManager().subscribe(listener);
}

void GameController::createLevel() {
    LevelGenerator levelGenerator(logger_);
    levelGenerator.generate(Size2D(2 + level_, 2 + level_), level_);
    levelComplete_ = false;
    player_->setPosition(levelGenerator.getEntryPosition());
    player_->setPassFounded(false);
}

bool GameController::isPlayerReachedExit() const {
    const Field& field = Field::getInstance();
    return field.getCell(player_->getPosition()).getType() == CellType::Exit;
}

void GameController::movePlayer(Direction direction) {
    Field& field = Field::getInstance();
    Position2D newPosition = Position2D(player_->getPosition().x, player_->getPosition().y);

    newPosition.shift(direction);
    player_->setRotation(direction);

    if (field.getCell(newPosition).isPassable()) {
        player_->setPosition(newPosition);
    }

    if (isPlayerReachedExit() && player_->getPassFounded()) {
        levelComplete_ = true;
        level_++;
    }
}

void GameController::executePlayerInteraction() {
    Field& field = Field::getInstance();
    Position2D interactionPosition = player_->getPosition().shift(player_->getRotation());;
    *player_ <= field.getCell(interactionPosition).getObject();
}

bool GameController::isLevelComplete() const {
    return levelComplete_;
}

void GameController::getLevelPixmap(pQPixmap& levelPixmap) const {
    LevelPainter::paint(levelPixmap, player_);
}

pConstPlayer GameController::getPlayer() {
    return player_;
}

size_t GameController::getLevelNumber() {
    return level_;
}

GameController::~GameController() {
    logger_->update("Quitting the game...\n");
}
