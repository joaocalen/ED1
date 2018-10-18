/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: 2018103815
 *
 * Created on 18 de Outubro de 2018, 09:26
 */

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
int max(int a, int b);
/*
 * 
 */
struct arv {
    Arv* noD;
    Arv* noE;
    char conteudo;
};

Arv* arv_criavazia() {
    return NULL;
}

Arv* arv_cria(char c, Arv* e, Arv* d) {
    Arv* nova = (Arv*) malloc(sizeof (Arv));
    nova -> noE = e;
    nova -> noD = d;
    nova -> conteudo = c;
}

char info(Arv* a) {
    return a -> conteudo;
}

int arv_vazia(Arv* a) {
    return (a == arv_criavazia());
}

Arv* arv_libera(Arv* a) {
    if (!arv_vazia(a)) {
        arv_libera(a->noE);
        arv_libera(a->noD);
        free(a);
    } else {
        return NULL;
    }
}

int arv_pertence(Arv* a, char c) {
    if (arv_vazia(a)) {
        return 0;
    } else {
        return ((info(a) == c) || arv_pertence(a->noE, c) || arv_pertence(a->noD, c));
    }
}

void arv_imprime(Arv* a) {
    printf("%c\n", info(a));
}

int folhas(Arv* a) {
    if (arv_vazia(a)) {
        return 0;
    } else if (arv_vazia(a->noE) && (arv_vazia(a->noD))) {
        return 1;
    } else {
        return folhas(a->noE) + folhas(a->noD);
    }
}

int ocorrencias(Arv* a, char c) {
    if (arv_vazia(a)) {
        return 0;
    } else if (info(a) == c) {
        ocorrencias(a->noE, c) +ocorrencias(a->noD, c);
        return 1;
    } else {
        return ocorrencias(a->noE, c) + ocorrencias(a->noD, c);
    }
}

int altura(Arv* a) {
    if (arv_vazia(a)) {
        return -1;
    } else {
        return 1 + max(altura(a->noE), altura(a->noD));
    }
}

Arv* arv_pai(Arv* a, char c) {
    if (info(a->noD) == c || info(a->noE) == c) {
        return a;
    } else if (arv_vazia(a)) {
        return NULL;
    } else {
        arv_pai(a->noE, c);
        arv_pai(a->noD, c);
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}