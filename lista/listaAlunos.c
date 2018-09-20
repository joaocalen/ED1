/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2018103815
 *
 * Created on 30 de Agosto de 2018, 09:21
 */

#include <cstdlib>
#include "lista.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    struct tipoItem{
        char* nome;
        char* end; // não normalizado
        int mat;
    };
    
    typedef struct cel Celula;
    
    struct cel {
        tipoItem* aluno;
        Celula* prox;
    };
    
    struct tipoLista{
        Celula* prim;
        Celula* ult;
    };
    
    return 0;
}

TipoLista* inicializaLista(){
    TipoLista* lista;
    lista = (TipoLista*) malloc(sizeof(TipoLista)); 
    lista -> prim = NULL;
    lista -> ult = NULL;
    return lista;
}

void insere(TipoItem* aluno, TipoLista* lista){
    if (lista -> prim == NULL){
     lista -> prim == aluno;   
     lista -> ult == aluno;   
    }
}

