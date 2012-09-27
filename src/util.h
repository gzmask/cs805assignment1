#ifndef POINTS_HPP
#define POINTS_HPP
#include <tr1/array>
typedef std::tr1::array<float, 3> Point;
typedef std::tr1::array<Point, 3> UVN;
UVN get_uvn(Point V1, Point V2);
float get_length(Point X);
Point cross_product(Point x, Point y);
Point normalize(Point x);
#endif