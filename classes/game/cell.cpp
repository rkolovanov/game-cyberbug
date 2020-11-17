#include "cell.h"

Cell::Cell(Position2D coords, CellType type, pObject object) {
    position_ = coords;
    object_ = object;
    changeType(type);
}

Cell::Cell(const Cell& other) {
    operator=(other);
}

Cell::Cell(Cell&& other) {
    position_ = other.position_;
    type_ = other.type_;
    passable_ = other.passable_;
    object_ = other.object_;
}

Cell& Cell::operator=(const Cell& other) {
    if (this != &other) {
        position_ = other.position_;
        type_ = other.type_;
        passable_ = other.passable_;

        if (other.object_ != nullptr) {
            object_ = other.object_->getCopy();
        }
    }

    return *this;
}

Cell& Cell::operator=(Cell&& other) {
    if (this != &other) {
        std::swap(position_, other.position_);
        std::swap(type_, other.type_);
        std::swap(passable_, other.passable_);
        std::swap(object_, other.object_);
    }

    return *this;
}

bool Cell::isPassable() const {
    return passable_ && object_ == nullptr;
}

bool Cell::getPassible() const {
    return passable_;
}

pConstObject Cell::getObject() const {
    return object_;
}

CellType Cell::getType() const {
    return type_;
}

Position2D Cell::getPosition() const {
    return position_;
}

pObject& Cell::getObject() {
    return object_;
}

void Cell::setObject(const pObject& object) {
    object_ = object;
}

void Cell::changeType(CellType type) {
    type_ = type;

    switch (type) {
    case CellType::Empty:
    case CellType::Entry:
    case CellType::Exit:
        passable_ = true;
        return;

    case CellType::None:
    case CellType::Wall:
    default:
        passable_ = false;
        return;
    }
}
