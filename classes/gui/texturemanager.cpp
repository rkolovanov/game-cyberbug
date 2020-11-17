#include "classes/gui/texturemanager.h"
#include "classes/game/field.h"
#include "classes/game/objects/armor/armor.h"
#include "classes/game/objects/medicines/medicines.h"
#include "classes/game/objects/weapon/weapon.h"
#include "classes/game/objects/levelpassobject/levelpassobject.h"
#include "classes/game/objects/creatures/player/player.h"
#include <cmath>

QMap<Texture, QImage> TextureManager::textures_;

void TextureManager::initTextures() {
    textures_[Texture::Void] = QImage(":/textures/tiles/tile_00.png");
    textures_[Texture::WoodFloor] = QImage(":/textures/tiles/tile_100.png");
    textures_[Texture::WoodWallLR] = QImage(":/textures/tiles/tile_120.png");
    textures_[Texture::WoodWallTB] = QImage(":/textures/tiles/tile_147.png");
    textures_[Texture::WoodWallTR] = QImage(":/textures/tiles/tile_145.png");
    textures_[Texture::WoodWallTL] = QImage(":/textures/tiles/tile_146.png");
    textures_[Texture::WoodWallBR] = QImage(":/textures/tiles/tile_118.png");
    textures_[Texture::WoodWallLB] = QImage(":/textures/tiles/tile_119.png");
    textures_[Texture::WoodWallLBR] = QImage(":/textures/tiles/tile_121.png");
    textures_[Texture::WoodWallL] = QImage(":/textures/tiles/tile_123.png");
    textures_[Texture::WoodWallT] = QImage(":/textures/tiles/tile_124.png");
    textures_[Texture::WoodWallTLR] = QImage(":/textures/tiles/tile_122.png");
    textures_[Texture::WoodWallTBR] = QImage(":/textures/tiles/tile_148.png");
    textures_[Texture::WoodWallR] = QImage(":/textures/tiles/tile_151.png");
    textures_[Texture::WoodWallTLB] = QImage(":/textures/tiles/tile_149.png");
    textures_[Texture::WoodWallB] = QImage(":/textures/tiles/tile_150.png");
    textures_[Texture::WoodWall] = QImage(":/textures/tiles/tile_205.png");
    textures_[Texture::WoodWallTLBR] = QImage(":/textures/tiles/tile_179.png");
    textures_[Texture::Entry] = QImage(":/textures/tiles/tile_132.png");
    textures_[Texture::Exit] = QImage(":/textures/tiles/tile_133.png");
    textures_[Texture::Shadow1] = QImage(":/textures/tiles/shadow_01.png");
    textures_[Texture::Shadow2] = QImage(":/textures/tiles/shadow_02.png");
    textures_[Texture::Shadow3] = QImage(":/textures/tiles/shadow_03.png");
    textures_[Texture::Shadow4] = QImage(":/textures/tiles/shadow_04.png");
    textures_[Texture::Cell] = QImage(":/textures/tiles/cell.png");
    textures_[Texture::PlayerStandT] = QImage(":/textures/player/player_stand_t.png");
    textures_[Texture::PlayerStandB] = QImage(":/textures/player/player_stand_d.png");
    textures_[Texture::PlayerStandR] = QImage(":/textures/player/player_stand_r.png");
    textures_[Texture::PlayerStandL] = QImage(":/textures/player/player_stand_l.png");
    textures_[Texture::ObjectMedicines] = QImage(":/textures/tiles/tile_290.png");
    textures_[Texture::ObjectArmor] = QImage(":/textures/tiles/tile_129.png");
    textures_[Texture::ObjectWeapon] = QImage(":/textures/tiles/tile_129_2.png");
    textures_[Texture::ObjectLevelPass] = QImage(":/textures/tiles/tile_key.png");
    textures_[Texture::Transparent] = QImage(":/textures/tiles/transparent.png");
}

QImage& TextureManager::getTextureImage(Texture texture) {
    return textures_[texture];
}

Texture TextureManager::getCellTexture(const Cell& cell) {
    const Field& field = Field::getInstance();
    Position2D neighborCellsPosition[4];
    int result = 0;

    neighborCellsPosition[0] = cell.getPosition().shift(Direction::Right);
    neighborCellsPosition[1] = cell.getPosition().shift(Direction::Bottom);
    neighborCellsPosition[2] = cell.getPosition().shift(Direction::Left);
    neighborCellsPosition[3] = cell.getPosition().shift(Direction::Top);

    for (int i = 0; i < 4; i++) {
        if (field.isCorrectPosition(neighborCellsPosition[i])) {
             if (field.getCell(neighborCellsPosition[i]).getType() == CellType::Wall) {
                 result += pow(2, i);
             }
        }
    }

    if (cell.getType() == CellType::Wall) {
        switch (result) {
        case 0: return Texture::WoodWall;
        case 1: return Texture::WoodWallR;
        case 2: return Texture::WoodWallB;
        case 3: return Texture::WoodWallBR;
        case 4: return Texture::WoodWallL;
        case 5: return Texture::WoodWallLR;
        case 6: return Texture::WoodWallLB;
        case 7: return Texture::WoodWallLBR;
        case 8: return Texture::WoodWallT;
        case 9: return Texture::WoodWallTR;
        case 10: return Texture::WoodWallTB;
        case 11: return Texture::WoodWallTBR;
        case 12: return Texture::WoodWallTL;
        case 13: return Texture::WoodWallTLR;
        case 14: return Texture::WoodWallTLB;
        case 15: return Texture::WoodWallTLBR;
        }
    } else if (cell.getType() == CellType::Empty) {
        return Texture::WoodFloor;
    } else if (cell.getType() == CellType::Entry) {
        return Texture::WoodFloor;
    } else if (cell.getType() == CellType::Exit) {
        return Texture::WoodFloor;
    }

    return Texture::Void;
}

Texture TextureManager::getObjectTexture(pConstObject object) {
    if (object != nullptr) {
        if (object->getClass() == typeid(Medicines)) {
            return Texture::ObjectMedicines;
        } else if (object->getClass() == typeid(Armor)) {
            return Texture::ObjectArmor;
        } else if (object->getClass() == typeid(Weapon)) {
            return Texture::ObjectWeapon;
        } else if (object->getClass() == typeid(LevelPassObject)) {
            return Texture::ObjectLevelPass;
        }
    }

    return Texture::Transparent;
}

Texture TextureManager::getCreatureTexture(pConstCreature creature) {
    if (creature != nullptr) {
        try {
            const Player& player = dynamic_cast<const Player&>(*creature);

            switch (player.getRotation()) {
            case Direction::Top:
                return Texture::PlayerStandT;
            case Direction::Bottom:
                return Texture::PlayerStandB;
            case Direction::Left:
                return Texture::PlayerStandL;
            case Direction::Right:
                return Texture::PlayerStandR;
            }
        } catch (const std::bad_cast&) {
            return Texture::Transparent;
        }
    }

    return Texture::Transparent;
}
