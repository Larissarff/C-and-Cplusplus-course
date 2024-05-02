#include <stdio.h>

int contador (int i){
	for (i=0;i<100;i++){
		printf("%d \n", i);
	}
}

int somarAteCem (int j){
	int soma;
	for (j=0;j<100;j++){
		soma = soma + j;
	}	
	printf("\n A soma de todos os numeros anteriores eh: %d ", soma);
}
