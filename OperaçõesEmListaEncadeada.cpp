#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>

using namespace std; //para utilizar cout

//Struct para pessoa
//lista encadeada
struct pessoa{
    string nome;
    int rg;
    //ponteiro para a proxima estrutrura
    struct pessoa *proximo;
};

//Limpa a tela
void limpatela(){
    system("CLS");
}

//Conta quantos elementos tem na lista
int retornaTamanhoListaEncadeada(pessoa *ponteiroEncadeada){

   //Tamanho da lista
   int tamanho = 0;

   //Ponteiro auxiliar para percorrer a lista
   pessoa *p = ponteiroEncadeada;

   while(p != NULL){

       //Transforma o P no endereco do proximo valor, Caso o endereco seja NULL, estamos no fim da lista
        p = p->proximo;

        //Contador de tamanho da lista
        tamanho++;
   }

   return tamanho;

}

//Imprime a lista encadeada
void imprimeEncadeada(pessoa *ponteiroEncadeada) {

   //Cabeaalho da Lista
   //cout << "Lista(Tamanho:"<< retornaTamanhoListaEncadeada(*ponteiroEncadeada) << ")\n";

   //Ponteiro auxiliar para percorrer a lista
   pessoa *p = ponteiroEncadeada;

   //Mostra a posicao do elemento
   int posicao = 0;

   //Enquanto o p nao for nulo
   while(p != NULL){

        //Imprime o valor da lista
        cout << posicao << " - " << p->nome << ", " << p->rg << "\n";

        //Transforma o P no endereco do proximo valor, Caso o endereco seja NULL, estamos no fim da lista
        p = p->proximo;

        //Incrementa a variavel da posicao dos elementos
        posicao++;
   }

   //Libera Memoria
   free(p);

}

//Adiciona um elemento ao come�o
void adcComecoEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg){

    //Cria uma nova estrutura
    pessoa *novovalor = new pessoa;
    novovalor->nome = nome;
    novovalor->rg = rg;
    novovalor->proximo = ponteiroEncadeada;

    //Redireciona o ponteiro
    ponteiroEncadeada = novovalor;

}

//Adiciona um elemento ao fim
void adcFimEncadeada(pessoa *ponteiroEncadeada, string nome, int rg){

    //Cria um novo valor
    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    //Cria um cursor que percorre a lista
    pessoa *p = ponteiroEncadeada;

        //Enquanto o p nao for nulo
        while(p != NULL){

            //Se estiver no ultimo elemento
            if(p->proximo == NULL){

                //Faz ele acrescentar o novo valor e sair do while
                p->proximo = novoValor;
                return;
            }

            //Transforma o P no endereco do proximo valor
            //Caso o endereco seja NULL, estamos no fim da lista
            //E saimos do while
            p = p->proximo;

        }

    //Libera Memoria
    free(p);
    free(novoValor);

}

//Adiciona valor numa posicao especifica
void adcPosicaoEncadeada(pessoa *ponteiroEncadeada,string nome,int rg, int posicao){

    //Criar NODE com um valor
    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    //Ponteiro Auxiliar
    pessoa *p = ponteiroEncadeada;

    //Variavel que percorre a lista
    int i = 0;

    //Criar o auxiliar para Salvar o endereco em K-1 ->proximo
    while(i <= posicao){

        if(i == posicao-1){

            //Auxiliar do valor
            pessoa *aux = new pessoa;

            //Precisamos armazenar o endereco a ser apontado pelo novo node
            aux->proximo = p->proximo;

            //Fazendo o elemento K-1 apontar para o novo NODE
            p->proximo = novoValor;

            //Fazendo o novo NODE apontar para a auxiliar
            novoValor->proximo = aux->proximo;

            //Libera a Memoria
            free(aux);

        }

        //Analisa o proximo membro da lista
        p = p->proximo;

        //Contador de posi��es
        i++;

    }

}

//Remove o elemento inicial
void removeInicioEncadeada(pessoa *&ponteiroEncadeada, string *nome, int *rg){

    //Retorna o nome do removido
    *nome = ponteiroEncadeada->nome;
    *rg = ponteiroEncadeada->rg;

    //O ponteiroEncadeada recebe o endere�o do proximo elemento,Agora o segundo elemento torna-se o ponteiroEncadeada
    ponteiroEncadeada=ponteiroEncadeada->proximo;

}

//Remove do final da lista
void removeFinalEncadeada(pessoa *&ponteiroEncadeada, string *nome, int *rg){

    //Auxiliares
    pessoa *p = new pessoa;
    pessoa *aux = new pessoa;

    //Se houver apenas um elemento na lista
    if(ponteiroEncadeada->proximo == NULL){

        //Recupera o nome e rg de quem saiu
        *nome = ponteiroEncadeada->nome;
        *rg = ponteiroEncadeada->rg;

        //Libera a Memoria do unico elemento e o deixa nulo
        free(ponteiroEncadeada);
        ponteiroEncadeada = NULL;

    }else{

        //Se houver mais de um elemento, nosso auxiliar p iguala-se ao ponteiroEncadeada
        p = ponteiroEncadeada;

        //Enquanto nao estiver no ultimo termo,o auxiliar torna-se o proximo
        //ate que o aux seja o penultimo elemento da lista
        while(p->proximo != NULL){
            aux = p;
            p=p->proximo;
        }

        //passa o valor do ultimo elemento para a variavel "valor"
        *nome = p->nome;
        *rg = p->rg;

        //Aqui, o aux representa o peultimo elemento da lista
        //Tornando-o o ultimo elemento da lista
        aux->proximo = NULL;

        //Libera a Memoria
        free(p);

    }
}

//Remove posi��o espec�fica
void removePosicaoEncadeada(pessoa *ponteiroEncadeada,string *nome,int *rg, int posicao){

    //Ponteiro Auxiliar
    pessoa *p = ponteiroEncadeada;

    //Variavel que percorre a lista
    int i = 0;

    //Navega pela lista
    while(i <= posicao){

        //Caso tenha alcan�ado a posicao desejada
        if(i == posicao-1){

            //Retorna os dados do usuario a ser removido
            *nome = p->nome;
            *rg = p->rg;

            //Auxiliar do valor
            pessoa *aux = new pessoa;

            //Precisamos armazenar o endereco a ser apontado pelo novo node
            aux = p->proximo;

            //Fazendo o elemento K apontar para o novo NODE (2 membros a frente)
            p->proximo = aux->proximo;

            //Libera a Memoria
            free(aux);
        }

        //Analisa o proximo membro da lista
        p = p->proximo;

        //Contador de posi��es
        i++;
    }

    free(p);
}

int main(){

    //Vari�veis
    int funcaoDesejada = 1, tamanho;

    //Cria o inicio da lista Encadeada
    pessoa *ponteiroEncadeada;

    //Cria um novo valor para o primeiro
    pessoa *novoPrimeiroValor = new pessoa; //substitui o malloc da ling C (mesma logica)
    novoPrimeiroValor->nome = "john";
    novoPrimeiroValor->rg = 13;
    novoPrimeiroValor->proximo = NULL;

    //Transforma o ponteiro do inicio da lista no novo valor
    ponteiroEncadeada = novoPrimeiroValor;

    //Cria um novo valor para o segundo
    pessoa *novoSegundoValor = new pessoa;
    novoSegundoValor->nome = "johnzin";
    novoSegundoValor->rg = 20;
    novoSegundoValor->proximo = NULL;

    //Colocando o segundo valor
    novoPrimeiroValor->proximo = novoSegundoValor;

     //Manipula as listas
    while(funcaoDesejada < 10 && funcaoDesejada > 0){

        cout << "Operacoes \n";
        cout << "1 - Insercao de um node no inicio da lista \n";
        cout << "2 - Insercao de um node no fim da lista \n";
        cout << "3 - Insercao de um node na posicao N \n";
        cout << "4 - Retirar um node do inicio da lista \n";
        cout << "5 - Retirar um node no fim da lista \n";
        cout << "6 - Retirar um node na posicao N \n";
        cout << "7 - Procurar um node com o campo RG \n";
        cout << "8 - Imprimir a Lista. \n";
        cout << "9 - Sair do sistema. \n";
        cout << "\nEscolha um numero e pressione ENTER: \n";

        cout << "\nTamanho Atual[" << retornaTamanhoListaEncadeada(ponteiroEncadeada) << "]\n";

        imprimeEncadeada(ponteiroEncadeada);

        //Le a opcao
        cin >> funcaoDesejada;

        //Limpa as opcoes
        limpatela();

        //Variaveis para valores novos
        string nome;
        int rg, posicao,posicaoNaLista;

        //Alterna as Operacoes
        switch(funcaoDesejada){

            case 1:

                //Cabecalho da acao
                cout << "Funcao Escolhida: Insere um node no inicio da lista\n";

                //Lendo valores do usuario
                cout << "\nDigite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;

                //Adiciona no inicio
                adcComecoEncadeada(ponteiroEncadeada, nome, rg);

                //Exibe o usuario inserido
                cout << "Usuario: " << nome << ",RG: " << rg << " adicionado ao inicio da lista)";

                break;

            case 2:

                //Cabe�alho da acao
                cout << "Funcao Escolhida: Insere um node no fim da lista\n";

                //Lendo valores do usuario
                cout << "\nDigite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;

                if(retornaTamanhoListaEncadeada(ponteiroEncadeada) < 1){

                        //Adiciona ao inicio da Lista
                        adcComecoEncadeada(ponteiroEncadeada, nome, rg);

                }else{

                        //Adiciona ao fim da Lista
                        adcFimEncadeada(ponteiroEncadeada, nome, rg);
                }

                //Exibe o usuario inserido
                cout << "Usuario: "<< nome<< ",RG: "<< rg<< " adicionado ao final da lista("<< retornaTamanhoListaEncadeada(ponteiroEncadeada) << ")";

                break;

            case 3:

                //Cabe�alho da acao
                cout << "Funcao Escolhida: Insere um node na posicao escolhida da lista\n";

                //Lendo valores do usuario
                cout << "\nDigite a Posicao: ";
                cin >> posicao;
                cout << "Digite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;

                if(posicao == 0 ){

                    //Adiciona ao inicio da Lista
                    adcComecoEncadeada(ponteiroEncadeada, nome, rg);

                }else if(posicao == retornaTamanhoListaEncadeada(ponteiroEncadeada) - 1){

                    //Adiciona ao fim da Lista
                    adcFimEncadeada(ponteiroEncadeada, nome, rg);

                }else{

                    //Adiciona na posicao N da Lista
                    adcPosicaoEncadeada(ponteiroEncadeada,nome,rg, posicao);

                }

                //Exibe o usuario inserido
                cout << "Usuario: " << nome << ",RG: " << rg << " adicionado na posicao "  <<  posicao  << " da lista.";

                break;

            case 4: //Remove no inicio

                if(retornaTamanhoListaEncadeada(ponteiroEncadeada) == 0){
                    cout << "Lista Vazia";

                }else{

                    //Remove no inicio
                    removeInicioEncadeada(ponteiroEncadeada, &nome, &rg);

                    //Exibe o usuario removido
                    cout << "Usuario: " << nome<< ",RG: " << rg << " foi removido do inicio";
                }

                break;

            case 5:


                //Remove no final
                removeFinalEncadeada(ponteiroEncadeada, &nome, &rg);

                //Exibe o usuario removido
                cout << "Usuario: " << nome << ",RG: " << rg << " foi removido do final.";

                break;

            case 6:

                //Cabe�alho da acao
                cout << "Funcao Escolhida: Remove um node na posicao escolhida\n";

                cout << "Tamanho da Lista" << retornaTamanhoListaEncadeada(ponteiroEncadeada);

                //Lendo valores do usuario
                cout << "\nDigite a Posicao: ";
                cin >> posicao;

                if(posicao == 0){

                    //Remove no inicio
                    removeInicioEncadeada(ponteiroEncadeada, &nome, &rg);

                }/*else if (posicao == retornaTamanhoListaEncadeada(ponteiroEncadeada) - 1){

                    //Remove no final
                    removeFinalEncadeada(ponteiroEncadeada, &nome, &rg);

                }*/else{

                    //Remove na posicao N
                    removePosicaoEncadeada(ponteiroEncadeada, &nome, &rg, posicao);

                }

                //Exibe o usuario removido
                cout << "Usuario: "<< nome<< ",RG: "<< rg<< " foi removido da posicao" << posicao;
                break;

            case 7:

                //Cabe�alho da acao
                cout << "Funcao Escolhida: Retorna o nome e a posicao pelo RG\n";

                //Lendo valores do usuario
                cout << "Digite o RG: ";
                cin >> rg;

                //Retorna o nome pelo RG
                //cout << "O nome do RG:" << rg << " eh " << retornaNomeEncadeada(ponteiroEncadeada, rg,&posicao, &comparacoes) << "(" << posicao -1 << ")(Comparacoes:" << comparacoes << ")";

                break;

            case 8:

                imprimeEncadeada(ponteiroEncadeada);

                break;

        }
    }

    return 0;
}
