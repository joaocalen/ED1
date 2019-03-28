/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tabelaHash.h
 * Author: joaogcalen
 *
 * Created on 10 de Dezembro de 2018, 11:53
 */

#ifndef TABELAHASH_H
#define TABELAHASH_H

#define N 127
#define NPAL 64

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct palavra Palavra;
    
    typedef struct palavra* Hash[N];

    Palavra* hsh_busca(Hash tab, int mat);
    
    Palavra* hsh_insere(Hash tab, int mat, char* nome, char turma, char* email);
    
    int hash(char* string);
    
    Palavra *acessa(Hash tab, char* palavra);
    
    int le_palavra(FILE* fp, char* s);
    
    int conta(Hash tab);
    
    Palavra** cria_vetor(Hash tab, int n);
    
    int compara (const void* v1, const void* v2);
    
    void imprime(Hash tab);
    
    void inicializa(Hash tab);
    
    Palavra* palavra_setOcorrencias(Palavra* p);
#ifdef __cplusplus
}
#endif

#endif /* TABELAHASH_H */

