#include <stdio.h>
#define TAM 10

//Funcao que imprime um vetor
int imprime_vetor(int vetor[]){
    printf("\n");
    for(int i = 0; i<TAM; i++){
        printf(" | %d |", vetor[i]);
    }
}

//funcao que faz o tipo de busca binaria:
int Busca_binaria(int vetor[], int inicio, int fim, int valor_procurado){
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == valor_procurado) {
            return meio;
        } else if (vetor[meio] > valor_procurado) {
            return Busca_binaria(vetor, inicio, meio - 1, valor_procurado);
        } else {
            return Busca_binaria(vetor, meio + 1, fim, valor_procurado);
        }
    }
    // Caso o valor não seja encontrado, retornar -1
    return -1;
}



int main(){
    int vetor [TAM] = {3,4,5,6,7,8,9,10,11,12}; //criando um vetor ordenado hipotético (PRECISA SER ORDENADO)
    int inicio, fim, valor_procurado;

    printf("\tQual valor deseja encontrar na lista?"); //Lendo o valor procurado
    scanf("%d", &valor_procurado);

    inicio = 0;
    fim = TAM-1;
    //Aplica a função da busca binária e seus parametros
    int resultado =Busca_binaria(vetor, inicio, fim, valor_procurado); 

    if(resultado == -1){
        printf("Valor nao encontrado");
        imprime_vetor(vetor);
    } else{
        printf("O valor foi encontrado na posição %d\n", resultado);
    }
    
}
//Vantagens da busca binária: diminui a complexidade do código usando recursão
    