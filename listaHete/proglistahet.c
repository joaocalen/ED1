/*
 *********************************
 * Programa testador 3 do TAD Lista
 * Testa funcoes de criacao, Insercao, Impressao, Retirada e Calculo do valor assegurado(Vale 10,0)
 *********************************
 */
#include <stdio.h>
#include "listahet.h"

int main() {

    printf("\n **** Preparando para a Terceira Bateria de Testes. Vale 10,0 **** \n\n");

    // criando a lista vazia
    ListaHet* lista = cria();

    //tenta retirar com lista vazia
    lista = retira_cliente(lista, 1);

    // criando alguns alunos apenas para testar (mais adequado seria carregar de um arquivo)
    Cliente* maria = cria_cliente("maria", 1);
    Cliente* sofia = cria_cliente("sofia", 2);
    Cliente* jose = cria_cliente("jose", 3);

    //printf("Dono: %s \n", jose -> nome);

    Movel* carro_sofia = cria_movel(2784, 2011, 25000);
    Movel* carro1_jose = cria_movel(3784, 2009, 12000);
    Movel* carro_maria = cria_movel(1852, 2000, 9000);
    Movel* carro2_jose = cria_movel(3785, 2011, 20000);
    Imovel* casa_sofia = cria_imovel(222, 1984, 500000);
    Imovel* casa_jose = cria_imovel(333, 1978, 600000);

    // inserindo elementos na lista
    lista = insere_movel(lista, sofia, carro_sofia);
    lista = insere_movel(lista, jose, carro1_jose);
    lista = insere_movel(lista, maria, carro_maria);
    lista = insere_movel(lista, jose, carro2_jose);
    lista = insere_imovel(lista, sofia, casa_sofia);
    lista = insere_imovel(lista, jose, casa_jose);

    imprime(lista);


    float valor_assegurado_jose = calcula_valor_assegurado(lista, jose, 0.7, 0.25);

    printf("O valor assegurado de Jose eh: %f \n", valor_assegurado_jose);


    lista = retira_cliente(lista, 1);

    printf("Imprimindo a lista novamente \n");

    imprime(lista);


    float valor_assegurado_sofia = calcula_valor_assegurado(lista, sofia, 0.7, 0.25);

    printf("O valor assegurado de sofia eh: %f \n", valor_assegurado_sofia);

    lista = retira_cliente(lista, 2);

    printf("Imprimindo a lista novamente \n");
    imprime(lista);
    
    lista = retira_cliente(lista, 3);


    printf("\n **** PARABENS!!! **** \n\n");
}
