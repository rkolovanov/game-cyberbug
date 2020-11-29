#ifndef SOURCES_GUI_LEVELPAINTER_H
#define SOURCES_GUI_LEVELPAINTER_H

#include <QPixmap>

#include "sources/game/objects/creatures/player/player.h"

namespace gui {

using sharedQPixmap = std::shared_ptr<QPixmap>;
using Enemies = std::vector<sharedCreature>;


class LevelPainter final {
public:
    static void paint(sharedQPixmap& level_pixmap, const sharedConstPlayer& player, const Enemies& enemies);
}; // class LevelPainter


}; // namespace gui

#endif // SOURCES_GUI_LEVELPAINTER_H
