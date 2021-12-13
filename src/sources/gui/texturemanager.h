#ifndef SOURCES_GUI_TEXTURE_MANAGER_H
#define SOURCES_GUI_TEXTURE_MANAGER_H

#include <QMap>
#include <QImage>

#include "sources/gui/texture.h"
#include "sources/game/cell.h"
#include "sources/game/creatures/creature.h"

namespace gui {


class TextureManager final {
private:
    static QMap<Texture, QImage> textures_;

public:
    static void initTextures();
    static QImage& getTextureImage(Texture texture);
    static Texture getCellTexture(const game::Cell& cell);
    static Texture getObjectTexture(const game::sharedConstObject& object);
    static Texture getCreatureTexture(const game::sharedConstCreature& creature);
}; // class TextureManager


}; // namespace gui

#endif // SOURCES_GUI_TEXTURE_MANAGER_H
