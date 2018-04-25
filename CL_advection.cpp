#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

// inicializacion de las funciones

void in(double *u, double xmin, double deltax, int n, double sigma, double media);
void im(double *u, double xmin, double deltax, int n, double t);
void der(double *u, double *uv, int n, double deltax, double deltat, double C);
void cop(double *u, double *uv, int n);

//funcion que define el valor de u dependiendo de las condiciones iniciales

void in(double *u, double xmin, double deltax, int n){
  int i;
  double x;
  double abso = abs(0.5);
  for(i=0;i<n;i++){
    x = xmin +  i * deltax;
    if(x<=abso){
      u[i] = 0.5;
    }else{
      u[i] = 0.0;
    }
  }
}
//funcion que imprime
void im(double *u, double xmin, double deltax, int n, double t){
  double x;
  int i;
  for(i=0;i<n;i++){
    x = xmin +  i * deltax;
    cout << t << " " << x << " " << u[i] << endl;
  }
}
// funcion que deriva
void der(double *u, double *uv, int n, double deltax, double deltat, double C){
  int j;
  for(j=1; j<n-1; ++j){
     u[j] = uv[j]-C*deltat*(uv[j+1]-uv[j])/deltax;
  }
}
void cop(double *u, double *uv, int n){
  int i;
  for(i=0;i<n;i++){
    u[i] = uv[i];
  }
}
// main para correr el codigo
int main(){
  double C = 1.0;
  double T = 0.5;
  double t = 0.0;
  double x = 3.0;
  double deltax = 0.01;
  double deltat = 0.001;
  double *u;
  double *uv;
  double *ui;
  double xmin = 0.0;
  double xmax = 2.0;
  int numerox = (xmax-xmin)/(deltax+1);
  uv = new double[numerox];
  u = new double[numerox];
  in(uv, xmin, deltax, numerox);
  im(uv, xmin, deltax, numerox, t);
  while(T>t){
    der(u, uv, numerox, deltax, deltat, C);
    cop(uv, u, numerox);
    t += deltat;
  }
  im(uv, xmin, deltax, numerox, t);

  return 0;
}
