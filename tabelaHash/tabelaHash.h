/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tabelaHash.h
 * Author: 2018103815
 *
 * Created on 8 de Novembro de 2018, 09:35
 */

#ifndef TABELAHASH_H
#define TABELAHASH_H
#define N 127

#ifdef __cplusplus
extern "C" {
#endif

    struct palavra {
        char* palavra;
        int freq;
        Palavra* prox;
    };

    typedef struct palavra Palavra;

    typedef struct palavra* Hash[N];


#ifdef __cplusplus
}
#endif

#endif /* TABELAHASH_H */

