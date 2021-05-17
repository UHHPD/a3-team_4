#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


using namespace std;

double poisson(double mu, int k){
  return ((pow(mu, k)*exp(-mu))/tgamma(k+1));
}

int main(){
  int n_i;
  double mu = 3.11538;
  int n = 234;
  vector<int> zaehler(11);

  ifstream fin("datensumme.txt");
  ofstream fout("histpoi.txt");

  for(int i = 0 ; i < 234 ; ++i) {
    fin >> n_i;
    zaehler[n_i] += 1;
  }

  for(unsigned int k = 0; k < zaehler.size(); ++ k) {
    fout << k << " " << zaehler[k] << " " << n*poisson(mu, k) << endl;
  }
  fin.close();
  fout.close();
}