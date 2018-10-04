/* 
 * File:   main.c
 * Author: joaogcalen
 *
 * Created on 3 de Outubro de 2018, 18:41
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void montaAcertado(char* acertado, int tamanho);
void imprimeForca(char* palavra, char* acertado);
int verificaLetra(char* palavra, char* acertado, int erros);
bool mudaString(char* palavra, char* acertado, char c);

int main(int argc, char** argv) {
    char* palavra1 = (char*) malloc(10 * sizeof (char));
    printf("Digite uma palavra (use apenas letras minusculas): ");
   // scanf("%s", palavra);
    printf("rola");
    char* acertado = (char*) malloc(10 * sizeof (char));
    
    int tam = strlen(palavra1);
    montaAcertado(acertado, tam);
    printf("%s",acertado);
    imprimeForca(palavra1, acertado);
    free(acertado);
    free(palavra1);
    free(argv);

    return (EXIT_SUCCESS);
}

void montaAcertado(char* acertado, int tam) {
    int i = 0;
    while (tam >= i) {
        acertado[i] = '_';
        i++;
    }
}

void imprimeForca(char* palavra, char* acertado) {
    int erros = 0;
    printf("ai meu cu");
    while (palavra != acertado) {
        if (erros >= 5) {
            printf("Fim da linha.");
            free(acertado);
            free(palavra);
            exit(0);
        }
        int i = 0;
        erros = verificaLetra(palavra, acertado, erros);
        printf("Palavra: ");
        while (strlen(acertado) >= i) {
            printf("%c ", acertado[i]);
            i++;
        }
        printf("Erros: %d/5", erros);
    }
    printf("Parabéns. Você acertou");
}

int verificaLetra(char* palavra, char* acertado, int erros) {
    char c;
    printf("Jogador 2: ");
    printf("Digite uma letra: ");
    scanf("%c", c);
    if (mudaString(palavra, acertado, c)) {
        return erros;
    }
    return erros + 1;
}

bool mudaString(char* palavra, char* acertado, char c) {
    int i = 0;
    bool acertou = false;
    while (strlen(palavra) >= i) {
        if (c == palavra[i]) {
            acertado[i] = c;
            acertou = true;
        }
    }
    return acertou;
}