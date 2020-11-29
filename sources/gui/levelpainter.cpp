#include <QPainter>

#include "sources/gui/levelpainter.h"
#include "sources/gui/texturemanager.h"
#include "sources/game/field.h"


void gui::LevelPainter::paint(sharedQPixmap& levelPixmap, const sharedConstPlayer& player, const Enemies& enemies) {
    if (Field::isCreated() && player != nullptr) {
        const Field& field = Field::getInstance();
        Size2D fieldSize = field.getSize();

        if (levelPixmap == nullptr ||
            static_cast<size_t>(levelPixmap->width()) != fieldSize.x * 64 ||
            static_cast<size_t>(levelPixmap->height()) != fieldSize.y * 64)
        {
            levelPixmap = std::make_shared<QPixmap>(fieldSize.x * 64, fieldSize.y * 64);
        }

        QPainter painter(levelPixmap.get());

        for (const Cell& cell : field) {
            Position2D coords = cell.getPosition();

            painter.drawImage(coords.x * 64, coords.y * 64, TextureManager::getTextureImage(TextureManager::getCellTexture(cell)));

            if (cell.getType() == CellType::Entry) {
                painter.drawImage(coords.x * 64, coords.y * 64, TextureManager::getTextureImage(Texture::Entry));
            } else if (cell.getType() == CellType::Exit) {
                painter.drawImage(coords.x * 64, coords.y * 64, TextureManager::getTextureImage(Texture::Exit));
            }

            if (cell.getPassable()) {
                painter.drawImage(coords.x * 64, coords.y * 64, TextureManager::getTextureImage(Texture::Cell));
            }

            if (cell.getObject() != nullptr) {
                painter.drawImage(coords.x * 64, coords.y * 64, TextureManager::getTextureImage(TextureManager::getObjectTexture(cell.getObject())));
            }

            if (coords.y == 0) {
                painter.drawImage(coords.x * 64, coords.y * 64, TextureManager::getTextureImage(Texture::Shadow2));
            }

            if (coords.x == 0) {
                painter.drawImage(coords.x * 64, coords.y * 64, TextureManager::getTextureImage(Texture::Shadow1));
            }

            if (coords.y == fieldSize.y - 1) {
                painter.drawImage(coords.x * 64, coords.y * 64, TextureManager::getTextureImage(Texture::Shadow4));
            }

            if (coords.x == fieldSize.x - 1) {
                painter.drawImage(coords.x * 64, coords.y * 64, TextureManager::getTextureImage(Texture::Shadow3));
            }
        }

        for (auto& enemy : enemies) {
            painter.drawImage(enemy->getPosition().x * 64, enemy->getPosition().y * 64, TextureManager::getTextureImage(TextureManager::getCreatureTexture(enemy)));
        }

        painter.drawImage(player->getPosition().x * 64, player->getPosition().y * 64, TextureManager::getTextureImage(TextureManager::getCreatureTexture(player)));
    }
}
