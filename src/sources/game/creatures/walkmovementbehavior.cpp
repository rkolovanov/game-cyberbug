#include <vector>
#include <algorithm>

#include "sources/game/creatures/walkmovementbehavior.h"
#include "sources/game/field.h"

namespace game {


Position2D game::WalkMovementBehavior::getMovementPosition(Creature& creature, const Position2D& target_position) {
    game::Position2D creature_position = creature.getPosition();

    using Length = size_t;
    using Checked = bool;

    Field& field = Field::getInstance();

    const int R = 6;
    const int D = 2 * R + 1;
    const int N = D * D;
    const int INF = 10e6;
    int c_x = static_cast<int>(creature_position.x) - R;
    int c_y = static_cast<int>(creature_position.y) - R;
    int start, target;

    std::vector<Position2D> places;
    std::vector<int> p;
    std::vector<Length> d;
    std::vector<Checked> u;
    std::vector<std::vector<size_t>> g;

    places.reserve(N);
    p.reserve(N);
    d.reserve(N);
    u.reserve(N);
    g.reserve(N);

    for (size_t y = 0; y < D; y++) {
        for (size_t x = 0; x < D; x++) {
            if (c_x + x >= 0 && c_y + y >= 0) {
                Position2D position(c_x + x, c_y + y);

                if (field.isCorrectPosition(position)) {
                    places.push_back(position);
                    p.push_back(-1);
                    d.push_back(INF);
                    u.push_back(false);
                    g.push_back(std::vector<size_t>());

                    if (position == creature_position) {
                        start = places.size() - 1;
                    } else if (position == target_position) {
                        target = places.size() - 1;
                    }
                }
            }
        }
    }

    d[start] = 0;

    for (size_t i = 0; i < places.size(); i++) {
        Position2D& position = places[i];

        Position2D pos(position.x + 1, position.y);
        auto f = std::find(places.begin(), places.end(), pos);
        if (f != places.end()) {
            if (field.getCell(pos).isPassable()) {
                g[i].push_back(std::distance(places.begin(), f));
            }
        }

        pos = Position2D(position.x - 1, position.y);
        f = std::find(places.begin(), places.end(), pos);
        if (f != places.end()) {
            if (field.getCell(pos).isPassable()) {
                g[i].push_back(std::distance(places.begin(), f));
            }
        }

        pos = Position2D(position.x, position.y + 1);
        f = std::find(places.begin(), places.end(), pos);
        if (f != places.end()) {
            if (field.getCell(pos).isPassable()) {
                g[i].push_back(std::distance(places.begin(), f));
            }
        }

        pos = Position2D(position.x, position.y - 1);
        f = std::find(places.begin(), places.end(), pos);
        if (f != places.end()) {
            if (field.getCell(pos).isPassable()) {
                g[i].push_back(std::distance(places.begin(), f));
            }
        }
    }

    for (size_t i = 0; i < places.size(); i++) {
        int v = -1;
        for (size_t j = 0; j < places.size(); j++) {
            if ((v == -1 || d[j] < d[v]) && u[j] == false) {
                v = j;
            }
        }
        if (d[v] == INF)
            break;
        u[v] = true;

        for (size_t j = 0; j < g[v].size(); j++) {
            size_t idx = g[v][j];
            if (d[v] + 1 < d[idx]) {
                d[idx] = d[v] + 1;
                p[idx] = v;
            }
        }
    }

    int pp = p[target];
    if (d[target] < INF) {
        while (p[pp] != start && p[pp] != -1) {
            pp = p[pp];
        }

        if (p[pp] != -1) {
            return places[pp];
        }
    }

    return creature_position;
}


};
