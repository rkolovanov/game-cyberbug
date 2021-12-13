#include "sources/game/enemiesturnstate.h"
#include "sources/game/playerturnstate.h"

namespace game {


void game::EnemiesTurnState::startTurn(GameController& controller) {
    sharedCreature player = controller.getPlayer();

    for (auto& enemy : controller.getEnemies()) {
        Position2D player_position = player->getPosition();
        Position2D enemy_position = enemy->getPosition();

        long long delta_x = static_cast<long long>(player_position.x) - static_cast<long long>(enemy_position.x);
        long long delta_y = static_cast<long long>(player_position.y) - static_cast<long long>(enemy_position.y);

        if (abs(delta_x) < 7 && abs(delta_y) < 7) {
            Position2D new_position = enemy->getMovementPosition(player_position);

            if (enemy_position != new_position && controller.isPassablePosition(new_position)) {
                int dx = new_position.x - enemy_position.x;
                int dy = new_position.y - enemy_position.y;

                if (dx > 0) {
                    enemy->setRotation(Rotation::Right);
                } else if (dy < 0) {
                    enemy->setRotation(Rotation::Top);
                } else if (dy > 0) {
                    enemy->setRotation(Rotation::Bottom);
                } else if (dx < 0) {
                    enemy->setRotation(Rotation::Left);
                }

                enemy->setPosition(new_position);
            }

            enemy->tryAttack(player);
        }
    }

    controller.endTurn();
}


void game::EnemiesTurnState::endTurn(GameController& controller) {
    if (controller.getPlayer()->getHealth() <= 0) {
        controller.setPlayerDead(true);
    }
    controller.changeState(std::make_shared<PlayerTurnState>());
}


void game::EnemiesTurnState::movePlayer(GameController&, Direction) {}


void game::EnemiesTurnState::executePlayerInteraction(GameController&) {}


void game::EnemiesTurnState::executePlayerAttack(GameController&) {}


};
