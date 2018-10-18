/*
*********************************
* Programa testador do TAD Arvore
*********************************
*/
#include <stdio.h>
#include "arvore.h"

int main()
{
      //cria uma �rvore para teste
       Arv* a = arv_cria('a',
		    arv_cria('b',
			 arv_criavazia(),
			 arv_cria('d', arv_criavazia(), arv_criavazia())
		    ),
		    arv_cria('c',
			arv_cria('e', arv_criavazia(), arv_criavazia()),
			arv_cria('f', arv_criavazia(), arv_criavazia())
		    )
	);

	
     arv_imprime(a);
     
     // Verificia se o caracter 'b' pertence a arvore
     int pertence = arv_pertence (a, 'b');
     printf ("Caracter b pertence?: %d\n", pertence);	
      

    // Verificia se o caracter 'z' pertence a arvore
     pertence = arv_pertence (a, 'z');
     printf ("Caracter z pertence?: %d\n", pertence);	


     //retorna o pai do no c (deve ser 'a')
     Arv* pai = arv_pai (a, 'c');
     printf ("Pai do no c: %c \n", info(pai));

     // retorna o numero de folhas da arvore (3)
     int f = folhas(a);
     printf ("Numero de folhas da arvore: %d \n", f);

     // retorna o numero de ocorrencias de 'f' (1 vez) 
     int i = ocorrencias (a, 'f');
     printf ("Numero de ocorrencias de f: %d \n", i);
    
    // retorna a altura da arvore (no caso, 2)
    int h = altura (a);
    printf ("A altura da arvore e': %d \n", h);

     arv_libera (a);

}
