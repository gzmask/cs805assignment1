#ifndef MATRIX_H
#define MATRIX_H
#include <tr1/array>
typedef std::tr1::array<float, 3> Point;
typedef std::tr1::array<float, 4> Row;
typedef std::tr1::array<Row, 4> Matrix;
Matrix get_T(Point);
#endif
