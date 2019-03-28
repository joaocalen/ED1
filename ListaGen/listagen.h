/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listagen.h
 * Author: 2018103815
 *
 * Created on 20 de Novembro de 2018, 10:25
 */

#ifndef LISTAGEN_H
#define LISTAGEN_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct lista Lista;
    
    Lista* cria();
    
    Lista* insere(void* dado, Lista* l);
    
    Lista* retira(Lista* l, int (*cmp)(void* , void*),void* dado);
    
    int percorre(Lista* l, int (*cb)(void*,void*),void* dado);
    
    void libera(Lista* l, void(*f)(void*));


#ifdef __cplusplus
}
#endif

#endif /* LISTAGEN_H */

