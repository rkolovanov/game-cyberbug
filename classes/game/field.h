#ifndef FIELD_H
#define FIELD_H

#include <memory>
#include "classes/game/cell.h"

typedef std::unique_ptr<class Field> pField;


class Field {
private:
    static pField instance_;

    Size2D size_ = Size2D(0, 0);
    ppCell cells_ = nullptr;

    Field(const Size2D& size);
    Field(const Field& other);
    Field(Field&& other);

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
};


class Field::FieldIterator {
    Position2D position_;

public:
    explicit FieldIterator(const Position2D& position);

    bool operator==(const FieldIterator& other) const;
    bool operator!=(const FieldIterator& other) const;
    FieldIterator& operator++();
    FieldIterator operator++(int);
    Cell& operator*();
};

class Field::ConstFieldIterator {
    Position2D position_;

public:
    explicit ConstFieldIterator(const Position2D& position);

    bool operator==(const ConstFieldIterator& other) const;
    bool operator!=(const ConstFieldIterator& other) const;
    ConstFieldIterator& operator++();
    ConstFieldIterator operator++(int);
    const Cell& operator*() const;
};


#endif // FIELD_H
