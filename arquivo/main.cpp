#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main()
{
    //declaracao dos streams de entradaesaida

    cout << "Escrever no arquivo: ";
    char r[1];
    gets(r);
    if(r[0] == 's'){
        ofstream arquivo;
        arquivo.open("d:\\testes.txt", ios::app);
        cout << "Digite: ";
        char ff[100];
        gets(ff);
        arquivo << ff << endl;
        arquivo.close();
    }
    ifstream arquivo;
    arquivo.open("d:\\testes.txt", ios::in);
    if(arquivo.is_open()){
        cout << "\nLendo arquivo:\n" << endl;
        string linha;
        char c[100];
        while(!arquivo.eof()){
            arquivo.getline(c,100);
            cout << c << endl;
        }
        arquivo.close();
    }
    return 0;
}
