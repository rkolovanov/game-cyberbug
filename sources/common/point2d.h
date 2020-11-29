#ifndef SOURCES_COMMON_POINT_2D_H
#define SOURCES_COMMON_POINT_2D_H

#include <ostream>

#include "sources/common/direction.h"

using Size2D = struct Point2D;
using Position2D = struct Point2D;


struct Point2D final {
public:
    size_t x;
    size_t y;

    Point2D();
    Point2D(size_t x, size_t y);

    friend bool operator==(const Point2D& left, const Point2D& right);
    friend bool operator!=(const Point2D& left, const Point2D& right);
    friend std::ostream& operator<<(std::ostream& stream, const Point2D& point);

    Point2D& shift(Direction direction);
}; // struct Point2D


#endif // SOURCES_COMMON_POINT_2D_H
