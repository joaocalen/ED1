/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>

#include "listagen.h"

struct lista {
    void* info;
    Lista* prox;
};

Lista* cria(){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l-> info = NULL;
    l-> prox = NULL;
}

Lista* insere(void* dado, Lista* l) {
    Lista* novo = (Lista*) malloc(sizeof (Lista*));
    novo -> info = dado;
    novo -> prox = l;
    return novo;
}

Lista* retira(Lista* l, int(*cmp)(void*, void*), void* dado, void(*f)(void*)) {

}

int percorre(Lista* l, int(*cb)(void*, void*), void* dado) {
    Lista* aux;
    aux = l;
    while (l != NULL) {
        cb(l->info, dado);
        l = l-> prox;
    }
    return 1;
}

void libera(Lista* l, void(*f)(void*,void*)){
    f(l,NULL);
}