#include "sources/game/point2d.h"

namespace game {


Point2D::Point2D(): x(0), y(0) {}


Point2D::Point2D(size_t x, size_t y): x(x), y(y) {}


bool operator==(const Point2D& left, const Point2D& right) {
    return left.x == right.x && left.y == right.y;
}


bool operator!=(const Point2D& left, const Point2D& right) {
    return !operator==(left, right);
}


bool operator<(const Point2D& left, const Point2D& right) {
    return operator!=(left, right) && (left.y <= right.y && left.x <= right.x);
}


std::ostream& operator<<(std::ostream& stream, const Point2D& point) {
    stream << "(" << point.x << ", " << point.y << ")";
    return stream;
}


Point2D& Point2D::shift(Direction direction) {
    switch (direction) {
    case Direction::Top:
        y--;
        break;
    case Direction::Bottom:
        y++;
        break;
    case Direction::Left:
        x--;
        break;
    case Direction::Right:
        x++;
        break;
    }
    return *this;
}


};
