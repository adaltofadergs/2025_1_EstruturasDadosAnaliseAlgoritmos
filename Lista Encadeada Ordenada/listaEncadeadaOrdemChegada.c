/******************************************************************************

Lista Encadeada de nomes, em ordem crescente

*******************************************************************************/

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
    while( opcao != 0 ){
        //system("cls");
        printf( "\n\n------Menu------\n");
        printf( " 1 - Inserir na lista \n");
        printf( " 2 - Remover da lista \n");
        printf( " 3 - Imprimir lista \n");
        printf( " 0 - Sair \n");
        printf( " Digite sua escolha:  ");
        scanf( "%d" , &opcao );
        
        if( opcao == 1 ){
            //system("cls");
            printf( " Digite o nome que será inserido:  ");
            scanf( " %[^\n]" , &nome );
           
            No* endGerado = gerarEndereco( nome );
            if( endGerado != NULL ){
                if( inicio == NULL){
                    inicio = endGerado;
                }else{
                    // colocar na lista, ordenando
                    if( strcmp( nome , inicio->dado ) < 0 ){
                        endGerado->prox = inicio;
                        inicio = endGerado;
                    }else{
                        No* ant = inicio;
                        No* aux = inicio->prox;
                        while ( aux != NULL){
                            if( strcmp( nome , aux->dado ) < 0 ){
                                ant->prox = endGerado;
                                endGerado->prox = aux;
                                break;
                            }else{
                                ant = aux;
                                aux = aux->prox;
                            }
                        }
                        if( endGerado->prox == NULL ){
                            ant->prox = endGerado;
                        }
                    } 
                }
            }
        }
        
        if( opcao == 2){
            if( inicio == NULL ){
                printf( "A lista encadeada está vazia!");
            }else{
                bool removido = false;
                printf( " Digite o valor que será removido:  ");
                scanf( " %[^\n]" , &nome );
                if( strcmp( inicio->dado,  nome) == 0 ){
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
                        if( strcmp( aux->dado , nome) == 0){
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
                    printf("O valor %s foi removido!" , nome);
                }else{
                    printf("O valor %s não foi encontrado", nome);
                }
            }
        }
        
        
        if( opcao == 3){
            printf("\nLista Encadeada: \n");
			if( inicio == NULL) printf("A lista está vazia!");
			No* aux = inicio;
			while( aux != NULL){
				printf("\n%s", aux->dado);
				aux = aux->prox;
			}
        }
    }
    return 0;
}
