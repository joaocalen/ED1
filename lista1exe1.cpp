/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2018103815
 *
 * Created on 28 de Agosto de 2018, 13:29
 */

#include <cstdlib>
#include <cstring>
#include <string.h>
#include <stdio.h>


using namespace std;

/*
 * 
 */
void inverterString(char* str);
void alocarString(char* str);

int main(int argc, char** argv) {
    char* str;
    str = (char*) malloc(1 * sizeof (char));
    alocarString(str);
    inverterString(str);
    free(str);
    return 0;
}

void inverterString(char* str) {
    int i = strlen(str);
    while(i>=0){
        printf("%c", str[i]);
        i--;
    }
}

void alocarString(char* str) {
    char c;
    int i = 0;
    printf("Digite uma palavra: ");
    while ((c = getchar()) != '\n' && c != '\0') {
        *(str + i * sizeof (char)) = c;
        str = (char*) realloc(str, strlen(str) + 1 * sizeof (char));
        i++;
    }
    *(str + i * sizeof (char)) = '\0';
}