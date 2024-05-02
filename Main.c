#include <stdio.h>
#include <stdlib.h>
#include "funcions.h"

void main(){
	
	int a;
	
	printf("\n\t Insira um valor de 0 - 10 ");
	scanf("%d", &a);
	
	contador(a);
	somarAteCem(a);
	
}
