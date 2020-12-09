#ifndef SOURCES_GAME_FIELD_MEMENTO_H
#define SOURCES_GAME_FIELD_MEMENTO_H

#include <vector>

#include "sources/common/imemento.h"
#include "sources/game/cell.h"

using CellRow = std::vector<Cell>;
using CellTable = std::vector<CellRow>;
using sharedCellTable = std::shared_ptr<CellTable>;


class FieldMemento final: public IMemento {
private:
    sharedCellTable cells_;
    Size2D size_;

public:
    FieldMemento(const sharedCellTable& cells, Size2D size);
    sharedCellTable getCellTable();
    Size2D getSize();
}; // class FieldMemento


#endif // SOURCES_GAME_FIELD_MEMENTO_H
