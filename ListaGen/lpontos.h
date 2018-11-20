/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lpontos.h
 * Author: 2018103815
 *
 * Created on 20 de Novembro de 2018, 10:25
 */

#ifndef LPONTOS_H
#define LPONTOS_H

#include "listagen.h"

#ifdef __cplusplus
extern "C" {
#endif

    
    typedef struct ponto Ponto;

    Lista* criaListaPontos();
    
    Lista* inserePonto(Lista* l, float x, float y);
    
    void imprimeLista(Lista* l);
    
    Lista* retiraPonto(Lista* l, float x, float y);
    
    Ponto* centroGeometrico(Lista* l);
    
    void liberaPontos(Lista* l);

#ifdef __cplusplus
}
#endif

#endif /* LPONTOS_H */

