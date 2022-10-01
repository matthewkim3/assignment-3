/*
Author:

This file provides a function called inMandelbrotSet which takes two doubles
which together represent a single complex number.  The function returns 1 if
the number is in the Mandelbrot set and 0 otherwise

A complex number, c is in the Mandelbrot set if the sequence:
X(0) = 0
X(n+1) = X(n)*X(n) + c
is unbounded (meaning tends toward infinity)

A complex number, a + ib times another complex number, c + id is equal to
ac + ibc + iad - bd, so (a + ib) * (a + ib) is aa + 2iab - bb = aa - bb + 2iab

We can't always know for sure if its going to infinity, but we do know that
if the real or imaginary part ever have absolute value greater than 2, it will go to infinity,
so if that is ever the case, we return 0.  Otherwise, if we do 100 iterations
and have not yet returned, we return 1.
*/



#include <complex.h>
#include <math.h>

double complex MandelbrotSetGenerator(double a, double b, int n){
  double complex z=0;
  double complex c=a+b*I;
  for(int i=0;i<n;i++){
    
    z=z*z+c;

  }
  //printf("z = %f% + fi\n",creal(z), cimag(z));
  return z;
  
}

int inMandelbrotSet(double a, double b) {
  for(int i=0;i<100;i++){
  if(fabs(creal(MandelbrotSetGenerator(a,b,i)))>2||fabs(cimag(MandelbrotSetGenerator(a,b,i)))>2){
      return 0;
    }
  }
 return 1; 
}
