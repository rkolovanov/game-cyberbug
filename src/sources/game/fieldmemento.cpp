#include "sources/game/fieldmemento.h"

namespace game {


game::FieldMemento::FieldMemento(const sharedCellTable& cells, Size2D size) {
    size_ = size;

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


game::sharedCellTable game::FieldMemento::getCellTable() {
    return cells_;
}


Size2D game::FieldMemento::getSize() const {
    return size_;
}


};
