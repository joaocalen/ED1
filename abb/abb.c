/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stddef.h>
#include <stdlib.h>

#include "abb.h"

struct abb {
    int num;
    Abb* noE;
    Abb* noD;
};

Abb* abb_criaVazia() {
    return NULL;
}

Abb* abb_cria(int num) {
    Abb* abb = (Abb*) malloc(sizeof (Abb));
    abb ->num = num;
    abb -> noE = NULL;
    abb -> noD = NULL;
    return abb;
}

void abb_insere(int num, Abb* raiz) {
    if (num > raiz->num) {
        if (raiz->noD == abb_criaVazia()) {
            raiz->noD = abb_cria(num);
        } else {
            abb_insere(num, raiz->noD);
        }
    } else {
        if (raiz->noE == abb_criaVazia()) {
            raiz->noE = abb_cria(num);
        } else {
            abb_insere(num, raiz->noE);
        }
    }
}

Abb* abb_libera(Abb* raiz) {
    if (raiz != abb_criaVazia()) {
        abb_libera(raiz->noE);
        abb_libera(raiz->noD);
        free(raiz);
    }
    return NULL;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int abb_altura(Abb* raiz) {
    if (raiz == abb_criaVazia()) {
        return -1;
    } else {
        return 1 + (max(abb_altura(raiz->noE), abb_altura(raiz->noD)));
    }
}

int abb_folhas(Abb* raiz) {
    if (raiz == abb_criaVazia()) {
        return 0;
    } else if (raiz->noE == abb_criaVazia() && raiz->noD == abb_criaVazia()) {
        return 1;
    } else {
        return abb_folhas(raiz->noE) + abb_folhas(raiz->noD);
    }
}

int abb_pertence(int num, Abb* raiz) {
    if (raiz == abb_criaVazia()) {
        return 0;
    } else {
        return (num == raiz->num) || abb_pertence(raiz->noE) || abb_pertence(raiz->noD);
    }
}

Abb* abb_busca(int num, Abb* raiz) {
    if (raiz == abb_criaVazia()) {
        return abb_criaVazia();
    } else {
        if (num == raiz->num) {
            return raiz;
        } else {
            Abb* a1 = abb_busca(num, raiz->noE);
            Abb* a2 = abb_busca(num, raiz->noD);
            if (a1 != abb_criaVazia()) {
                return a1;
            } else if (a2 != abb_criaVazia()) {
                return a2;
            } else {
                return abb_criaVazia();
            }
        }
    }
}

Abb* abb_retira(int num, Abb* raiz) {
    Abb* retira = abb_busca(num, raiz);
    if (retira->noE == abb_criaVazia() && retira->noD == abb_criaVazia()) {
        free(retira);
    } else {
        if (raiz->noE != abb_criaVazia()) {
            retira->num = abb_trocaNumDireita(retira->noE, num);
            abb_retira(num, retira);
        } else {
            retira->num = abb_trocaNumEsquerda(retira->noD, num);
            abb_retira(num, retira);
        }
    }
}

int abb_trocaNumDireita(Abb* raiz, int num) {
    if (raiz->noD != abb_criaVazia()) {
        return abb_trocaNumDireita(raiz->noD, num);
    } else {
        int retorno = raiz->num;
        raiz->num = num;
        return retorno;
    }
}

int abb_trocaNumEsquerda(Abb* raiz, int num) {
    if (raiz->noE != abb_criaVazia()) {
        return abb_trocaNumDireita(raiz->noE, num);
    } else {
        int retorno = raiz->num;
        raiz->num = num;
        return retorno;
    }
}

void abb_imprime(Abb* raiz) {
    if (raiz != abb_criaVazia()) {
        abb_imprime(raiz->noE);
        printf("%d", raiz->num);
        abb_imprime(raiz->noE);
    }
}