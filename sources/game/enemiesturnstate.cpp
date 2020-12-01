#include "sources/game/enemiesturnstate.h"
#include "sources/game/playerturnstate.h"


void EnemiesTurnState::startTurn(GameController& controller) {
    sharedCreature player = controller.getPlayer();

    for (auto& enemy : controller.getEnemies()) {
        Position2D player_position = player->getPosition();
        Position2D enemy_position = enemy->getPosition();

        long long delta_x = static_cast<long long>(player_position.x) - static_cast<long long>(enemy_position.x);
        long long delta_y = static_cast<long long>(player_position.y) - static_cast<long long>(enemy_position.y);

        if (abs(delta_x) < 7 && abs(delta_y) < 7) {
            Position2D new_position = enemy->getMovementPosition(player_position);

            if (enemy_position != new_position && controller.isPassablePosition(new_position)) {
                enemy->setPosition(new_position);
            }

            enemy->tryAttack(player);
        }
    }

    controller.endTurn();
}


void EnemiesTurnState::endTurn(GameController& controller) {
    controller.changeState(std::make_shared<PlayerTurnState>());
    controller.startTurn();
}


void EnemiesTurnState::movePlayer(GameController&, Direction) {}


void EnemiesTurnState::executePlayerInteraction(GameController&) {}


void EnemiesTurnState::executePlayerAttack(GameController&) {}
