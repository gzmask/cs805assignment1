#include "util.h"
#include <math.h>

//get u,v,n from two non-collinear vectors
UVN get_uvn(Point V1, Point V2) {
  //get n, which is just normalized V1
  Point n = normalize(V1); 

  //get u, which is normalized V2 x V1
  Point u = normalize(cross_product(V2, V1));

  //get v, which is normalized n x u
  Point v = normalize(cross_product(n, u));

  return {u,v,n};
}

//normalize a point
Point normalize(Point x) {
  return { x[0]/get_length(x), 
           x[1]/get_length(x), 
           x[2]/get_length(x) }; 
}

//calculates cross product of two points
Point cross_product(Point x, Point y) {
  return { x[1]*y[2] - x[2]*y[1],
           x[2]*y[0] - x[0]*y[2],
           x[0]*y[1] - x[1]*y[0]};
}

//calculates length of a point
float get_length(Point x) {
  return sqrt(pow(x[0],2)+pow(x[1],2)+pow(x[2],2));
}
