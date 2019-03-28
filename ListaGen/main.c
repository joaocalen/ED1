/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: 2018103815
 *
 * Created on 20 de Novembro de 2018, 10:22
 */
#include "lpontos.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    Lista* lista = criaListaPontos();
    lista = inserePonto(lista, 3.2, 3.0);
    lista = inserePonto(lista, 8.2, 0.0);
    lista = inserePonto(lista, 0.7, 2.0);

    imprimeLista(lista);
    CG* centro = inicializaCG();
    percorre(lista, centroGeometrico, centro);
    centro = calculaCG(centro);
    imprimeCG(centro);
    return (EXIT_SUCCESS);
}

