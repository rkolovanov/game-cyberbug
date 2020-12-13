#ifndef SOURCES_GUI_LEVELPAINTER_H
#define SOURCES_GUI_LEVELPAINTER_H

#include <QPixmap>

#include "sources/game/creatures/player/player.h"
#include "sources/game/creatures/enemies/abstractenemy.h"

namespace gui {

using sharedQPixmap = std::shared_ptr<QPixmap>;


class LevelPainter final {
public:
    static void paint(sharedQPixmap& level_pixmap, const game::sharedConstPlayer& player, const game::Enemies& enemies);
}; // class LevelPainter


}; // namespace gui

#endif // SOURCES_GUI_LEVELPAINTER_H
