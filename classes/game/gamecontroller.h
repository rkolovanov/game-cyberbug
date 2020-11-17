#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QPixmap>
#include "classes/game/objects/creatures/player/player.h"
#include "classes/game/field.h"
#include "classes/logging/logginglistener.h"

typedef std::shared_ptr<class GameController> pGameController;
typedef std::shared_ptr<QPixmap> pQPixmap;


class GameController {
private:
    pPlayer player_;
    pLoggingListener logger_;
    size_t level_ = 0;
    bool levelComplete_ = false;

public:
    GameController(pLoggingListener& logger);
    void createLevel();
    void movePlayer(Direction direction);
    void executePlayerInteraction();
    bool isPlayerReachedExit() const;
    bool isLevelComplete() const;
    void getLevelPixmap(pQPixmap& levelPixmap) const;
    pConstPlayer getPlayer();
    size_t getLevelNumber();
    ~GameController();
};


#endif // GAMECONTROLLER_H
