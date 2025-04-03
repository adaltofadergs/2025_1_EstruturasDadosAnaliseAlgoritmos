/******************************************************************************

Lista Encadeada por ordem de chegada

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int dado;
    struct No* prox;
} No;


No* gerarEndereco( int valor ){
    No *novoNo = (No*) malloc( sizeof(No) );
    if( novoNo == NULL ){
        printf( "ERRO AO ALOCAR MEMORIA" );
    }
    novoNo->dado = valor;
    novoNo->prox = NULL;
    return novoNo;
}

int main()
{

    int opcao = -1;
    int valor;
    No* inicio = NULL;
    while( opcao != 0 ){
        printf( "\n\n------Menu------\n");
        printf( " 1 - Inserir na lista \n");
        printf( " 2 - Remover da lista \n");
        printf( " 3 - Imprimir lista \n");
        printf( " 0 - Sair \n");
        printf( " Digite sua escolha:  ");
        scanf( "%d" , &opcao );
        
        if( opcao == 1 ){
            printf( " Digite o valor que será inserido:  ");
            scanf( "%d" , &valor );
           
            No* endGerado = gerarEndereco( valor );
            if( endGerado != NULL ){
                if( inicio == NULL){
                    inicio = endGerado;
                }else{
                    No* aux = inicio;
                    while( aux->prox != NULL ){
                        aux = aux->prox;
                    }
                    aux->prox = endGerado;
                }
            }
        }
        
        if( opcao == 2){
            if( inicio == NULL ){
                printf( "A lista encadeada está vazia!");
            }else{
                bool removido = false;
                printf( " Digite o valor que será removido:  ");
                scanf( "%d" , &valor );
                if( inicio->dado == valor ){
                    // valor é igual ao primeiro elemento
                    No* aux = inicio;
                    inicio = inicio->prox;
                    free( aux );
                    removido = true;
                }else{
                    // se o valor não é igual ao primeiro
                    No* ant = inicio;
                    No* aux = inicio->prox;
                    while ( aux != NULL ){
                        if( aux->dado == valor){
                            ant->prox = aux->prox;
                            free( aux );
                            removido = true;
                            break;
                        }else{
                            ant = aux;
                            aux = aux->prox;
                        }
                    }
                }
                if( removido ){
                    printf("O valor %d foi removido!" , valor);
                }else{
                    printf("O valor %d não foi encontrado", valor);
                }
            }
        }
        
        
        if( opcao == 3){
            printf("\nLista Encadeada: \n");
			if( inicio == NULL) printf("A lista está vazia!");
			No* aux = inicio;
			while( aux != NULL){
				printf("%d - ", aux->dado);
				aux = aux->prox;
			}
        }
    }
    return 0;
}
