#include <iostream>
#include <string>

using namespace std;
const int TAM = 80;

class BasAg {
protected:
  string nome;
  string numag;

public:
  BasAg() {
    nome = '\0';
    numag = '\0';
  }
  BasAg(string n, string ng) {
    nome =n;
    numag=ng;
  }
  void print() {
    cout << nome << '\n';
  }
};

class Agente : public BasAg // herança ou classe derivada
{
protected:
  float altura;
  int idade;

public:
  Agente() : BasAg() {
    altura = 0;
    idade = 0;
  }
  Agente(string n, string ng, float a, int i) : BasAg(n, ng) {
    altura = a;  
    idade = i;
  }
  void print(){
    cout << idade << endl;
  }
};

int main() {
  Agente agente("Daniel", "1", 1.78, 21);
  agente.BasAg::print();
  agente.print();
  
  return 0;
}

