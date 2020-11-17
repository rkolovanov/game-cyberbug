#include "classes/game/field.h"
#include "classes/common/exception.h"

pField Field::instance_ = nullptr;

Field::Field(const Size2D& size): size_(size) {
    cells_ = ppCell(new pCell[size.y], std::default_delete<pCell[]>());

    for (size_t y = 0; y < size.y; y++) {
        cells_.get()[y] = pCell(new Cell[size.x], std::default_delete<Cell[]>());

        for (size_t x = 0; x < size.x; x++) {
            cells_.get()[y].get()[x] = Cell(Position2D(x, y));
        }
    }
}

Field::Field(const Field& other) {
    size_ = other.size_;

    if (other.cells_ != nullptr) {
        cells_ = ppCell(new pCell[size_.y], std::default_delete<pCell[]>());

        for (size_t y = 0; y < size_.y; y++) {
            cells_.get()[y] = pCell(new Cell[size_.x], std::default_delete<Cell[]>());

            for (size_t x = 0; x < size_.x; x++) {
                cells_.get()[y].get()[x] = other.cells_.get()[y].get()[x];
            }
        }
    }
}

Field::Field(Field&& other) {
    size_ = other.size_;
    cells_ = other.cells_;
}

Field& Field::operator=(const Field& other) {
    if (this != &other) {
        size_ = other.size_;

        if (other.cells_ != nullptr) {
            cells_ = ppCell(new pCell[size_.y], std::default_delete<pCell[]>());

            for (size_t y = 0; y < size_.y; y++) {
                cells_.get()[y] = pCell(new Cell[size_.x], std::default_delete<Cell[]>());

                for (size_t x = 0; x < size_.x; x++) {
                    cells_.get()[y].get()[x] = other.cells_.get()[y].get()[x];
                }
            }
        }
    }

    return *this;
}

Field& Field::operator=(Field&& other) {
    if (this != &other) {
        std::swap(size_, other.size_);
        std::swap(cells_, other.cells_);
    }

    return *this;
}

Field& Field::initInstance(const Size2D& size) {
    if (!isCreated()) {
        instance_ = pField(new Field(size));
    }
    return *instance_;
}

Field& Field::getInstance() {
    if (!isCreated()) {
        throw Exception("Instance of class 'Field' is not created.\n");
    }
    return *instance_;
}

void Field::deleteInstance() {
    Field::instance_ = nullptr;
}

bool Field::isCreated() {
    return Field::instance_ != nullptr;
}

Cell& Field::getCell(const Position2D& position) {
    if (position.x >= size_.x || position.y >= size_.y) {
        throw Exception("Method Field::getCell(): Out of field range.");
    }
    return cells_.get()[position.y].get()[position.x];
}

const Cell& Field::getCell(const Position2D& position) const {
    if (position.x >= size_.x || position.y >= size_.y) {
        throw Exception("Method Field::getCell(): Out of field range.");
    }
    return cells_.get()[position.y].get()[position.x];
}

Size2D Field::getSize() const {
    return size_;
}

bool Field::isCorrectPosition(Position2D position) const {
    if (position.x < getSize().x && position.y < getSize().y) {
        return true;
    }

    return false;
}

Field::FieldIterator Field::begin() {
    return FieldIterator(Position2D(0, 0));
}

Field::FieldIterator Field::end() {
    return FieldIterator(Position2D(0, getSize().y));
}

const Field::ConstFieldIterator Field::begin() const {
    return ConstFieldIterator(Position2D(0, 0));
}

const Field::ConstFieldIterator Field::end() const {
    return ConstFieldIterator(Position2D(0, getSize().y));
}

Field::FieldIterator::FieldIterator(const Position2D& position): position_(position) {}

bool Field::FieldIterator::operator==(const FieldIterator& other) const {
    return position_ == other.position_;
}

bool Field::FieldIterator::operator!=(const FieldIterator& other) const {
    return !operator==(other);
}

Field::FieldIterator& Field::FieldIterator::operator++() {
    Field& field = Field::getInstance();

    if (position_.x + 1 >= field.getSize().x) {
        position_.y++;
        position_.x = 0;
    } else {
        position_.x++;
    }

    return *this;
}

Field::FieldIterator Field::FieldIterator::operator++(int) {
    FieldIterator iterator(*this);
    operator++();
    return iterator;
}

Cell& Field::FieldIterator::operator*() {
    Field& field = Field::getInstance();
    return field.getCell(position_);
}

Field::ConstFieldIterator::ConstFieldIterator(const Position2D& position): position_(position) {}

bool Field::ConstFieldIterator::operator==(const Field::ConstFieldIterator& other) const {
    return position_ == other.position_;
}

bool Field::ConstFieldIterator::operator!=(const Field::ConstFieldIterator& other) const {
    return !operator==(other);
}

Field::ConstFieldIterator& Field::ConstFieldIterator::operator++() {
    const Field& field = Field::getInstance();

    if (position_.x + 1 >= field.getSize().x) {
        position_.y++;
        position_.x = 0;
    } else {
        position_.x++;
    }

    return *this;
}

Field::ConstFieldIterator Field::ConstFieldIterator::operator++(int) {
    ConstFieldIterator iterator(*this);
    operator++();
    return iterator;
}

const Cell& Field::ConstFieldIterator::operator*() const {
    const Field& field = Field::getInstance();
    return field.getCell(position_);
}
