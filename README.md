# Lanczos-Approximation
Lanczos Gamma Function Approximation in c++ for all real and complex numbers

```c++
#include <iostream>
#include <complex.h>
#include <math.h>
#include "gamma.hpp"


int main() {
  //Works with
  //x! = gamma(x+1)
  std::complex<double> s(1.5, 0); //0.5! = sqrt(pi)/2 ~= 0.88622
  std::cout << gamma(s); //A complex number
}
```
