/*

Exercício de Fila

Exercício: Construir uma fila de carros de uma lavagem, onde cada carro possui:
modelo, placa e kilometragem. Construa uma método que adiciona os carros na fila, 
porém, nesta fila, só cabem, 5 carros. Construa também um método que lave os carros.

*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char modelo[20];
    char placa[8];
    int km;
    struct Carro* prox;
} Carro;


Carro* gerarEndereco( char modelo_[20], char placa_[8], int km_ ){
    Carro *novoNo = (Carro*) malloc( sizeof(Carro) );
    if( novoNo == NULL ){
        printf( "ERRO AO ALOCAR MEMORIA" );
    }
    strcpy( novoNo->modelo ,  modelo_ );
    strcpy( novoNo->placa ,  placa_ );
    novoNo->km = km_ ;
    novoNo->prox = NULL;
    return novoNo;
}

int main()
{

    int opcao = -1;
    char modelo[20];
    char placa[8];
    int km;
    Carro* inicio = NULL;
    Carro* fim = NULL;
    while( opcao != 0 ){
        
        printf( "\n\n------Menu------\n");
        printf( " 1 - Inserir um carro na Fila \n");
        printf( " 2 - Lavar um Carro \n");
        printf( " 3 - Imprimir a Fila de Carros \n");
        printf( " 0 - Sair \n");
        printf( " Digite sua escolha:  ");
        scanf( "%d" , &opcao );
        
        if( opcao == 1 ){

            int cont = 0;
            Carro* atual = inicio;
			while( atual != NULL){
				cont ++;
				atual = atual->prox;
			}
            if( cont == 5){
                printf( "\nA fila está cheia, só cabem 5 carros!");
            }else{

                printf( "Digite o modelo do carro que será inserido:  ");
                scanf( " %[^\n]" , &modelo );
                printf( "Digite a placa do carro:  ");
                scanf( " %[^\n]" , &placa );
                printf( "Digite a kilometragem:  ");
                scanf( "%d" , &km );

                Carro* endGerado = gerarEndereco( modelo, placa, km );
                if( fim == NULL ){
                    inicio = endGerado;
                }else{
                    fim->prox = endGerado;
                }
                fim = endGerado;

            }
        }
        
        if( opcao == 2){
            if( inicio == NULL ){
                printf( "A Fila está vazia!");
            }else{
                Carro* aux = inicio;
                inicio = inicio->prox;
                printf( "%s - %s lavado com sucesso!", aux->modelo, aux->placa);
                free( aux );
                if( inicio == NULL ) fim = NULL;  
            }
        }
        
        if( opcao == 3){
            printf("\nFila de Carros: \n");
			if( inicio == NULL) printf("\nA Fila está vazia!");
			Carro* atual = inicio;
			while( atual != NULL){
				printf("\nModelo: %s - ", atual->modelo );
				printf("\nPlaca: %s - ", atual->placa );
				printf("\nKilometragem: %d - ", atual->km );
				printf("\n----------------------------\n");
				atual = atual->prox;
			}
        }
    }
    return 0;
}
