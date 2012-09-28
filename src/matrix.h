#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <iomanip>
#include <string>
#include <tr1/array>
typedef std::tr1::array<float, 3> Point;
typedef std::tr1::array<float, 4> Row;
typedef std::tr1::array<Row, 4> Matrix;
Matrix get_T(Point);
Matrix get_Ti(Point);
Matrix get_R(Point, Point, Point);
Matrix get_Ri(Point, Point, Point);
Matrix get_M(Point, Point, Point);
Matrix get_Mi(Point, Point, Point);
Point mul(Point, Matrix);
Point mul(Matrix, Point);
Row mul(Row, Matrix);
Row mul(Matrix, Row);
Matrix mul(Matrix, Matrix);
void pmatrix(std::string, Matrix);
#endif
