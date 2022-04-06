double gammaG = 4.7421875;
double gammaP[] = {
  0.99999999999999709182,
  57.156235665862923517,
  -59.597960355475491248,
  14.136097974741747174,
  -0.49191381609762019978,
  0.33994649984811888699e-4,
  0.46523628927048575665e-4,
  -0.98374475304879564677e-4,
  0.15808870322491248884e-3,
  -0.21026444172410488319e-3,
  0.21743961811521264320e-3,
  -0.16431810653676389022e-3,
  0.84418223983852743293e-4,
  -0.26190838401581408670e-4,
  0.36899182659531622704e-5
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
  
  std::complex<double> x(gammaP[0], 0);
  for (int i=1;i<gammaLen;++i){
    std::complex<double> gammaPval(gammaP[i], 0);
    std::complex<double> dummy(i, 0);
    x += gammaPval / (n+dummy);
  }
  std::complex<double> t(real(n) + gammaG + 0.5, imag(n));
  std::complex<double> half(0.5, 0);
  std::complex<double> t2q(sqrt(2*M_PI), 0);
  std::complex<double> tpow = pow(t, n+half);
  std::complex<double> neg(-real(t), -imag(t));
  std::complex<double> expt = exp(neg);

  return x * t2q * tpow * expt;
}