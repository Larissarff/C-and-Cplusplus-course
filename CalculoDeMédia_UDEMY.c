#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
	setlocale(LC_ALL, ""); //Autoriza acentos em portugues.
	
	float Nota1;
	float Nota2; //Definindo variáveis.
	
	printf("\n\tCálculo de Média: \nInsira sua nota da prova 1: \n"); //Instrução para usuário.
	scanf("%f", &Nota1); //Redefinindo o valor da Nota1
	
	printf("\nInsira a nota da prova 2: \n"); //Instrução para usuário.
	scanf("%f", &Nota2); //Redefinindo o valor da Nota1
	
	printf("A média das Notas 1: %.2f e Nota 2: %.2f é: %.2f", Nota1, Nota2, (Nota1 + Nota2)/2); //Instrução para usuário e calculo da média.
	system("pause"); // permite que o usuário tenha tempo pra ler o resultado.
}
