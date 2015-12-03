///////////////////////////////////
//  Christian Greb	2030036  //
//  Homework6	Lorenz model     //
///////////////////////////////////

#include<fstream>
#include<cmath>
#include<iostream>

using namespace std;

void func(double x, double y, double z, double* ki);

int main(){
  const int N = 10000;
  const double tstart = 0, tende = 100, T = tende-tstart, dt = T/N;
  double x = 1, y = 2, z = 3;
  double k1[3], k2[3], k3[3], k4[3];
  
  ofstream out("data.txt");
  out << 0 << "\t" << x << "\t" << y << "\t" << z << endl;
  
  for(int i=1; i<N+1; i++){
    func(x,y,z,k1);   
    func(x+dt/2*k1[0],y+dt/2*k1[1],z+dt/2*k1[3],k2);
    func(x+dt/2*k2[0],y+dt/2*k2[1],z+dt/2*k2[3],k3);
    func(x+dt*k3[0],y+dt*k3[1],z+dt*k3[3],k4);
    
    x += dt/6*(k1[0]+2*k2[0]+2*k3[0]+k4[0]);
    y += dt/6*(k1[1]+2*k2[1]+2*k3[1]+k4[1]);
    z += dt/6*(k1[2]+2*k2[2]+2*k3[2]+k4[2]);
    
    out << i*dt << "\t" << x << "\t" << y << "\t" << z << endl;
  }
  out.close();
  return 0;
}

void func(double x, double y, double z, double* ki){
  const double a = 10, b = 28, c = 8/3;
  ki[0] = a*(y-x);
  ki[1] = x*(b-z)-y;
  ki[2] = x*y-c*z;
}