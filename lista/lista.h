#ifndef LISTA_H_
#define LISTA_H_

/*TipoItem Aluno (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD. Devem ser definidos campos:
  - nome (string)
  - matricula (int)
  - endereco (string)
  */
typedef struct tipoitem TipoItem;

/*Tipo que define a lista (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD.
  Usar lista COM Sentinela
  */
typedef struct tipolista TipoLista;

/*Inicializa o sentinela de uma lista
* inputs: nenhum
* output: Sentinela inicializado
* pre-condicao: nenhuma
* pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL
*/
TipoLista* inicializaLista();

/*Insere um aluno na primeira posi��o da lista de alunos
* inputs: aluno a ser inserido na lista (do tipo TipoItem) e a lista
* output: nenhum
* pre-condicao: aluno e lista n�o s�o nulos
* pos-condicao: lista cont�m o aluno inserido na primeira posi��o
*/
void insere (TipoItem* aluno, TipoLista* lista);

/*Retira um aluno de matr�cula mat da lista de alunos
* inputs: a lista e a matr�cula do aluno a ser retirado da lista
* output: o aluno (do tipo TipoItem) retirado da lista ou NULL, se o aluno n�o se encontrar na lista
* pre-condicao: lista n�o � nula
* pos-condicao: lista n�o cont�m o aluno de matr�cula mat
*/
TipoItem* retira (TipoLista* lista, int mat);


/*Imprime os dados de todos os alunos da lista
* inputs: a lista de alunos
* output: nenhum
* pre-condicao: lista n�o � nula
* pos-condicao: dados dos alunos impressos na saida padrao
*/
void imprime (TipoLista* lista);

/*Libera toda a mem�ria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
* inputs: a lista encadeada de alunos
* output: Lista vazia (NULL)
* pre-condicao: lista n�o � nula
* pos-condicao: mem�ria alocada � liberada
*/
TipoLista* libera (TipoLista* lista);


/*Inicializa um TipoItem aluno
* inputs: o nome, a matricula e o endereco do aluno
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, matricula e endereco validos
* pos-condicao: tipo item criado, com os campos nome, matricula e endereco copiados
*/
TipoItem* inicializaTipoItem(char* nome, int matricula, char* endereco);


#endif /* LISTA_H_ */
