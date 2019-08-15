#include <iostream>
#include <cstdlib>

using namespace std;

typedef int tipoChave;

struct tipoRegistro{
    string name;
    tipoChave chave;
};

struct tipoNo{
    tipoRegistro reg;
    *tipoNo esq, dir;
};

void Inserir(tipoNo *no, tipoRegistro x){
    if(*no == NULL){
        *no = (tipoNo) malloc(sizeof(tipoRegistro));
        no->reg = x;
        no->esq = NULL;
        no->reg = NULL;
        return;
    }
    if(x.chave < no->reg.chave){
        Inserir(&no->esq, x);
        return;
    }if(x.chave > no->reg.chave){
        Inserir(&no->dir, x);
    }else
        cout << "Erro: registro ja existente na arvore" << endl;
}

void novoRegistro(tipoNo topo){
    tipoRegistro reg;
    cout << "Digite o nome: ";
    cin >> reg.name;
    cout << "Insira a chave deste registro: ";
    cin >> reg.chave;
    Inserir(topo ,reg);
}

int main()
{
    tipoNo topo = NULL;
    return 0;
}
