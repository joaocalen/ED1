/*
 ============================================================================
 Name        : aula1.c
 Author      : João Felipe G. Calenzani
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_esfera(float r, float* area, float* volume);
int negativos(int n, float* vet);
void inverte(int n, int* vet);
int** inverte2(int n, int* vet);
int menu();
void imprime(int n, int* vet);

int main(void) {
	switch (menu()) {
	case 1:
		printf("Digite o raio da esfera (cm): ");
		float r, area, volume;
		scanf("%f", &r);
		calc_esfera(r, &area, &volume);
		printf("A área da esfera é %.2f pi e o volume é %.2f pi \n", area,
				volume);
		break;
	case 2:
		printf("Digite o número de elementos do vetor: ");
		int tam;
		int i = 0;
		float num;
		scanf("%d", &tam);
		float* vet = (float*) malloc(tam * sizeof(float));
		while (i < tam) {
			printf("Digite um número: ");
			scanf("%f", &num);
			vet[i] = num;
			i++;
		}
		printf("O vetor em questão possui %d números negativos \n",
				negativos(tam, vet));
		free(vet);
		break;
	case 3:
		printf("Digite o número de elementos do vetor: ");
		i = 0;
		scanf("%d", &tam);
		int num2;
		int* vet2 = (int*) malloc(tam * sizeof(int));
		while (i < tam) {
			printf("Digite um número: ");
			scanf("%d", &num2);
			vet2[i] = num2;
			i++;
		}
		inverte (tam, vet2);
		free(vet2);
		break;
	case 4:
		break;
	default:
		printf("Digite um número válido");
		menu();
		break;
	}
	return EXIT_SUCCESS;
}

void calc_esfera(float r, float* area, float* volume) {
	*area = 4 * (pow(r, 2));
	*volume = (4 * (pow(r, 3))) / 3;
}

int negativos(int n, float* vet) {
	int i, aux = 0;
	while (i < n) {
		if (vet[i] < 0) {
			aux++;
		}
		i++;
	}
	return aux;
}

void inverte(int n, int* vet) {
	int i = 0;
	int aux;
	while (i < ((n)/2)){
		aux = vet[n-i-1];
		vet[n-i-1] = vet[i];
		vet[i] = aux;
		i++;
	}
	imprime (n,vet);
}

int** inverte2(int n, int* vet) {

}

int menu(){
	printf(" --------------  MENU -------------\n");
	printf("| 1) Superfície e Volume de esfera |\n");
	printf("| 2) Números Negativos em um vetor |\n");
	printf("| 3) Inverter valores em um vetor  |\n");
	printf("| 4) Desafio                       |\n");
	printf(" ---------------------------------- \n");
	printf("Digite o número do procedimento a ser realizado:");
	int opcao;
	scanf("%d", &opcao);

	return opcao;
}

void imprime (int n, int* vet){
	int i = 0;
	for (i=0;i<n;i++){
		printf("%d",vet[i]);
		printf("\n");
	}
}
