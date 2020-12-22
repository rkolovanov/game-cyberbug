#include <QMap>

#include "sources/common/exception.h"
#include "sources/game/gamecontroller.h"
#include "sources/game/levelgenerator.h"
#include "sources/game/creatures/enemies/enemy.h"
#include "sources/gui/levelpainter.h"
#include "sources/game/playerturnstate.h"
#include "sources/game/gamesaver.h"
#include "sources/game/gameloader.h"

namespace game {


game::GameController::GameController(const logging::sharedLoggingListener& logger): logger_(logger) {}


void game::GameController::newGame() {
    changeState(std::make_shared<PlayerTurnState>());
    player_ = std::make_shared<Player>(Position2D(0, 0));
    player_->setMaxHealth(100);
    player_->setHealth(100);
    player_->setAttackDamage(2);
    player_->setProtection(0);
    player_->getEventManager().subscribe(logger_);
    player_dead_ = false;
    level_ = 0;
    createLevel();
}


void game::GameController::createLevel() {
    LevelGenerator levelGenerator(logger_);
    levelGenerator.generate(Size2D(2 + level_, 2 + level_), level_);
    enemies_.clear();
    levelGenerator.spawnEnemies(enemies_, level_);
    level_complete_ = false;
    player_->setPosition(levelGenerator.getEntryPosition());
    player_->setPassFounded(false);
}


void game::GameController::changeState(const sharedGameState& state) {
    state_ = state;
}


void game::GameController::startTurn() {
    if (state_ != nullptr && !isPlayerDead()) {
        state_->startTurn(*this);
    }
}


void game::GameController::endTurn() {
    if (state_ != nullptr && !isPlayerDead()) {
        state_->endTurn(*this);
    }
}


void game::GameController::movePlayer(Direction direction) {
    if (state_ != nullptr && !isPlayerDead()) {
        state_->movePlayer(*this, direction);
    }
}


void game::GameController::executePlayerInteraction() {
    if (state_ != nullptr && !isPlayerDead()) {
        state_->executePlayerInteraction(*this);
    }
}


void game::GameController::executePlayerAttack() {
    if (state_ != nullptr && !isPlayerDead()) {
        state_->executePlayerAttack(*this);
    }
}


void game::GameController::checkLevelFinish() {
    if (isPlayerReachedExit() && player_->getPassFounded() && !level_complete_) {
        level_complete_ = true;
        level_++;
    }
}


bool game::GameController::isLevelComplete() {
    return level_complete_;
}


bool game::GameController::isPlayerReachedExit() const {
    const Field& field = Field::getInstance();
    return field.getCell(player_->getPosition()).getType() == CellType::Exit;
}


bool game::GameController::isPassablePosition(const Position2D& position) const {
    const Field& field = Field::getInstance();
    if (field.getCell(position).isPassable()) {
        for (auto& enemy : enemies_) {
            if (enemy->getPosition() == position) {
                return false;
            }
        }
        return position != player_->getPosition();
    }
    return false;
}


void game::GameController::getLevelPixmap(sharedQPixmap& levelPixmap) const {
    gui::LevelPainter::paint(levelPixmap, player_, enemies_);
}


game::sharedPlayer game::GameController::getPlayer() {
    return player_;
}


game::Enemies& game::GameController::getEnemies() {
    return enemies_;
}


bool game::GameController::isPlayerDead() const {
    return player_dead_;
}


void game::GameController::setPlayerDead(bool value) {
    player_dead_ = value;
}


size_t game::GameController::getLevelNumber() const {
    return level_;
}


game::GameController::~GameController() {
    logger_->update("Quitting the game...");
}


void game::GameController::saveGame(const std::string& path) {
    GameSaver saver(path, logger_);
    try {
        saver.save(player_, enemies_, level_);
    } catch (Exception& error) {
        logger_->update(error.getMessage());
    } catch (...) {
        logger_->update("Unknown error!");
    }
}


void game::GameController::loadGame(const std::string& path) {
    GameLoader loader(path, logger_);
    try {
        loader.load(player_, enemies_, level_);
        player_dead_ = player_->getHealth() <= 0;
    } catch (Exception& error) {
        logger_->update(error.getMessage());
    } catch (...) {
        logger_->update("Unknown error!");
    }
}


};
