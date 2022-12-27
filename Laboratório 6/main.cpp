#include <iostream>
using namespace std;

int add(int n1, int n2) { return n1 + n2; }
double add(double num1, double num2) { return num1 + num2; }
int add(int n1, int n2, int n3) { return n1 + n2 + n3; }
int main() {
  // Chamando função com 2 parâmetros int
  cout << "Result 1=" << add(15, 15)
       << endl; // Chamando função com 2 parâmetros duplos
  cout << "Result 2=" << add(40.0, 31.1)
       << endl; // Chamando função com 3 parâmetros int
  cout << "Result 3=" << add(30, 30, 20);
}
