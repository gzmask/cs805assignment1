#include <iostream>
#include "points.hpp"
#include "get_uvn.cpp"

using namespace std;

int main () {
  Point V1;
  Point V2;
  UVN uvn = get_uvn(V1, V2);

  return 0;
}
