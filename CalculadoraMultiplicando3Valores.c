#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
	setlocale(LC_ALL,"");
	
	int valor1, valor2, valor3, multiplicado;
	
	printf("\n\tCalculando produtos: \n Digite três valores para multiplicação separados por vírgulas: \n");
	scanf("%d, %d, %d", &valor1, &valor2, &valor3);
	
	multiplicado = valor1 * valor2 * valor3;
	
	printf("O valor da multiplicação é: %d", multiplicado);
}
