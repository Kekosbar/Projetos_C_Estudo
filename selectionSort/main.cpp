#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void random(int vet[], int tam){
    srand((unsigned) time(NULL));
    for(int i=0; i<tam; i++)
        vet[i] = rand() % 10;
}

void selectionSort(int vet[], int tam){
    int min, aux;
    for(int i=0; i<tam-1; i++){
        min = i;
        for(int j=i+1; j<tam; j++){
            if(vet[j] < vet[min])
                min = j;
        }
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}

void imprimir(int vet[], int tam){
    for(int i=0; i<tam; i++){
        cout << vet[i] << endl;
    }
}

int PesquisaBinaria (int vet[], int chave, int Tam){
     int inf = 0;     // limite inferior (o primeiro índice de vetor em C é zero          )
     int sup = Tam-1; // limite superior (termina em um número a menos. 0 a 9 são 10 números)
     int meio;
     while (inf <= sup)
     {
          meio = (inf + sup)/2;
          if (chave == vet[meio])
               return meio;
          if (chave < vet[meio])
               sup = meio-1;
          else
               inf = meio+1;
     }
     return -1;   // não encontrado
}

int buscaSequencial (int x, int n, int v[]) {
   int m = 0;
   while (/*A*/ m < n && v[m] < x) 
      ++m;
   if (m < n && v[m] == x) 
      return m;
   else 
      return -1;
}

int main() {
    const int tam = 10;
    //int vet[tam] = {0,1,2,3,4,5,6,7,8,9};
    int vet[tam];
    random(vet, tam);
    imprimir(vet, tam);
    cout << endl;
    cout << PesquisaBinaria(vet, 5, tam) << endl;
    cout << endl;
    selectionSort(vet, tam);
    imprimir(vet, tam);
    cout << endl;
    cout << PesquisaBinaria(vet, 5, tam) << endl;
    cout << endl;
    return 0;
}

int teste(int vet[], int chave, int tam){
    int meio;
    int inf = 0;
    int sup = tam-1;
    while(inf <= sup){
        meio = (inf + sup)/2;
        if(chave == vet[meio])
            return meio;
        if(chave < vet[meio])
            sup = meio-1;
        else
            inf = meio+1;
    }
    return -1;
}
