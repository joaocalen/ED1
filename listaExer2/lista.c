#include <stdio.h>
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

Lista* insere(Item* item, Lista* l) {
    Lista* nova = (Lista*) malloc(sizeof (Lista));
    nova -> prox = l;
    nova -> item = item;
    return nova;
}

Lista* retira(Item* item, Lista* l) {
    Celula* aux = l;
    Celula* ant = NULL;
    while (aux != NULL && aux->item->nome != item->nome) {
        ant = aux;
        aux = aux ->prox;
    }
    if (aux == NULL) {
        //printf("Elemento não encontrado!\n");
        return l;
    }
    if (ant == NULL) {
        l = aux -> prox;
    } else {
        ant -> prox = aux -> prox;
    }
    free(aux ->item ->nome);
    free(aux ->item);
    free(aux);
    return l;
}

Lista* libera(Lista* l) {
    while (l != NULL) {
        l = retira(l->item, l);
    }
    free(l);
    return NULL;
}

void imprime(Lista* l) {
    Celula* aux = l;
    while (aux != NULL) {
        printf("Nome: %s \n", aux ->item ->nome);
        printf("Idade: %d \n", aux ->item ->idade);
        aux = aux -> prox;
    }
    if (l == NULL) {
        printf("LISTA VAZIA");
    }
}

