#include "point2d.h"

Point2D::Point2D(size_t x, size_t y): x(x), y(y) {}

bool Point2D::operator==(const Point2D& other) const {
    return x == other.x && y ==other.y;
}

bool Point2D::operator!=(const Point2D& other) const {
    return !operator==(other);
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

std::ostream& operator<<(std::ostream& stream, const Point2D& point) {
    stream << "(" << point.x << ", " << point.y << ")";
    return stream;
}
