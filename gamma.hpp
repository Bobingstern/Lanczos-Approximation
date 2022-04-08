double gammaP[] = {
  676.5203681218851
    ,-1259.1392167224028
    ,771.32342877765313
    ,-176.61502916214059
    ,12.507343278686905
    ,-0.13857109526572012
    ,9.9843695780195716e-6
    ,1.5056327351493116e-7
};
int gammaLen = sizeof(gammaP)/sizeof(gammaP[0]);

std::complex<double> gamma(std::complex<double> n){
  //Reflection formula
  if (real(n) < 0.5f){
    std::complex<double> t(1-real(n), -imag(n));
    std::complex<double> r(M_PI*real(n), M_PI*imag(n));
    std::complex<double> y(M_PI,0);
    return y / sin(r) / gamma(t);
  }
  n = std::complex<double>(real(n)-1, imag(n));
  
  std::complex<double> x(1, 0);
  for (int i=0;i<gammaLen;++i){
    std::complex<double> gammaPval(gammaP[i], 0);
    std::complex<double> dummy(i+1, 0);
    x += gammaPval / (n+dummy);
    
  }
  
  std::complex<double> t(real(n) + gammaLen - 0.5, imag(n));
  std::complex<double> half(0.5, 0);
  std::complex<double> t2q(sqrt(2*M_PI), 0);
  std::complex<double> tpow = pow(t, n+half);
  std::complex<double> neg(-real(t), -imag(t));
  std::complex<double> expt = exp(neg);
  return x * t2q * tpow * expt;
}
