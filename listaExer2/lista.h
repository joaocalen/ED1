/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lista.h
 * Author: joaogcalen
 *
 * Created on 3 de Outubro de 2018, 21:44
 */

#ifndef LISTA_H
#define LISTA_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct celula Lista;

    typedef struct celula Celula;

    typedef struct item Item;

    Lista* inicializaLista();

    Lista* insere(Item* item, Lista* l);

    Lista* retira(Item* item, Lista* l);

    Lista* libera(Lista* l);

    void imprime(Lista* l);

    Item* inicializaItem(char* nome, int idade);




#ifdef __cplusplus
}
#endif

#endif /* LISTA_H */

