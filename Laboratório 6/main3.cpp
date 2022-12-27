#include <iostream>
using namespace std;

class A {
public: // define função como virtual
  virtual void display() { // tirar o virtual, o display vai exibir o da classe A, com virtual mostra o da classe B;
    cout << "This is from the base class function." << endl;
  }
};

class B : public A {
public:
  void display() {
    cout << "This is from the derived class function. " << endl;
  }
};

int main() {
  B obj1;
  A *obj2 = &obj1;  // ponteiro do tipo A que aponta para obj1
  obj2->display(); // chama a função membro da classe B
  return 0;
}
