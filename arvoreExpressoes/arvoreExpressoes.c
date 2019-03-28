
#include "arvoreExpressoes.h"
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);

struct arv {
    Arv* NoE;
    Arv* NoD;
    char operator;
    int operating;
};

Arv* CriaVazia() {
    return NULL;
}

Arv* CriaOperador(char c, Arv* esq, Arv* dir) {
    Arv* arv = (Arv*) malloc(sizeof (Arv));
    arv -> NoD = dir;
    arv -> NoE = esq;
    arv -> operator = c;
    arv -> operating = 0;
    return arv;
}

Arv* CriaOperando(int valor) {
    Arv* arv = (Arv*) malloc(sizeof (Arv));
    arv -> NoD = CriaVazia();
    arv -> NoE = CriaVazia();
    arv ->operating = valor;
    arv -> operator = (char) 0;
    return arv;
}

void Imprime(Arv* arv) {
    if (arv != CriaVazia()) {
        if (arv -> operator != ((char) 0)) {
            printf("<%c", arv->operator);
        } else {
            printf("<%d", arv->operating);
        }
        Imprime(arv -> NoE);
        Imprime(arv -> NoD);
    } else {
        printf("<");
    }
    printf(">");
}

Arv* Libera(Arv* arv) {
    if (arv != CriaVazia()) {
        Libera(arv->NoE);
        Libera(arv->NoD);
        free(arv);
    }
    return CriaVazia();
}

int Folhas(Arv* arv) {
    if (arv->NoD == CriaVazia() && arv->NoE == CriaVazia()) {
        return 1;
    } else if (arv == CriaVazia()) {
        return 0;
    }
    return Folhas(arv->NoE) + Folhas(arv->NoD);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int Altura(Arv* arv) {
    if (arv == CriaVazia()) {
        return -1;
    } else {
        return 1+ max(Altura(arv->NoE), Altura(arv->NoD));
    }
}

float operacao(int a, int b, char operacao) {
    switch (operacao) {
        case '-':
            return a - b;
        case '+':
            return a + b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}

float Avalia(Arv* arv) {
    if (arv->operating != 0) {
        return arv -> operating;
    } else {
        return operacao(Avalia(arv->NoE), Avalia(arv->NoD), arv->operator);
    }
}

