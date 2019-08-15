#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

int const VERTICES = 6; // Total de vertices no grafo
int const GRAFO[VERTICES][VERTICES] =  {0,4,10,6,0,0,
                                        0,0,4,0,8,0,
                                        0,0,0,5,0,7,
                                        0,0,0,0,0,10,
                                        0,0,0,0,0,5};

struct Aresta{
    int v; // Vertice v
    int u; // Vertice u
    int peso; // Peso w da aresta a
    
    string toString(){
        return v +" - "+u;
    }
};

// Lista com todas as arestas possíveis para solução
list<Aresta> arestas_possiveis;

void inicia_arestas_pssiveis(){
    for(int i=0; i<VERTICES; i++){
        for(int j=0; j<VERTICES; j++){
            
        }
    }
}

struct Individuo{
    Aresta c[VERTICES]; // Caracteristicas do individuo, rota para solução
    int peso=0; // Somatório final do peso w de cada aresta, w[A]
    
    void nasce_aleatorio(){
        for(int i=0; i<VERTICES-1; i++){
            list<int> adj; // lista de vertices adjacentes
            for(int j=i; j<VERTICES; j++){
                if(GRAFO[i][j] != 0) // Não permite arestas inexistente
                    adj.push_front(j);
            }
            list<int>::iterator it = adj.begin();
            int posj = rand() % adj.size();
            advance(it, posj);
            c[i].v = i;
            c[i].u = *it;
            c[i].peso = GRAFO[i][*it];
        }
        // Sorteia uma aresta de retorno qualquer
        while(true){
            int i = rand() % VERTICES;// sorteia i
            int opc = VERTICES - i;
            int j = (rand() % opc) + i+1;// sorteia j
            if (GRAFO[i][j] != 0) {
                c[i].v = i;
                c[i].u = j;
                c[i].peso = GRAFO[i][j];
                break;
            }
        }
    }
    
    void calcula_pesoFinal(){
        peso = 0;
        for(int i=0; i<VERTICES; i++){
            peso += c[i].peso;
        }
    }
    
    string toString(){
        string s = "Individuo: {";
        for(int i=0; i<VERTICES; i++)
            s += c[i].toString()+" | ";
        s += "} peso: ";
        return s;
    }
};

int main() {
    srand (time(NULL));
    Individuo id;
    id.nasce_aleatorio();
    cout << "passou aleatorio\n";
    id.calcula_pesoFinal();
    cout << "passou calculo\n";
    cout << id.toString() << endl;
    cout << id.c[0].toString() << endl;
    cout << id.c[1].toString() << endl;
    cout << id.c[1].v << endl;
    cout << id.c[1].u << endl;
    return 0;
}

