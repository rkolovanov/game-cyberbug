#include "sources/game/cell.h"

namespace game {


game::Cell::Cell(): passable_(false), type_(CellType::None) {}


game::Cell::Cell(Position2D coords, CellType type, sharedObject object)
    : passable_(false), position_(coords), object_(object) {
    changeType(type);
}


game::Cell::Cell(const Cell& other) {
    operator=(other);
}


game::Cell::Cell(Cell&& other) {
    position_ = std::move(other.position_);
    type_ = std::move(other.type_);
    passable_ = std::move(other.passable_);
    object_ =std::move(other.object_);
}


game::Cell& game::Cell::operator=(const Cell& other) {
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


game::Cell& game::Cell::operator=(Cell&& other) {
    if (this != &other) {
        position_ = std::move(other.position_);
        type_ = std::move(other.type_);
        passable_ = std::move(other.passable_);
        object_ =std::move(other.object_);
    }
    return *this;
}


bool game::Cell::isPassable() const {
    return passable_ && object_ == nullptr;
}


bool game::Cell::getPassable() const {
    return passable_;
}


game::sharedConstObject game::Cell::getObject() const {
    return object_;
}


game::CellType game::Cell::getType() const {
    return type_;
}


Position2D game::Cell::getPosition() const {
    return position_;
}


game::sharedObject& game::Cell::getObject() {
    return object_;
}


void game::Cell::setObject(const sharedObject& object) {
    object_ = object;
}


void game::Cell::changeType(CellType type) {
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


};
