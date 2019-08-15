#include <iostream>
#include <cstdlib>

using namespace std;

struct TipoElemento{
    char nome[20];
    char sobnome[20];
    int idade;
    bool sexo;
    
    TipoElemento *proximo;
};

struct TipoPilha{
    TipoElemento *inicio;
};

void iniciaPilha(TipoPilha &pilha){
    pilha.inicio = NULL;
}

void addPilha(TipoPilha &pilha, TipoElemento elemento){
    TipoElemento *aux = (TipoElemento*) malloc(sizeof(TipoElemento));
    *aux = elemento;
    aux->proximo = pilha.inicio;
    pilha.inicio = aux;
}

void recebeNewElemento(TipoPilha &pilha){
    TipoElemento elemento;
    cout << "---------------------\n" << endl;
    cin.ignore();
    cout << "Digite o nome: "; cin.getline(elemento.nome, 20);
    cout << "Digite o sobre nome: "; cin.getline(elemento.sobnome, 20);
    cout << "Digite a idade: "; cin >> elemento.idade;
    cout << "Digite o sexo [0. Masculino/ 1. Feminino]: "; cin >> elemento.sexo;
    addPilha(pilha, elemento);
}

void viewElemento(TipoElemento elemento){
    cout << "Nome: "; cout << elemento.nome << endl;
    cout << "Sobre nome: "; cout <<elemento.sobnome << endl;
    cout << "Idade: "; cout << elemento.idade << endl;
    if(elemento.sexo)
        cout << "Sexo: Feminino" << endl;
    else
        cout << "Sexo: Masculino" << endl;
}

bool buscaLista(TipoElemento *&p){
    char nome[20];
    cout << "--------------------\n" << endl;
    cin.ignore();
    cout << "Digite o nome a encontrar: "; cin.getline(nome, 20);
    while(p != NULL){
        for(int i=0; i<20; i++){
            if(nome[i] == NULL){
                viewElemento(*p);
                return true;
            }
            if(nome[i] != p->nome[i])
                break;
        }
        p = p->proximo;
    }
    return false;
}

void removerElemento(TipoPilha &pilha){
    TipoElemento *aux = pilha.inicio;
    pilha.inicio = pilha.inicio->proximo;
    free(aux);
}

void mostraAll(TipoPilha &pilha){
    TipoElemento *p = pilha.inicio;
    while(p != NULL){
        cout << "----------------------------" << endl;
        viewElemento(*p);
        p = p->proximo;
    }
}

void menu(){
    system("clear");
    cout << "1) Adicionar registro" << endl;
    cout << "2) Pesquisar registro" << endl;
    cout << "3) Remover registro" << endl;
    cout << "4) Mostrar todos os registros" << endl;
    cout << "0) Sair" << endl;
}

int main() {
    TipoPilha pilha;
    TipoElemento *p;
    iniciaPilha(pilha);
    char r, l;
    do{
        menu();
        cout << "\nOpcao: "; cin >> r;
        system("clear");
        switch(r){
            case '1':
                recebeNewElemento(pilha);
                break;
            case '2':
                p = pilha.inicio;
                buscaLista(p);
                break;
            case '3':
                removerElemento(pilha);
                break;
            case '4':
                mostraAll(pilha);
                break;
            case '0':
                cout << "\nSaindo..." << endl;
                return 0;
            default:
                cout << "\nOpcao invalida!" << endl;
        }
        cout << "\nDigite qualquer coisa para continuar"; cin >> l;
    }while(r != '0');
    return 0;
}
