#ifndef POINT_2D_H
#define POINT_2D_H

#include <ostream>
#include "classes/enumerations/direction.h"

typedef struct Point2D Size2D;
typedef struct Point2D Position2D;


struct Point2D {
public:
    size_t x = 0;
    size_t y = 0;

    Point2D() = default;
    Point2D(size_t x, size_t y);
    bool operator==(const Point2D& other) const;
    bool operator!=(const Point2D& other) const;
    Point2D& shift(Direction direction);

    friend std::ostream& operator<<(std::ostream& stream, const Point2D& point);
};


#endif // POINT_2D_H
