#include <iostream>
using namespace std;
class A {
public:
  void display() { cout << "This is from the base class function." << endl; }
};
class B : public A {
public:
  void display() { // redefine função membro da classe base
    cout << "This is from the derived class function. " << endl;
  }
};
int main() {
  B obj;
  // Chamando a função display() da classe derivada
  obj.display();
  return 0;
}
