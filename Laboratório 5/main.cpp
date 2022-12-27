#include <iostream>

using namespace std;

class base { // É criada uma classe Base
public:
  base() { cout << "\n base criada\n"; }
  ~base() { cout << "base destruida \n\n"; }
};

class D_class1 : public base { // D_class1 vai herdar os metodos da classe base
public:
  D_class1() { cout << "D_class1 criada \n"; }
  ~D_class1() { cout << "D_class1 destruida\n"; };
};

class D_class2 : public D_class1 { // D_class2 vai herdar tanto os metodos de d_class1 e da classe base
public:
  D_class2() { cout << "D_class2 criada \n"; }
  ~D_class2() { cout << "D_class2 destruida\n"; };
};

int main() {
  D_class1 d1; // Vai executar o construtor da classe Base e d_class1
  D_class2 d2; // Vai executar o construtor da classe Base e d_class1 e d_class2
  cout << "\n";
  return 0;
}


//Após a criação de uma classe derivada, esta tem acesso a todos os dados públicos da classe base. Todos os métodos declarados como públicos da classe base estão automaticamente disponíveis para a classe derivada. 
// Se uma classe derivada quiser acessar os dados privados da classe base não terá acesso. Para possibilitar este acesso, os dados privados na classe base devem ser declarados como protegidos. 