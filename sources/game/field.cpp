#include <utility>

#include "sources/game/field.h"
#include "sources/common/exception.h"

namespace game {


game::uniqueField game::Field::instance_ = nullptr;


game::Field::Field(const Size2D& size): size_(size) {
    cells_ = std::make_shared<CellTable>(size_.y);

    for (size_t y = 0; y < size_.y; y++) {
        CellRow& row = cells_->at(y);
        row.resize(size_.x);

        for (size_t x = 0; x < size_.x; x++) {
            row.at(x) = Cell(Position2D(x, y));
        }
    }
}


game::Field::Field(const Field& other) {
    size_ = other.size_;
    cells_.reset();

    if (other.cells_ == nullptr) {
        return;
    }

    cells_ = std::make_shared<CellTable>(size_.y);

    for (size_t y = 0; y < size_.y; y++) {
        CellRow& row = cells_->at(y);
        row.resize(size_.x);

        for (size_t x = 0; x < size_.x; x++) {
            row.at(x) = other.cells_->at(y).at(x);
        }
    }
}


game::Field::Field(Field&& other) {
    size_ = std::move(other.size_);
    cells_ = std::move(other.cells_);
}


game::Field& game::Field::operator=(const Field& other) {
    if (this != &other) {
        return *this;
    }

    size_ = other.size_;
    cells_ = nullptr;

    if (other.cells_ == nullptr) {
        return *this;
    }

    cells_ = std::make_shared<CellTable>(size_.y);

    for (size_t y = 0; y < size_.y; y++) {
        CellRow& row = cells_->at(y);
        row.resize(size_.x);

        for (size_t x = 0; x < size_.x; x++) {
            row.at(x) = other.cells_->at(y).at(x);
        }
    }

    return *this;
}


game::Field& game::Field::operator=(Field&& other) {
    if (this != &other) {
        size_ = std::move(other.size_);
        cells_ = std::move(other.cells_);
    }
    return *this;
}


game::Field& game::Field::initInstance(const Size2D& size) {
    if (!isCreated()) {
        // Конструктор приватный, поэтому std::make_unique применить не удается
        instance_ = uniqueField(new Field(size));
    }
    return *instance_;
}


game::Field& game::Field::getInstance() {
    if (!isCreated()) {
        throw Exception("Instance of class 'Field' is not created.");
    }
    return *instance_;
}


void game::Field::deleteInstance() {
    Field::instance_.reset();
}


bool game::Field::isCreated() {
    return Field::instance_ != nullptr;
}


game::Cell& game::Field::getCell(const Position2D& position) {
    if (position.x >= size_.x || position.y >= size_.y) {
        throw Exception("Method Field::getCell(): Out of field range.");
    }
    return cells_->at(position.y).at(position.x);
}


const game::Cell& game::Field::getCell(const Position2D& position) const {
    if (position.x >= size_.x || position.y >= size_.y) {
        throw Exception("Method Field::getCell(): Out of field range.");
    }
    return cells_->at(position.y).at(position.x);
}


Size2D game::Field::getSize() const {
    return size_;
}


bool game::Field::isCorrectPosition(Position2D position) const {
    return position.x < getSize().x && position.y < getSize().y;
}


game::Field::FieldIterator game::Field::begin() {
    return FieldIterator(Position2D(0, 0));
}


game::Field::FieldIterator game::Field::end() {
    return FieldIterator(Position2D(0, getSize().y));
}


const game::Field::ConstFieldIterator game::Field::begin() const {
    return ConstFieldIterator(Position2D(0, 0));
}


const game::Field::ConstFieldIterator game::Field::end() const {
    return ConstFieldIterator(Position2D(0, getSize().y));
}


game::FieldMemento game::Field::save() const {
    return FieldMemento(cells_, size_);
}


void game::Field::restore(FieldMemento& snapshot) {
    sharedCellTable cells = snapshot.getCellTable();
    size_ = snapshot.getSize();
    cells_.reset();

    if (cells == nullptr) {
        return;
    }

    cells_ = std::make_shared<CellTable>(size_.y);

    for (size_t y = 0; y < size_.y; y++) {
        CellRow& row = cells_->at(y);
        row.resize(size_.x);

        for (size_t x = 0; x < size_.x; x++) {
            row.at(x) = cells->at(y).at(x);
        }
    }
}


game::Field::FieldIterator::FieldIterator(const Position2D& position): position_(position) {}


bool game::Field::FieldIterator::operator==(const FieldIterator& other) const {
    return position_ == other.position_;
}


bool game::Field::FieldIterator::operator!=(const FieldIterator& other) const {
    return !operator==(other);
}


game::Field::FieldIterator& game::Field::FieldIterator::operator++() {
    const Field& field = Field::getInstance();

    if (position_.x + 1 >= field.getSize().x) {
        position_.y++;
        position_.x = 0;
    } else {
        position_.x++;
    }

    return *this;
}


game::Field::FieldIterator game::Field::FieldIterator::operator++(int) {
    FieldIterator iterator(*this);
    operator++();
    return iterator;
}


game::Cell& game::Field::FieldIterator::operator*() const {
    Field& field = Field::getInstance();
    return field.getCell(position_);
}


game::Field::ConstFieldIterator::ConstFieldIterator(const Position2D& position): position_(position) {}


bool game::Field::ConstFieldIterator::operator==(const Field::ConstFieldIterator& other) const {
    return position_ == other.position_;
}


bool game::Field::ConstFieldIterator::operator!=(const Field::ConstFieldIterator& other) const {
    return !operator==(other);
}


game::Field::ConstFieldIterator& game::Field::ConstFieldIterator::operator++() {
    const Field& field = Field::getInstance();

    if (position_.x + 1 >= field.getSize().x) {
        position_.y++;
        position_.x = 0;
    } else {
        position_.x++;
    }

    return *this;
}


game::Field::ConstFieldIterator game::Field::ConstFieldIterator::operator++(int) {
    ConstFieldIterator iterator(*this);
    operator++();
    return iterator;
}


const game::Cell& game::Field::ConstFieldIterator::operator*() const {
    const Field& field = Field::getInstance();
    return field.getCell(position_);
}


};
