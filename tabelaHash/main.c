/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: 2018103815
 *
 * Created on 8 de Novembro de 2018, 09:35
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabelaHash.h"

int main(int argc, char** argv) {
    FILE* fp;
    Hash tab;
    char s[NPAL];

    if (argc != 2) {
        printf("Arquivo de saída não fornecido \n");
        return 0;
    }

    fp = fopen(argv[1], "rt");
    if (fp == NULL) {
        printf("ERRO DE ABERTURA DE ARQUIVO\n");
        return 0;
    }

    inicializa(tab);
    while (le_palavra(fp, s)) {
        Palavra* p = acessa(tab, s);
        p = palavra_setOcorrencias(p);
    }

    imprime(tab);
    return (EXIT_SUCCESS);
}