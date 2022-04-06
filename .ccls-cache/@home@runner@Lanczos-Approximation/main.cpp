#include <iostream>
#include <complex.h>
#include <math.h>
#include "gamma.hpp"


int main() {
  //x! = gamma(x+1)
  std::complex<double> s(1.5, 0); //0.5! = sqrt(pi)/2 ~= 0.88622
  std::cout << gamma(s);
}