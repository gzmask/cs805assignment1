#include "util.h"
#include <math.h>

UVN get_uvn(Point V1, Point V2) {

  //get n, which is just normalized V1
  Point n = { V1[0]/get_length(V1), 
              V1[1]/get_length(V1), 
              V1[2]/get_length(V1) }; 


  //get u, which is normalized V2 x V1
  Point u_ = { V2[1]*V1[2] - V2[2]*V1[1],
              V2[2]*V1[0] - V2[0]*V1[2],
              V2[0]*V1[1] - V2[1]*V1[0]};
  Point u = { (V2[1]*V1[2] - V2[2]*V1[1])/get_length(u_),
              (V2[2]*V1[0] - V2[0]*V1[2])/get_length(u_),
              (V2[0]*V1[1] - V2[1]*V1[0])/get_length(u_)};

  //get v, which is n x u
  Point v_ = { n[1]*u[2] - n[2]*u[1],
              n[2]*u[0] - n[0]*u[2],
              n[0]*u[1] - n[1]*u[0]};
  Point v = { (n[1]*u[2] - n[2]*u[1])/get_length(v_),
              (n[2]*u[0] - n[0]*u[2])/get_length(v_),
              (n[0]*u[1] - n[1]*u[0])/get_length(v_)};

  UVN result_uvn = {u, v, n};
  return result_uvn;
}

float get_length(Point X) {
  return abs(sqrt(pow(X[0],2)+pow(X[1],2)+pow(X[2],2)));
}
