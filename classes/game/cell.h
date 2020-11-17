#ifndef CELL_H
#define CELL_H

#include <memory>
#include "classes/common/point2d.h"
#include "classes/enumerations/celltype.h"
#include "classes/enumerations/texture.h"
#include "classes/game/objects/object.h"

typedef std::shared_ptr<class Cell> pCell;
typedef std::shared_ptr<std::shared_ptr<class Cell>> ppCell;


class Cell {
private:
    bool passable_ = false;
    CellType type_ = CellType::None;
    Position2D position_;
    pObject object_;

public:
    Cell() = default;
    explicit Cell(Position2D position, CellType type = CellType::None, pObject object = nullptr);
    Cell(const Cell& other);
    Cell(Cell&& other);
    ~Cell() = default;

    Cell& operator=(const Cell& other);
    Cell& operator=(Cell&& other);

    bool isPassable() const;
    bool getPassible() const;
    pConstObject getObject() const;
    CellType getType() const;
    Position2D getPosition() const;
    pObject& getObject();
    void setObject(const pObject& object);
    void changeType(CellType type);
};


#endif // CELL_H
