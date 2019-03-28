/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "tabelaHash.h"

struct palavra {
    char palavra[NPAL];
    int ocorrencias;
    struct palavra* prox;
};

 int le_palavra(FILE* fp, char* s) {
    int i = 0;
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c))
            break;

    };

    if (c == EOF)
        return 0;
    else
        s[i++] = c;

    while (i < NPAL - 1 && (c = fgetc(fp)) != EOF && isalpha(c))
        s[i++] = c;
    s[i] = '\0';

    return 1;
}

 void inicializa(Hash tab) {
    int i;
    for (i = 0; i < N; i++)
        tab[i] = NULL;
}

 int hash(char* string) {
    int i;
    int total = 0;
    for (i = 0; string[i] != '\0'; i++)
        total += string[i];

    return total % N;
}

 Palavra *acessa(Hash tab, char* s) {
    Palavra* p;
    int h = hash(s);

    for (p = tab[h]; p != NULL; p = p->prox) {
        if (strcmp(p->palavra, s) == 0)
            return p;
    }

    p = (Palavra*) malloc(sizeof (Palavra));
    strcpy(p->palavra, s);
    p->ocorrencias = 0;
    p->prox = tab[h];
    tab[h] = p;
    return p;
}

 int conta(Hash tab) {
    Palavra* p;
    int numOcorrencias = 0;
    for (int i = 0; i < N; i++) {
        for (p = tab[i]; p != NULL; p = p->prox) {
            numOcorrencias++;
        }
    }
    return numOcorrencias;
}

 Palavra** cria_vetor(Hash tab, int n) {
    Palavra** vetor = (Palavra**) malloc(n * sizeof (Palavra*));
    Palavra* p;
    int aux = 0;
    for (int i = 0; i < N; i++) {
        for (p = tab[i]; p != NULL; p = p->prox) {
            vetor[aux] = p;
            aux++;
        }
    }
    return vetor;
}

 int compara(const void* v1, const void* v2) {
    Palavra** p1 = (Palavra**) v1;
    Palavra** p2 = (Palavra**) v2;

    if ((*p1)->ocorrencias > (*p2)-> ocorrencias) return -1;
    else if ((*p1)->ocorrencias < (*p2)->ocorrencias) return 1;
    else return strcmp((*p1)->palavra, (*p2)->palavra);
}

 void imprime(Hash tab) {
    int i;
    int n;
    Palavra** vet;

    n = conta(tab);
    vet = cria_vetor(tab, n);
    qsort(vet, n, sizeof (Palavra*), compara);

    for (i = 0; i < n; i++) {
        printf("%s = %d\n", vet[i]->palavra, vet[i]->ocorrencias);
    }
    free(vet);
}

Palavra* palavra_setOcorrencias(Palavra* p) {
    if (p != NULL) {
        p ->ocorrencias++;
    }
    return p;
}