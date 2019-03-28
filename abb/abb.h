/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   abb.h
 * Author: joaogcalen
 *
 * Created on 25 de Novembro de 2018, 11:36
 */

#ifndef ABB_H
#define ABB_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct abb Abb;

    Abb* abb_criaVazia();

    Abb* abb_cria(int num);

    void abb_insere(int num, Abb* raiz);

    Abb* abb_busca(int num, Abb* raiz);

    Abb* abb_retira(int num, Abb* raiz);

    Abb* abb_libera(Abb* raiz);

    int abb_altura(Abb* raiz);

    int abb_folhas(Abb* raiz);

    int abb_pertence(int num, Abb* raiz);

    Abb* abb_pai(int num, Abb* raiz);

    void abb_imprime(Abb* raiz);

    int abb_trocaNumEsquerda(Abb* raiz, int num);

    int abb_trocaNumDireita(Abb* raiz, int num);


#ifdef __cplusplus
}
#endif

#endif /* ABB_H */

