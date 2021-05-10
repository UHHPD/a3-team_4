#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

double poisson(double mu, int k) {
  return ((pow(mu, k)*exp(-mu))/tgamma(k+1));
}

double prob(vector<int> daten, double mu){
  double result = 1;
  for(int k : daten){
    result *= poisson(mu, k);
  }
  return result;
}

double prob_n(vector<int> daten){
  double result = 1;
  for(int k : daten){
    result *= poisson(k, k);
  }
  return result;
}


int main() {
  vector<int> daten;
  vector<double> space;
  double mu_1 = 3.11538;
  int n_i;
  int n = 233;
  
  ifstream fin("datensumme.txt");
  ofstream fout1("likelihood.txt");
  ofstream fout2("nll.txt");
  ofstream fout3("deltanll.txt");

  for(int i = 0 ; i < 234 ; ++i) {
    fin >> n_i;
    daten.push_back(n_i);
  }

  for(double mu = 0; mu <= 6; mu += 0.1){
    fout1 << mu << " " << prob(daten, mu) << endl;
    fout2 << mu << " " << -2*log(prob(daten, mu)) << endl;
    double res = -2*log(prob(daten, mu))+2*log(prob(daten, mu_1));
    fout3 << mu << " " << res << endl;
    if(res < 1){
      space.push_back(mu); //Wertebereich für die besten Schätzwerte von mu.
    }
  }

  double a = (prob(daten, mu_1))/(prob_n(daten));

  double z = ((-2*log(a)-n)/(sqrt(2*n)));

  cout << a << "" << z << endl;

  fin.close();
  fout1.close();
  fout2.close();
  fout3.close();
}
