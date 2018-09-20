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

Fila* cria_fila() {
    Fila* fila = (Fila*) malloc(sizeof (Fila));
    fila -> p = fila -> aux = cria_pilha();
    return fila;
}

void insere(Pessoa* pessoa, Fila* f) {
    push(pessoa, f->p);
}

Pessoa* retira(Fila* f) {
    Pessoa* p;
    transfereItens(f->p, f->aux);
    p = pop(f->aux);
    transfereItens(f->aux, f->p);
    return p;
}

void imprime_fila(Fila* f) {
    transfereItens(f->p, f->aux);
    imprime_pilha(f->aux);
    transfereItens(f->aux, f->p);
}

int vazia_fila(Fila* f) {
    return vazia_pilha(f->p);
}

Fila* destroi_fila(Fila* f) {
    destroi_pilha(f->aux);
    destroi_pilha(f->p);
}

void separa_filas(Fila* f, Fila* f_maiores, Fila* f_menores) {
    Pessoa* p;
    while (!vazia_pilha(f->p)) {
        p = pop(f->p);
        if (getIdade(p) >= 60) {
            push(p, f_maiores ->p);
        } else {
            push(p, f_menores ->p);
        }
    }
}