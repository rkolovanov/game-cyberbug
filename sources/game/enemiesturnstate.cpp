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
            Position2D new_position = enemy_position;

            // Movement
            if (enemy->getClass() == typeid(Enemy<MovementPolicy::Walk, AttackPolicy::Distance>) ||
                enemy->getClass() == typeid(Enemy<MovementPolicy::Walk, AttackPolicy::Melee>)) {
                if (delta_x > 0) {
                    new_position.shift(Direction::Right);
                    enemy->setRotation(Direction::Right);
                } else if (delta_x < 0) {
                    new_position.shift(Direction::Left);
                    enemy->setRotation(Direction::Left);
                } else if (delta_y > 0) {
                    new_position.shift(Direction::Bottom);
                    enemy->setRotation(Direction::Bottom);
                } else if (delta_y < 0) {
                    new_position.shift(Direction::Top);
                    enemy->setRotation(Direction::Top);
                }
            }

            if (enemy_position != new_position && controller.isPassablePosition(new_position)) {
                enemy->setPosition(new_position);
                enemy_position = new_position;
            }

            // Attack
            if (enemy->getClass() == typeid(Enemy<MovementPolicy::Stand, AttackPolicy::Melee>) ||
                enemy->getClass() == typeid(Enemy<MovementPolicy::Walk, AttackPolicy::Melee>)) {
                if (Position2D(enemy_position.x + 1, enemy_position.y) == player_position) {
                    enemy->setRotation(Direction::Right);
                    *enemy <= player;
                } else if (Position2D(enemy_position.x - 1, enemy_position.y) == player_position) {
                    enemy->setRotation(Direction::Left);
                    *enemy <= player;
                } else if (Position2D(enemy_position.x, enemy_position.y + 1) == player_position) {
                    enemy->setRotation(Direction::Bottom);
                    *enemy <= player;
                } else if (Position2D(enemy_position.x, enemy_position.y - 1) == player_position) {
                    enemy->setRotation(Direction::Top);
                    *enemy <= player;
                }
            } else {
                if (delta_x > 0 && delta_y == 0 && abs(delta_x) < 4) {
                    enemy->setRotation(Direction::Right);
                    *enemy <= player;
                } else if (delta_x < 0 && delta_y == 0 && abs(delta_x) < 4) {
                    enemy->setRotation(Direction::Left);
                    *enemy <= player;
                } else if (delta_y > 0 && delta_x == 0 && abs(delta_y) < 4) {
                    enemy->setRotation(Direction::Bottom);
                    *enemy <= player;
                } else if (delta_y < 0 && delta_x == 0 && abs(delta_y) < 4) {
                    enemy->setRotation(Direction::Top);
                    *enemy <= player;
                }
            }
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
