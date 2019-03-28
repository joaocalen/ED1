/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <stdio.h>

#include "lpontos.h"

struct ponto {
    float x;
    float y;
};



struct cg {
    Ponto* p;
    int numPontos;
};

Lista* criaListaPontos() {
    return cria();
}

Lista* inserePonto(Lista* l, float x, float y) {
    return insere(inicializaPonto(x, y), l);
}

Ponto* inicializaPonto(float x, float y) {
    Ponto* p = (Ponto*) malloc(sizeof (Ponto));
    p -> x = x;
    p -> y = y;
    return p;
}

CG* inicializaCG() {
    CG* cg = (CG*) malloc(sizeof (CG));
    cg -> p = inicializaPonto(0, 0);
    cg -> numPontos = 0;
    return cg;
}

CG* calculaCG(CG* cg) {
    cg -> p -> x /= cg -> numPontos;
    cg -> p -> y /= cg -> numPontos;
    return cg;
}

void imprimeLista(Lista* l) {
    percorre(l, imprime, NULL);
}

Lista* retiraPonto(Lista* l, float x, float y) {
    Ponto* p = inicializaPonto(x, y);
    retira(l, compara, p);
    free(p);
}

Lista* liberaPontos(Lista* l) {
    //    if (l != NULL) {

    //    while (l != NULL) {
    //        Lista* aux = l -> prox;
    //
    //    }
    //}
    return NULL;
}

void imprimeCG(CG* cg){
    printf("CG X: %f Y: %f",cg -> p -> x,cg -> p -> y);
}


// funções de callback

static int compara(void* info, void* dado) {
    Ponto* p1 = (Ponto*) info;
    Ponto* p2 = (Ponto*) dado;

    return (((p1 -> x) == (p2 -> x)) && ((p1 -> y) == (p2 -> y)));
}

static void liberaPonto(void* info) {
    Ponto* p = (Ponto*) info;
    free(p);
}

static int imprime(void* info, void* dado) {
    Ponto* p = (Ponto*) info;
    printf("X: %f\n", p->x);
    printf("Y: %f\n", p->y);
    return 1;
}

int centroGeometrico(void* info, void* dado) {
    Ponto* p = (Ponto*) info;
    CG* cg = (CG*) dado;
    cg -> p -> x += p-> x;
    cg -> p -> y += p-> y;
    cg -> numPontos++;
    return 0;
}
