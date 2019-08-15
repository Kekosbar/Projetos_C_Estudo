#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <list>

using namespace std;

struct TipoVertice {
    char vet;
    list <TipoVertice*> lista_adj; // Lista de ponteiros com os vertices adjacentes
};
// Struct abaixo usada na Arvore geradora minima
struct TipoAresta{
    TipoVertice *u;
    TipoVertice *v;
};

struct TipoGrafo {
    list <TipoVertice> lista_vertices; // Lista com todos os vertices do grafo
    list <TipoAresta> lista_aresta; // Lista com arestas e peso, para função Arvore minima
private:
    // Procure pelo vertice para evitar a inseção de vertices repitidos
    bool pesquisaListaVertices(char v, list <TipoVertice>::iterator &it) {
        it = lista_vertices.begin();
        int tam = lista_vertices.size();
        for(int i=0; i<tam; i++){
            if (it->vet == v) return true;
            it++;
        }
        return false;
    }
};

void inicializa(char mat[3][3], char vet[9]){
    int x = 8;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int al = rand()%(x+1);
            mat[i][j] = vet[al];
            vet[al] = vet[x--];
        }
    }
}

void quadro(char mat[3][3]){
    for(int i=0; i<3; i++){
        cout << "-------------" << endl;
        for(int j=0; j<3; j++){
            cout << "| " << mat[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "-------------" << endl;
}


    
int main() {
    srand((unsigned)time(0));
    char mat[3][3];
    char vet[9]= {'1','2','3','4','5','6','7','8',' '};
    inicializa(mat, vet);
    cout << endl;
    quadro(mat);
    return 0;
}

