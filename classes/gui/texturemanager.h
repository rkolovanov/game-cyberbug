#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <QMap>
#include <QImage>
#include "classes/enumerations/texture.h"
#include "classes/game/cell.h"


class TextureManager {
private:
    static QMap<Texture, QImage> textures_;

public:
    static void initTextures();
    static QImage& getTextureImage(Texture texture);
    static Texture getCellTexture(const Cell& cell);
    static Texture getObjectTexture(pConstObject object);
    static Texture getCreatureTexture(pConstCreature creature);
};


#endif // TEXTUREMANAGER_H
