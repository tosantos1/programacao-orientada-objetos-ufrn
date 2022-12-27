#include <iostream>
#include <string>

using namespace std;
class base1 {
public:
    base1() {cout << "\n base1 criada\n";}
    ~base1() {cout << "base1 destruida \n\n";}
};
class base2 {
public:s
    base2() {cout << "\n base2 criada\n";}
    ~base2() {cout << "base2 destruida \n\n";}
};
// classe de multiplas bases
class D_class1 : public base1, public base2 {
public:
   D_class1() {cout << "D_class1 criada \n";}
   ~D_class1() {cout << "D_class1 estruida\n";};
};

int main()
{
 D_class1 d1;
 cout << "\n";
 return 0;
}

// Ao criar a variavel d1 com classe D_class1, a classe 
// Base1 vai chamar o construtor e imprimir "base1 criada"
// Depois vai ser chamado a classe Base2 e imprimir "base2 criada"
// E por fim o construtor da D_class1 vai ser executado

// Os destrutores vem na ordem inversa, de D_class1, base2 e base1

/*  resultado
 base1 criada
 base2 criada
 D_class1 criada

 D_class1 destruida
 base2 destruida
 base1 destruida 
 */
