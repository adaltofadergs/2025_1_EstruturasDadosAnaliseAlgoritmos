/*
Lista Duplamente Encadeado - Em ordem crescente
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    struct No* ant;
    char dado[20];
    struct No* prox;
} No;


No* gerarEndereco( char valor[20] ){
    No *novoNo = (No*) malloc( sizeof(No) );
    if( novoNo == NULL ){
        printf( "ERRO AO ALOCAR MEMORIA" );
    }
    strcpy( novoNo->dado ,  valor );
    novoNo->ant = NULL;
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
        printf( " 1 - Inserir na lista \n");
        printf( " 2 - Remover da lista \n");
        printf( " 3 - Imprimir lista \n");
        printf( " 4 - Imprimir lista reversa \n");
        printf( " 0 - Sair \n");
        printf( " Digite sua escolha:  ");
        scanf( "%d" , &opcao );
        
        if( opcao == 1 ){
            printf( " Digite o nome que será inserido:  ");
            scanf( " %[^\n]" , &nome );
            No* endGerado = gerarEndereco( nome );
            if( endGerado != NULL ){
                if( inicio == NULL){
                    inicio = endGerado;
                    fim = endGerado;
                }else{
                    // colocar na lista, ordenando
                    if( strcmp( nome , inicio->dado ) < 0 ){
                        // colocando o dado no INICIO
                        endGerado->prox = inicio;
                        inicio->ant = endGerado;
                        inicio = endGerado;
                    }else{
                        No* anterior = inicio;
                        No* aux = inicio->prox;
                        while ( aux != NULL){
                            if( strcmp( nome , aux->dado ) < 0 ){
                                anterior->prox = endGerado;
                                aux->ant = endGerado;
                                endGerado->prox = aux;
                                endGerado->ant = anterior;
                                break;
                            }else{
                                anterior = aux;
                                aux = aux->prox;
                            }
                        }
                        if( endGerado->prox == NULL ){
                            //anterior->prox = endGerado;
                            fim->prox = endGerado;
                            endGerado->ant = fim;
                            fim = endGerado;
                        }
                    } 
                }
            }
        }
        
        if( opcao == 2){
            if( inicio == NULL ){
                printf( "A lista duplamente encadeada está vazia!");
            }else{
                bool removido = false;
                printf( " Digite o valor que será removido:  ");
                scanf( " %[^\n]" , &nome );
                if( strcmp( inicio->dado,  nome) == 0 ){
                    // valor é igual ao primeiro elemento
                    No* aux = inicio;
                    inicio = inicio->prox;
                    if( inicio == NULL ){
                        fim = NULL;
                    }else{
                        inicio->ant = NULL;
                    }
                    free( aux );
                    removido = true;
                }else{
                    // se o valor não é igual ao primeiro
                    No* anterior = inicio;
                    No* aux = inicio->prox;
                    while ( aux != NULL ){
                        if( strcmp( aux->dado , nome) == 0){
                            anterior->prox = aux->prox;
                            if( aux->prox == NULL ){
                                fim = anterior;
                            }else{
                                //aux->prox->ant = anterior;
                                anterior->prox->ant = anterior;
                            }
                            free( aux );
                            removido = true;
                            break;
                        }else{
                            anterior = aux;
                            aux = aux->prox;
                        }
                    }
                }
                if( removido ){
                    printf("O valor %s foi removido!" , nome);
                }else{
                    printf("O valor %s não foi encontrado", nome);
                }
            }
        }
        
        
        if( opcao == 3){
            printf("\nLista  Duplamente Encadeada (Em Ordem): \n");
			if( inicio == NULL) printf("A lista está vazia!");
			No* aux = inicio;
			while( aux != NULL){
				printf("\n%s", aux->dado);
				aux = aux->prox;
			}
        }

        if( opcao == 4){
            printf("\nLista  Duplamente Encadeada (Em Ordem Inversa): \n");
			if( fim == NULL) printf("A lista está vazia!");
			No* aux = fim;
			while( aux != NULL){
				printf("\n%s", aux->dado);
				aux = aux->ant;
			}
        }
    }
    return 0;
}
