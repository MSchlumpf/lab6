/* Lab6
 * Euler method (forward and backward)
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main(){
  const double b = -0.5; //lambda
  const int N = 40;	 //number of iterations
  const double dt = 5*(-log(2))/b/(N-1);
  double t = 0, yf = 1, yb = 1, ya = 1, yc = 1;
  
  ofstream out("data.txt");
  out << t << "\t" << yf << "\t" << yb << "\t" << ya << "\t" << yc << endl;
  
  for(int i=1; i<N; i++){
    t = i*dt;
    yf += dt*b*yf;
    yb /= (1-dt*b);
    ya = exp(b*t);
    yc *= (1+dt*0.5*b)/(1-dt*0.5*b);
    out << t << "\t" << yf << "\t" << yb << "\t" << ya << "\t" << yc << endl;
  }
  out.close();
  
  return 0;
}