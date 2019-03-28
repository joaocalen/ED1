/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: joaogcalen
 *
 * Created on 4 de Outubro de 2018, 01:21
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listahet.h"

/*
 * 
 */
#define imov 1
#define mov 2

struct cliente {
    char* nome;
    int id_cliente;
};

struct movel {
    int placa;
    int ano;
    float valor;
};

struct imovel {
    int id_imovel;
    int ano;
    float valor;
};

struct listahet {
    Cliente* dono;
    void* item;
    ListaHet* prox;
    int id_item;
};

ListaHet * cria() {
    return NULL;
}

Cliente* cria_cliente(char* nome, int id) {
    Cliente* cliente = (Cliente*) malloc(sizeof (Cliente));
    cliente -> nome = (char*) malloc(strlen(nome + 1) * sizeof (char));
    strcpy(cliente -> nome, nome);
    cliente -> id_cliente = id;
    return cliente;
}

Movel* cria_movel(int placa, int ano, float valor) {
    Movel* movel = (Movel*) malloc(sizeof (Movel));
    movel -> placa = placa;
    movel -> ano = ano;
    movel -> valor = valor;
    return movel;
}

Imovel* cria_imovel(int id, int ano, float valor) {
    Imovel* imovel = (Imovel*) malloc(sizeof (Imovel));
    imovel -> id_imovel = id;
    imovel -> ano = ano;
    imovel -> valor = valor;
    return imovel;
}

ListaHet* insere_movel(ListaHet* lista, Cliente* dono, Movel* item) {
    ListaHet* nova = (ListaHet*) malloc(sizeof (ListaHet));
    nova -> prox = lista;
    nova -> dono = dono;
    nova -> item = item;
    nova -> id_item = mov;
    return nova;
}

ListaHet* insere_imovel(ListaHet* lista, Cliente* dono, Imovel* item) {
    ListaHet* nova = (ListaHet*) malloc(sizeof (ListaHet));
    nova -> prox = lista;
    nova -> dono = dono;
    nova -> item = item;
    nova -> id_item = imov;
    return nova;
}

void imprime(ListaHet* lista) {
    ListaHet* aux = lista;
    while (aux != NULL) {
        printf("Dono: %s \n", aux -> dono -> nome);
        if (lista -> id_item = mov) {
            printf("Ano: %d \n", ((Movel*) aux -> item) -> ano);
            printf("Placa: %d \n", ((Movel*) aux -> item) -> placa);
            printf("Valor: %.2f \n\n", ((Movel*) aux -> item) -> valor);
        } else {
            printf("Ano: %d \n", ((Imovel*) aux -> item) -> ano);
            printf("Identificador: %d \n", ((Imovel*) aux -> item) -> id_imovel);
            printf("Valor: %.2f \n\n", ((Imovel*) aux -> item) -> valor);
        }
        aux = aux -> prox;
    }
}

ListaHet* retira_cliente(ListaHet* lista, int id_cliente) {
    retira_cliente2(lista, id_cliente, 0);
}

ListaHet* retira_cliente2(ListaHet* lista, int id_cliente, int primeira) {
    ListaHet* aux = lista;
    ListaHet* ant = NULL;
    while (aux != NULL && aux -> dono -> id_cliente != id_cliente) {
        ant = aux;
        aux = aux -> prox;
    }
    if (aux == NULL) {
        printf("Nada para retirar \n\n");
        return lista;
    }
    if (ant == NULL) {
        lista = aux -> prox;
    } else {
        ant -> prox = aux -> prox;
    }
    if (primeira == 0) {
        free(aux -> dono -> nome);
        free(aux -> dono);
    }
    free(aux -> item);
    free(aux);
    retira_cliente2(lista, id_cliente, 1);
}

float calcula_valor_assegurado(ListaHet* lista, Cliente* dono, float taxa_movel, float taxa_imovel) {
    float valor = (float) 0;
    ListaHet* aux = lista;
    while (aux != NULL) {
        if ((aux -> dono -> id_cliente) == (dono -> id_cliente)) {
            if (aux -> id_item == mov) {
                valor = valor + taxa_movel * (((Movel*) aux ->item) ->valor);
            } else {
                valor = valor + taxa_imovel * (((Imovel*) aux ->item) -> valor);
            }
        }
        aux = aux -> prox;
    }
    return valor;
}