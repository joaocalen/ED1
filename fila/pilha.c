/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: 2018103815
 *
 * Created on 13 de Setembro de 2018, 09:19
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#define MaxTam 10

struct pessoa {
    char* nome;
    char* endereco;
    int idade;
};

struct pilha {
    Pessoa* pessoas[MaxTam];
    int topo;
};

Pilha* cria_pilha() {
    Pilha* pilhaAlunos = (Pilha*) malloc(sizeof (Pilha));
    pilhaAlunos -> topo = 0;
    return pilhaAlunos;
}

void push(Pessoa* pessoa, Pilha* pilha) {
    if (pilha -> topo < MaxTam) {
        pilha -> pessoas[pilha -> topo] = pessoa;
        pilha -> topo++;
    }
}

Pessoa* inicializaPessoa(char* nome, int idade, char* endereco) {
    Pessoa* pessoa = (Pessoa*) malloc(sizeof (Pessoa));
    pessoa -> nome = (char*) malloc(strlen(nome + 1) * sizeof (char));
    pessoa -> endereco = (char*) malloc(strlen(endereco + 1) * sizeof (char));
    strcpy(pessoa -> endereco, endereco);
    strcpy(pessoa -> nome, nome);
    pessoa -> idade = idade;
    return pessoa;
}

Pessoa* pop(Pilha* pilha) {
    if (!vazia_pilha(pilha)) {
        pilha -> topo--;
        return (pilha -> pessoas[pilha-> topo]);
    }

}

Pilha* destroi_pilha(Pilha* pilha) {
    int i;
    for (i = 0; i < pilha->topo; i++) {
        free(pilha->pessoas[i]->endereco);
        free(pilha->pessoas[i]->nome);
        free(pilha->pessoas[i]);
    }
    free(pilha);
}

void imprime_pilha(Pilha* pilha) {
    int i;
    for (i = 0; i < pilha->topo; i++) {
        printf("%s\n", pilha->pessoas[i]->endereco);
        printf("%s\n", pilha->pessoas[i]->nome);
        printf("%d\n\n\n", pilha->pessoas[i]->idade);
    }
}

int vazia_pilha(Pilha* p) {
    if (p != NULL) {
        return (p -> topo == 0);
    }
    return NULL;
}

int geiIdade(Pessoa* p) {
    return p -> idade;
}


void transfereItens(Pilha* p1, Pilha* p2){
    while (!vazia_pilha(p1)) {
        push(pop(p1), p2);
    }
}
/*
 * 
 */


