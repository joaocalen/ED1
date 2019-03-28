/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: joaogcalen
 *
 * Created on 3 de Outubro de 2018, 21:18
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*
 * 
 */
int main(int argc, char** argv) {
    // criando a lista vazia
    Lista* lista;
    // criando alguns alunos apenas para testar (mais adequado seria carregar de um arquivo)
    Item* maria = inicializaItem("maria", 23);
    Item* sofia = inicializaItem("sofia", 45);
    Item* jose = inicializaItem("jose", 45);
    Item* joao = inicializaItem("joao", 34);
    Item* catarina = inicializaItem("catarina", 98);

    //insere os alunos na lista
    lista = insere(maria, lista);
    lista = insere(sofia, lista);
    lista = insere(jose, lista);
    lista = insere(joao, lista);
    lista = insere(catarina, lista);

    //imprime a lista com todos os alunos
    //imprime(lista);

    //retira a maria da lista e imprime
    //    Item* retirado = retira(maria, lista);
    //    if (retirado != NULL)
    //        imprime(lista);
    //    else
    //        printf("N�o foi possivel retirar o aluno de matr�cula 123");

    //retira o Joao da lista e imprime
    lista = retira(jose, lista);
    imprime(lista);
    lista = retira(jose, lista);
    //if (lista != NULL)
    //    imprime(lista);
    //else
     //   printf("N�o foi possivel retirar o aluno de matr�cula 34");


    //Tenta retirar com um n�mero de matr�cula inexistente
    //    retirado = retira(lista, 555);
    //    if (retirado != NULL)
    //        imprime(lista);
    //    else
    //        printf("N�o foi possivel retirar o aluno de matr�cula 555");


    lista = libera(lista);
    imprime(lista);
    return (EXIT_SUCCESS);
}

