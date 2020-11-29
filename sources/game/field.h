#ifndef SOURCES_GAME_FIELD_H
#define SOURCES_GAME_FIELD_H

#include <memory>
#include <vector>

#include "sources/game/cell.h"

using uniqueField = std::unique_ptr<class Field>;
using CellRow = std::vector<Cell>;
using CellTable = std::vector<CellRow>;
using sharedCellTable = std::shared_ptr<CellTable>;


class Field final {
private:
    static uniqueField instance_;

    Size2D size_;
    sharedCellTable cells_;

    explicit Field(const Size2D& size);
    explicit Field(const Field& other);
    explicit Field(Field&& other);

    Field& operator=(const Field& other);
    Field& operator=(Field&& other);

    class FieldIterator;
    class ConstFieldIterator;

public:
    static Field& initInstance(const Size2D& size);
    static Field& getInstance();
    static void deleteInstance();
    static bool isCreated();

    Cell& getCell(const Position2D& position);
    const Cell& getCell(const Position2D& position) const;
    Size2D getSize() const;
    bool isCorrectPosition(Position2D position) const;
    FieldIterator begin();
    FieldIterator end();
    const ConstFieldIterator begin() const;
    const ConstFieldIterator end() const;
}; // class Field


class Field::FieldIterator final {
    Position2D position_;

public:
    explicit FieldIterator(const Position2D& position);

    bool operator==(const FieldIterator& other) const;
    bool operator!=(const FieldIterator& other) const;
    FieldIterator& operator++();
    FieldIterator operator++(int);
    Cell& operator*() const;
}; // class Field::FieldIterator


class Field::ConstFieldIterator final {
    Position2D position_;

public:
    explicit ConstFieldIterator(const Position2D& position);

    bool operator==(const ConstFieldIterator& other) const;
    bool operator!=(const ConstFieldIterator& other) const;
    ConstFieldIterator& operator++();
    ConstFieldIterator operator++(int);
    const Cell& operator*() const;
}; // class Field::ConstFieldIterator


#endif // SOURCES_GAME_FIELD_H
