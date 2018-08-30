/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2018103815
 *
 * Created on 30 de Agosto de 2018, 09:21
 */

//#include <cstdlib>
#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//using namespace std;

struct tipoItem {
    char* nome;
    char* end; // não normalizado
    int mat;
};

typedef struct cel Celula;

struct cel {
    tipoItem* aluno;
    Celula* prox;
};

struct tipoLista {
    Celula* prim;
    Celula* ult;
};

TipoLista* inicializaLista() {
    TipoLista* lista;
    lista = (TipoLista*) malloc(sizeof (TipoLista));
    lista -> prim = NULL;
    lista -> ult = NULL;
    return lista;
}

void insere(TipoItem* aluno, TipoLista* lista) {
    Celula* alunoCel = (Celula*) malloc(sizeof (Celula));
    alunoCel -> aluno == aluno;
    alunoCel -> prox = lista -> prim;
    lista -> prim = alunoCel;
    if (lista -> ult == NULL) {
        lista -> ult = alunoCel;
    }
    //else if (lista -> prim == lista -> ult) {
}

TipoItem* retira(TipoLista* lista, int mat) {
    //Celula* alunoCel = (Celula*) malloc(sizeof (Celula));
    //alunoCel -> aluno -> mat = mat;
    if (lista -> ult == NULL) {
        return lista;
    } else if ((lista -> ult == lista -> prim) && lista -> ult -> aluno -> mat == mat) {
        free(lista -> prim -> prox);
        free(lista -> prim -> aluno);
        lista -> prim = NULL;
        lista -> ult = NULL;
    }
    Celula* aux;
    Celula* ant;
    aux = lista -> prim;
    while (aux -> aluno -> mat != mat) {
        ant = aux;
        aux = aux -> prox;
    }
    ant -> prox = aux -> prox;
    free(aux -> aluno ->end);
    free(aux -> aluno ->nome);
    free(aux -> aluno);
}

TipoLista* libera(TipoLista* lista) {
    Celula* p = lista -> prim;
    Celula* aux;
    while (p != NULL) {
        aux = p->prox;
        free(p->aluno->nome);
        free(p->aluno->end);
        free(p->aluno);
        free(p);
        p = aux;
    }
    free(lista);
    return NULL;
}

TipoItem* inicializaTipoItem(char* nome, int matricula, char* endereco) {
    TipoItem* aluno = (TipoItem*) malloc(sizeof (TipoItem));
    aluno -> nome = (char*) malloc((strlen(nome) + 1) * sizeof (char));
    strcpy(aluno->nome, nome);
    aluno-> end = (char*) malloc((strlen(endereco) + 1) * sizeof (char));
    strcpy(aluno->end, endereco);
    aluno -> mat = matricula;
    return aluno;
}

