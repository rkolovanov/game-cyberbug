#ifndef SOURCES_GAME_CELL_H
#define SOURCES_GAME_CELL_H

#include <memory>

#include "sources/common/point2d.h"
#include "sources/game/celltype.h"
#include "sources/gui/texture.h"
#include "sources/game/objects/object.h"

namespace game {


class Cell final {
private:
    bool passable_;
    CellType type_;
    Position2D position_;
    sharedObject object_;

public:
    Cell();
    explicit Cell(Position2D position, CellType type = CellType::None, sharedObject object = nullptr);
    explicit Cell(const Cell& other);
    explicit Cell(Cell&& other);

    Cell& operator=(const Cell& other);
    Cell& operator=(Cell&& other);

    bool isPassable() const;
    bool getPassable() const;
    sharedConstObject getObject() const;
    CellType getType() const;
    Position2D getPosition() const;
    sharedObject& getObject();
    //sharedConstObject& getObject() const;
    void setObject(const sharedObject& object);
    void changeType(CellType type);
}; // class Cell


};

#endif // SOURCES_GAME_CELL_H
