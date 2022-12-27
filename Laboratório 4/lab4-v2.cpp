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
class Y : public X {
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

void Y::make_k(void) { k = i * j; } // Atribui um valor a variavel k que esta na classe Y

void Z::f(void) {
  i = 2;// Muda os valor de I que está na classe X
  j = 3; // Muda os valor de J que está na classe X
}

int main() {
  Y var; // Inicia uma variavel VAR com a classe Y
  Z var2; // Inicia uma variavel VAR com a classe X


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

// Resposta questão 4
// Removendo o protected da classe X a função make_k da classe Y
// não vai conseguir acessar os valores de i e j da classe X, pois
// os mesmos agora são privados

/*
Mudando de protected para public, as classes X e Y vai poder acessar e alterar 
diretamente os valores de i e j
*/

// Este arquivo responde das questões 4 a 5 do lab4
