/**
 * @file Point.hpp
 * @brief Fichier de la classe Point *inutilisée*.
 */
#ifndef POINT_HPP
#define POINT_HPP

#include "Direction.hpp"

/**
 * @class Point
 * @brief Classe représentant des coordonnées 2D.
 */
class Point
{
private:
    int _x;
    int _y;

public:
    Point();
    Point(int x, int y);
    Point(const Point &point) = default;
    ~Point() = default;

    int getX() const { return _x; }
    int getY() const { return _y; }

    void setX(int x) { _x = x; }
    void setY(int y) { _y = y; }
};

extern Point ORIGINE;

Point operator+(const Point &p1, const Point &p2);
bool operator==(const Point &p1, const Point &p2);

Point directionToPoint(DIRECTION direction);
DIRECTION pointToDirection(Point point);

DIRECTION intToDirection(int entier);
int directionToInt(DIRECTION direction);

#endif