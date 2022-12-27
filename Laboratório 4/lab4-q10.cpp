class Cadastro {
private:
  char nome[30], fone[20];

public:
  Cadastro();
  void getdata();
  void putdata();
};

class Imovel {
private:
  char end[30], bairro[20];
  float AreaUtil, AreaTotal;
  int quartos;

public:
  Imovel();
  void getdata();
  void putdata();
};
class Tipo {
private:
  char tipo[20]; // Residencial, Loja, Galpão...
public:
  Tipo();
  void getdata();
  void putdata();
};

class Venda : private Cadastro, Imovel, Tipo {
private:
  float valor;

public:
  Venda() : Cadastro(), Imovel(), Tipo();
  void getdata();
  void putdata();
};

int main(){
  
}