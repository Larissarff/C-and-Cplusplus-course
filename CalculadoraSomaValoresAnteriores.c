#include <stdio.h>
#include <stdlib.h>

int main(){
	int soma;     /* criando a variavel soma que vai guardar os valores da soma*/
	int i;        /* criando uma variavel que assuma o valor de 1 para fazer a restrição */
	int numero;   /* criando uma variavel que vai guardar o numero a ser digitado pelo usuario */
	soma = 0;     /* Atribuindo valor a soma */
	i = 1;        /* Atribuindo valor a i */  /* lembrando que o usuario que vai atribuir valor ao numero, por isso nao é declarado aqui */
	
	printf("\n\tCalculo da soma dos n primeiros inteiros positivos:\n");  /* formato de \n\t que faz o titulo ser centralizado */
	scanf("%d", &numero);  /* formato de scanf que delimita o formato do dado a ser armazenado, e indica a variavel a ser armazenada com &variavel  */
	
	while (i <= numero) {   /* while, função que atribui verdadeiro ou falso */
    soma = soma + i;       /* nova atribuição da variavel soma, fazendo a soma */
    i = i + 1;             /* nova atribuição da variavel i, fazendo a soma */
    }
    printf("A soma dos %d primeiros inteiros positivos e' %d\n", numero, soma);  /* formato do printf com ( %d %d, variavel1, variavel2 )/* nova atribuição da variavel soma, fazendo a soma */ 
  
  return 0;
}
