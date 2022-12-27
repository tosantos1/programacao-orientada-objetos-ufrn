#include <iostream>

using namespace std;

class X {
// protected:
public:
  int i;
  int j;

public:
  void get_ij(void);
  void put_ij(void);
};

// Em Y, i e j  de X tornam-se membros protected.
class Y : private X {
  int k; // privado
public:
  int get_k(void);
  void make_k(void);
};

// Em Y, i e j  de X tornam-se membros protected.
class Y_private : public X {
public:
  int k; // privado
public:
  int get_k(void);
  void make_k(void);
};

// Z tem acesso a i e j de X, mas nao a
// k de Y, ja que ele é privado por definicao
class Z : public Y {
public:
  void f(void); // Definição da função f publica
};

void X::get_ij(void) {
  cout << "Informe dois numeros: "; // Imprime na tela uma mensagem
  cin >> i >> j; // Recebe os valores de i e j
}

void X::put_ij(void) { cout << i << " " << j << "\n"; } // Mostra os valores de i e j

int Y::get_k(void) { return k; } // Retorna K

void Y::make_k(void) { k = i * j; put_ij(); } // Atribui um valor a variavel k que esta na classe Y

int Y_private::get_k(void) { return k; } // Retorna K

void Y_private::make_k(void) { k = i * j; } // Atribui um valor a variavel k que esta na classe Y


void Z::f(void) {
  i = 2;// Muda os valor de I que está na classe X
  j = 3; // Muda os valor de J que está na classe X
}

int main() {
  Y var; // Inicia uma variavel VAR com a classe Y
  Z var2; // Inicia uma variavel VAR com a classe X

  var.k = 10; // Se as variaveis forem protected, não conseguiremos atualizar fora da classe.
  Y_private var3;
  var3.k = 10; // Já ser for public, será possivel atualizar;

  var.get_ij(); // Vai usar o metodo definido em X para receber i e j
  var2.i = 10; // Agora que o i e j está public, consegue mudar diretamente
  var2.j = 5;
  var.put_ij(); // Mostrar os valores de i e j
  var.make_k(); // Vai usar o metodo definido em Y para definir o valor de k = i * j
  cout << var.get_k(); // Mostra o valor em K
  cout << "\n"; // Vai quebrar linha

  var2.f(); // Muda os valores de i e j
  var2.put_ij(); // Imprime na tela os valores de i e j

  return 0;
}

// resultado:
// Informe dois numeros: 5 10
// 5 10
// 50
// 2 3


// Herança esquema final
// X => Y => Z

// Resposta questão 6
// Colocando o Y como protected, os metodos de X só vão ser acessados dentro das classes filhas. Não vão conseguir acessar fora da classe.
// Já colocando a herança X na classe Y como private, as classes filhas
// não conseguirão acessar nenhum metodo de X

