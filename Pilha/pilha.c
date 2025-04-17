/******* 
Filha - LIFO - Last In, First Out
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
    No* topo = NULL;

    while( opcao != 0 ){
        
        printf( "\n\n------Menu------\n");
        printf( " 1 - Inserir na Pilha \n");
        printf( " 2 - Remover da Pilha \n");
        printf( " 3 - Imprimir a Pilha \n");
        printf( " 0 - Sair \n");
        printf( " Digite sua escolha:  ");
        scanf( "%d" , &opcao );
        
        if( opcao == 1 ){
            printf( " Digite o nome que será inserido:  ");
            scanf( " %[^\n]" , &nome );
            No* endGerado = gerarEndereco( nome );
            if( topo != NULL ){
                endGerado->prox = topo;
            }
            topo = endGerado;
        }
        
        if( opcao == 2){
            if( topo == NULL ){
                printf( "A Pilha está vazia!");
            }else{
                No* aux = topo;
                topo = topo->prox;
                free( aux );
                printf( "Elemento removido com sucesso!");
            }
        }
        
        if( opcao == 3){
            printf("\nPilha: \n");
			if( topo == NULL) 
                printf("A Pilha está vazia!");
            else{
                No* aux = topo;
                while( aux != NULL){
                    printf("%s\n", aux->dado);
                    aux = aux->prox;
                }
            }
			
        }
    }
    return 0;
}



/*

Exercício de Pilha

Exercício: Construir uma pilha de livros, onde cada livro possui:
título, Autor e a quantidade de páginas. 
-> Construa uma método que adiciona o livro na pilha 
-> Construa também um método remove o livro da pilha.
-> Construa um método que imprime a pilha de livros, apresentando todos os dados de cada livro

*/
