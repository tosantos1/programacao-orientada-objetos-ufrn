#include <iostream>
#include <vector>
using namespace std;
// criacao da classe fila
class Fila {
  vector<int> q;
  int sloc, rloc;

public:
  Fila(void) {
    rloc = sloc = 0;
    cout << "fila inicializada\n";
  };
  Fila(int r, int s, vector<int> vec) {
    rloc = r;
    sloc = s;
    q = vec;
    cout << "fila inicializada com parametros\n";
  };
  ~Fila(void) { cout << "fila destruida\n"; };
  void qput(int i) {
    ++sloc;
    q.push_back(i);
  }
  Fila operator+(Fila f) const {
    int newrloc = rloc + f.rloc;
    int newsloc = sloc + f.sloc;
    vector<int> newQ(q);
    newQ.insert(newQ.end(), f.q.begin(), f.q.end());
    return Fila(newrloc, newsloc, newQ);
  };
  void operator++() {
    ++sloc;
    q.push_back(rand());
  }
  void operator--() {
    --sloc;
    q.pop_back();
  }

  void imprimir(void) const {
    cout << "Tamanho da fila: " << sloc << "\n";
    cout << "Fila: ";
    for (int i = 0; i < sloc; i++) {
      cout << q[i];
      if (i != sloc - 1) {
        cout << ", ";
      }
    }
    cout << "\n";
  };
  bool isEmpty() {
    if (rloc == sloc) {
      return true;
    }
    return false;
  };
  int qget(void) {
    if (isEmpty()) {
      cout << "fila sem elementos\n";
      return 0;
    }
    ++rloc;
    return q[rloc];
  };
};

int main() {
  Fila a, b(5, 5, {0, 1, 2, 3, 4}), c; // criando três objetos de tipo fila

  a.qput(10);
  b.qput(19);

  a.qput(20);
  --a;
  b.qput(1);

  ++a;
  ++b;

  c = a + b;
  ++c;
  c.imprimir();

  return 0;
}
