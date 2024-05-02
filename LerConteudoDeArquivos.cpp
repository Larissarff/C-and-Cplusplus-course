#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <iostream>
 
using namespace std;
 
int main () {
 
    //Dizer qual arquivo será lido
    ifstream input("Vocabulario.txt");
 
    //String que receberá o texto lido
    string textoLido;
 
    //Passa o texto do arquivo para a string
    for(string line; getline(input, line);){ //Cria uma string de uma linha que vai ler do input(vocabulario)
        textoLido += line;                  // que vai aloca-la na string line. Após isso, se inclui cada linha
    }                                       // da string line na string textoLido, que é onde vamos imprimir.
 
    //Mostrar o conteúdo
    cout << textoLido;
 
    return 0;
}