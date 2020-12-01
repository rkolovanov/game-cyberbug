#include "sources/game/playerturnstate.h"
#include "sources/game/enemiesturnstate.h"


void PlayerTurnState::startTurn(GameController&) {}


void PlayerTurnState::endTurn(GameController& controller) {
    controller.checkLevelFinish();
    controller.changeState(std::make_shared<EnemiesTurnState>());
    controller.startTurn();
}


void PlayerTurnState::movePlayer(GameController& controller, Direction direction) {
    sharedPlayer player = controller.getPlayer();
    Position2D new_position = player->getPosition();

    new_position.shift(direction);
    player->setRotation(direction);

    if (controller.isPassablePosition(new_position)) {
        player->setPosition(new_position);
    }

    controller.endTurn();
}


void PlayerTurnState::executePlayerInteraction(GameController& controller) {
    Field& field = Field::getInstance();
    sharedPlayer player = controller.getPlayer();
    Position2D interaction_position = player->getPosition().shift(player->getRotation());
    *player <= field.getCell(interaction_position).getObject();

    controller.endTurn();
}

void PlayerTurnState::executePlayerAttack(GameController& controller) {
    sharedPlayer player = controller.getPlayer();
    Position2D interaction_position = player->getPosition().shift(player->getRotation());
    sharedCreature attack_enemy = nullptr;
    size_t enemy_index = 0;

    for (auto& enemy : controller.getEnemies()) {
        if (enemy->getPosition() == interaction_position) {
            attack_enemy = enemy;
            break;
        }
        enemy_index++;
    }

    *player <= attack_enemy;

    if (attack_enemy != nullptr && attack_enemy->getHealth() <= 0) {
        player->setMaxHealth(player->getMaxHealth() + 5);
        controller.getEnemies().erase(controller.getEnemies().begin() + enemy_index);
    }

    controller.endTurn();
}
