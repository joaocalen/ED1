/*
*********************************
* Programa testador do TAD Lista
*********************************
*/
#include <stdio.h>
#include "lista.h"

int main()
{
    // criando a lista vazia
	TipoLista* lista;
	lista = inicializaLista();

    // criando alguns alunos apenas para testar (mais adequado seria carregar de um arquivo)
    TipoItem* maria = inicializaTipoItem("maria", 123, "rua da maria");
    TipoItem* sofia = inicializaTipoItem("sofia", 2345, "rua da sofia");
    TipoItem* jose = inicializaTipoItem("jose", 4523, "rua do jose");
    TipoItem* joao = inicializaTipoItem("joao", 34, "rua do joao");
    TipoItem* catarina = inicializaTipoItem("catarina", 987, "rua da catarina");

    //insere os alunos na lista
    insere(maria, lista);
    insere(sofia, lista);
    insere(jose, lista);
    insere(joao, lista);
    insere(catarina, lista);

    //imprime a lista com todos os alunos
    imprime(lista);

    //retira a maria da lista e imprime
    TipoItem* retirado = retira(lista, 123);
    if (retirado != NULL)
    	imprime(lista);
    else
    	printf ("N�o foi possivel retirar o aluno de matr�cula 123");

    //retira o Joao da lista e imprime
    retirado = retira(lista, 34);
    if (retirado != NULL)
    	imprime(lista);
    else
    	printf ("N�o foi possivel retirar o aluno de matr�cula 34");


     //Tenta retirar com um n�mero de matr�cula inexistente
      retirado = retira(lista, 555);
      if (retirado != NULL)
      	imprime(lista);
      else
      	printf ("N�o foi possivel retirar o aluno de matr�cula 555");
     

      lista = libera(lista);       

}
