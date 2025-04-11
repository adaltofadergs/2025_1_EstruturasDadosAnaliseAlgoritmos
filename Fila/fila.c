/******* 
Fila - FIFO
********/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char dado[20];
    struct No* prox;
} No;


No* gerarEndereco( char valor[20] ){
    No *novoNo = (No*) malloc( sizeof(No) );
    if( novoNo == NULL ){
        printf( "ERRO AO ALOCAR MEMORIA" );
    }
    strcpy( novoNo->dado ,  valor );
    novoNo->prox = NULL;
    return novoNo;
}

int main()
{

    int opcao = -1;
    char nome[20];
    No* inicio = NULL;
    No* fim = NULL;
    while( opcao != 0 ){
        
        printf( "\n\n------Menu------\n");
        printf( " 1 - Inserir na Fila \n");
        printf( " 2 - Remover da Fila \n");
        printf( " 3 - Imprimir a Fila \n");
        printf( " 0 - Sair \n");
        printf( " Digite sua escolha:  ");
        scanf( "%d" , &opcao );
        
        if( opcao == 1 ){
            printf( " Digite o nome que será inserido:  ");
            scanf( " %[^\n]" , &nome );
            No* endGerado = gerarEndereco( nome );
            if( fim == NULL ){
                inicio = endGerado;
                //fim = endGerado;
            }else{
                fim->prox = endGerado;
                //fim = endGerado;
            }
            fim = endGerado;
        }
        
        if( opcao == 2){
            if( inicio == NULL ){
                printf( "A Fila está vazia!");
            }else{
                No* aux = inicio;
                inicio = inicio->prox;
                free( aux );
                if( inicio == NULL ) fim = NULL;
                printf( "Elemento removido com sucesso!");
            }
        }
        
        if( opcao == 3){
            printf("\nFila: \n");
			if( inicio == NULL) printf("A Fila está vazia!");
			No* aux = inicio;
			while( aux != NULL){
				printf("%s - ", aux->dado);
				aux = aux->prox;
			}
        }
    }
    return 0;
}



/*

Exercício de Fila

Exercício: Construir uma fila de carros de uma lavagem, onde cada carro possui:
modelo, placa e kilometragem. Construa uma método que adiciona os carros na fila, 
porém, nesta fila, só cabem, 5 carros. Construa também um método que lave os carros.

*/
