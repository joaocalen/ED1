
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct item {
    char* nome;
    int idade;
};

struct celula {
    Item* item;
    Celula* prox;
};

Item* inicializaItem(char* nome, int idade) {
    Item* item = (Item*) malloc(sizeof (Item));
    item -> nome = (char*) malloc(strlen(nome + 1) * sizeof (char));
    strcpy(item->nome, nome);
    item -> idade = idade;
    return item;
}

Lista* inicializaLista() {
    Lista* l = (Lista*) malloc(sizeof (Lista));
    return l;
}

Lista* insere(Item* item, Lista* l) {
    Lista* nova = inicializaLista();
    nova -> prox = l;
    nova -> item = item;
    return nova;
}

Lista* retira(Item* item, Lista* l) {
    Celula* aux = NULL;
    if (l-> item == NULL) {
        return l;
    } else if (l->item == item) {
        aux = l;
        l = l -> prox;
        free(aux ->item->nome);
        free(aux ->item);
        free(aux);
    } else {
        Celula* ant = NULL;
        aux = l;
        while ((aux -> item != item) && (aux != NULL)) {
            ant = aux;
            aux = aux -> prox;
        }
        if (aux == NULL) {
            free(aux);
            free(ant);
        } else {
            ant -> prox = aux -> prox;
            free(aux ->item -> nome);
            free(aux ->item);
            free(aux);
            free(ant);
        }
    }
    return l;
}

Lista* libera(Lista* l){
    while (l != NULL){
        l = retira(l->item,l);
    }
}

