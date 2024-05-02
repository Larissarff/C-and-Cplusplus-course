	
#include <stdio.h>
#include <stdlib.h>


// int* pois é uma função que retorna um ponteiro
int* alocaVetor(int tamanho){
	
	//Criando um ponteiro auxiliar
	int *aux;
	
	//Alocação dinâmica de memória
	aux = (int*) malloc(tamanho * sizeof(int));
	// sizeof(int) => o tamanho de um dígito do tipo int
	
	if (aux == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1); // Encerra o programa em caso de erro
    }
    
	//Retorna o ponteiro que aponta para a pimeira posição do vetor alocado
	return aux;
}

int main(){
	// Definindo variáveis
	int *vetor, tamanho;
	
	//Lendo o tamanho do vetor
	printf("\n\t Digite um tamanho para o vetor: \n");
	scanf("%d", &tamanho);
	
	vetor = alocaVetor(tamanho);
	
	 for(int cont = 0; cont < tamanho; cont++)
        printf("%d\n", vetor[cont]);
		
	free(vetor);
	
	return 0;
}
