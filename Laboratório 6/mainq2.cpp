#include <iostream>
using namespace std;

#define MAX 100
#define PI 3.14159

class Shape {
protected:
  int width, height;

public:
  Shape(int a = 0, int b = 0) {
    width = a;
    height = b;
  }
  virtual int area() {
    cout << "Parent class area :" << width * height << endl;
    return width * height;
  }
};

class Rectangle : public Shape {
public:
  Rectangle(int a = 0, int b = 0) : Shape(a, b) {}
  int area() {
    cout << "Rectangle class area :" << width * height << endl;
    return (width * height);
  }
};
class Circle : public Shape {
private:
  int radius;
public:
  Circle(int a = 0, int b = 0,int r = 80) : Shape(a, b) {
    radius = r;
  }
   
  int area() {
    cout << "Circle class area :" << (4 * PI * radius) << endl;
    return (4 * PI * radius);
  }
};
class Square : public Shape {
public:
  Square(int a = 0, int b = 0) : Shape(a, b) {}
  int area() {
    cout << "Square class area :" << (width * height) << endl;
    return (width * height);
  }
};

class Triangle : public Shape {
public:
  Triangle(int a = 0, int b = 0) : Shape(a, b) {}
  int area() {
    cout << "Triangle class area :" << (width * height) / 2 << endl;
    return (width * height / 2);
  }
};

class ListaDeFigurasPolim {
public:
  ListaDeFigurasPolim();
  void add(Shape *f);
  void AreaAll();

private:
  int total;           // total de objetos   armazenados
  Shape *figuras[MAX]; // ponteiros para cada objeto  };
  // Construtor: zera o total de objetos armazenados
};

ListaDeFigurasPolim::ListaDeFigurasPolim() { total = 0; }
// Tenta adicionar um objeto ao vetor de ponteiros
// de objetos. Retorna imediatamente se não houver  espaço
void ListaDeFigurasPolim::add(Shape *f) {
  if (total == MAX)
    return;
  figuras[total++] = f;
}
// Desenha todos os objetos armazenados no vetor
// (ou seja, solicita para cada objeto se desenhar)

void ListaDeFigurasPolim::AreaAll() {
  for (int i = 0; i < total; ++i)
    figuras[i]->area();
}

int main() {
  Shape *shape; // o objeto aponta a classe Shape
  ListaDeFigurasPolim lista;

  shape = new Rectangle(10, 7);
  lista.add(shape);
  shape = new Triangle(10, 5);
  lista.add(shape);
  shape = new Rectangle(2, 4);
  lista.add(shape);
  shape = new Triangle(6, 9);
  lista.add(shape);
  shape = new Circle(10, 10, 80);
  lista.add(shape);
  shape = new Square(40,20);
  lista.add(shape);

  
  lista.AreaAll();
  return 0;
}

/* Retorno
  Rectangle class area :70
  Triangle class area :25
  Rectangle class area :8
  Triangle class area :27
  Circle class area :1005.31
  Square class area :800
*/