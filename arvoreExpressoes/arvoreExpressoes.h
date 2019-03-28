/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arvoreExpressoes.h
 * Author: joaogcalen
 *
 * Created on 24 de Novembro de 2018, 18:15
 */

#ifndef ARVOREEXPRESSOES_H
#define ARVOREEXPRESSOES_H

#define operador 1
#define operando 2

#ifdef __cplusplus
extern "C" {
#endif

/*Tipo que define a arvore(tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD. */
typedef struct arv Arv;

/*Cria uma arvore vazia, ou seja, retorna NULL
* inputs: nenhum
* output: NULL
*/
Arv* CriaVazia(void);

/*cria um nó raiz de operador dados o operador e as duas sub-árvores, a da esquerda e a da direita
* inputs: o operador, as sub-arvores da esquerda e da direita
* output: o endereço do nó raiz criado
*/
Arv* CriaOperador(char c, Arv* esq, Arv* dir);

/*cria um nó operando dado o valor do no (como o operando é um nó folha, as sub-arvores da esquerda e da direita são nulas
* inputs: o operando
* output: o endereço do nó raiz criado
*/
Arv* CriaOperando(int valor);

/*Imprime a árvore em notação InOrder (esq, raiz, direita)
* inputs: o endereço da raiz da árvore
* output: nenhum
*/
void Imprime(Arv* arv);

/* Libera memória alocada pela estrutura da árvore
as sub-árvores devem ser liberadas antes de se liberar o nó raiz
* inputs: o endereço da raiz da árvore
* output: uma árvore vazia, representada por NULL
*/
Arv* Libera (Arv* arv);


/* Retorna o valor correspondente à avaliação da expressão representada na árvore
* inputs: o endereço da raiz da árvore
* output: o valor da expressão
*/
float Avalia(Arv* arv);


/* Retorna o número de folhas da árvore
* inputs: o endereço da raiz da árvore
* output: o número de folhas
*/
int Folhas(Arv* arv);

/* Retorna a altura da árvore
* inputs: o endereço da raiz da árvore
* output: a altura da árvore
*/
int Altura(Arv* arv);

#ifdef __cplusplus
}
#endif

#endif /* ARVOREEXPRESSOES_H */

