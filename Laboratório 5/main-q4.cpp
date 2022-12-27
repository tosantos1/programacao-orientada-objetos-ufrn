#include <iostream>

using namespace std;

class X {
protected:
  int a; //

public:
  X(void);
  X(int a);
};

class Y {
protected:
  int b;

public:
  Y(void);
  Y(int b);
  Y(int a, int b);
};

// Z herda as duas classes X e Y
class Z : public X, public Y {
public:
  Z(void);
  Z(int a, int b);
  int make_ab(void);
};

X::X(void) {
  a = 10;
  cout << "Inicializando X\n";
}

X::X(int a) {
  a = a;
  cout << "Inicializando X com parametro\n";
}

Y::Y(void) {
  b = 20;
  cout << "Inicializando Y\n";
}

Y::Y(int a) {
  a = a;
  b = 20;
  cout << "Inicializando Y com parametro A\n";
}

Y::Y(int a, int b) {
  b = b;
  a = a;
  cout << "Inicializando Y com parametro A e B\n";
}

Z::Z(void) { cout << "Inicializando Z\n"; }
Z::Z(int a, int b) {
  X::a = a;
  Y::b = b;
  cout << "Inicializando Z com parametro A e B\n";
}

int Z::make_ab(void) { return a * b; }
// int Z::make_ab(int a, int b) { return a * b; }

int main() {
  Z i; // Inicia variavel i com Classe Z, que herda as classes X e Y sem parametros
  cout << i.make_ab(); //Imprime a multiplicação de A x B = 200
  cout << "\n";
  Z i_p(20, 30); // Inicia variavel i_p com Classe Z, que herda as classes X e Y com parametros
  cout << i_p.make_ab(); // Imprime a multiplicação de A x B = 600
  return 0;
}

// resultado:
// Inicializando X
// Inicializando Y
// Inicializando Z
// 200

// Inicializando X
// Inicializando Y
// Inicializando Z com parametro A e B
// 600