/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>

#include "lpontos.h"

struct ponto {
    float x;
    float y;
};

static int compara(void* info, void* dado) {
    Ponto* p1 = (Ponto*) info;
    Ponto* p2 = (Ponto*) dado;

    return (((p1 -> x) == (p2 -> x)) && ((p1 -> y) == (p2 -> y)));
}

static void liberaPonto(void* info, void* dado) {
    Lista* p = (Lista*) info;
    free(p->info);
    free(p);
}

static int imprime(void* info, void* dado) {
    Ponto* p = (Ponto*) info;
    printf("X: %.2f\n", p->x);
    printf("Y: %.2f\n", p->y);
    return 1;
}

static Ponto* centroGeometrico(Lista* l) {

}