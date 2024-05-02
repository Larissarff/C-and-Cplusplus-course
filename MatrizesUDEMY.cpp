#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	
	setlocale(LC_ALL,"");
	
	int matriz[2][2], i, j;
	int a = 0, b = 0;
	
	printf("\n\t Digite valores para uma matriz 2x2: \n");
	
	printf("\n Digite o valor [0,0] para uma matriz 2x2: \n");
	scanf("\n%d", &matriz[0][0]);
	printf("\n Digite o valor [0,1] para uma matriz 2x2: \n");
	scanf("\n%d", &matriz[0][1]);
	printf("\n Digite o valor [1,0] para uma matriz 2x2: \n");
	scanf("\n%d", &matriz[1][0]);
	printf("\n Digite o valor [1,1] para uma matriz 2x2: \n");
	scanf("\n%d", &matriz[1][1]);
	
	a = matriz[0][0];
	b = matriz[0][1];
	
	matriz[0][0] = matriz[1] [0];
	matriz[0][1] = matriz[1][1];
	matriz[1][0] = a;
	matriz[1][1] = b;
	
	printf("\n\t Matriz Invertida: \n");
	printf(" \n %d %d ", matriz[0][0], matriz[0][1]);
	printf(" \n %d %d ", matriz[1][0], matriz[1][1]);
	
}
	
