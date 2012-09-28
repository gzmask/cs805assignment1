#ifndef VecotrS_HPP
#define VecotrS_HPP
#include <tr1/array>
typedef std::tr1::array<float, 3> Vecotr;
typedef std::tr1::array<Vecotr, 3> UVN;
UVN get_uvn(Vecotr V1, Vecotr V2);
float get_length(Vecotr);
Vecotr cross_product(Vecotr, Vecotr);
Vecotr normalize(Vecotr);
#endif
