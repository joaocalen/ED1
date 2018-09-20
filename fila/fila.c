/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: 2018103815
 *
 * Created on 20 de Setembro de 2018, 09:23
 */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"

/*
 * 
 */
struct fila {
    Pilha* p;
    Pilha* aux;
};

Fila* cria_fila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila -> p = fila -> aux = cria_pilha();
    return fila;
}

void insere(Pessoa* pessoa, Fila* f){
    
}