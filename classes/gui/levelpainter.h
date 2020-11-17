#ifndef LEVELPAINTER_H
#define LEVELPAINTER_H

#include <QPixmap>
#include "classes/game/objects/creatures/player/player.h"

typedef std::shared_ptr<QPixmap> pQPixmap;


class LevelPainter {
public:
    static void paint(pQPixmap& levelPixmap, pConstPlayer player);
};


#endif // LEVELPAINTER_H
