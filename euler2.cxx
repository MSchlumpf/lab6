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
  const int N = 1000000;	 //number of iterations
  const double dt = 5*(-log(2))/b/(N-1);	//N-1 steps
  double* y = new double[4*N];	//array for all values of t and y
  y[0] = 0;			//start time
  y[N] = y[2*N] = y[3*N] = 1; 	//initial value y
  
  for(int i=1; i<N; i++){
    y[i] = i*dt;		//Time
    y[N+i] = y[N+i-1]+dt*b*y[N+i-1];		//euler forward
    y[2*N+i] = y[2*N+i-1]/(1-dt*b);	//euler backward
    y[3*N+i] = exp(b*y[i]);	//analytic solution
  }
  ofstream out("data.txt");
  for(int i=0; i<N; i++){
    out << y[i] << "\t" << y[N+i] << "\t" << y[2*N+i] << "\t" << y[3*N+i] << endl;
  }
  delete[] y;
  out.close();
  return 0;
}