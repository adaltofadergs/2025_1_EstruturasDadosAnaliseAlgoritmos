/*

Exercício de Pilha

Exercício: Construir uma pilha de livros, onde cada livro possui:
título, Autor e a quantidade de páginas. 
-> Construa uma método que adiciona o livro na pilha 
-> Construa também um método remove o livro da pilha.
-> Construa um método que imprime a pilha de livros, apresentando todos os dados de cada livro

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char titulo[30];
    char autor[30];
    int paginas;
    struct Livro* prox;
} Livro;


Livro* gerarEndereco( char _titulo[30], char _autor[20], int _paginas ){
    Livro *novoLivro = (Livro*) malloc( sizeof(Livro) );
    if( novoLivro == NULL ){
        printf( "ERRO AO ALOCAR MEMORIA" );
    }
    strcpy( novoLivro->titulo ,  _titulo );
    strcpy( novoLivro->autor ,  _autor );
    novoLivro->paginas = _paginas;
    novoLivro->prox = NULL;
    return novoLivro;
}

 int main()
{

    int opcao = -1;
    char titulo[30];
    char autor[20];
    int pag;
    Livro* topo = NULL;

    while( opcao != 0 ){
        
        printf( "\n\n------Menu------\n");
        printf( " 1 - Inserir Livro na Pilha \n");
        printf( " 2 - Remover Livro da Pilha \n");
        printf( " 3 - Imprimir a Pilha de Livro \n");
        printf( " 0 - Sair \n");
        printf( " Digite sua escolha:  ");
        scanf( "%d" , &opcao );
        
        if( opcao == 1 ){
            printf( " Digite o título do Livro:  ");
            scanf( " %[^\n]" , &titulo );
            printf( " Digite o nome do Autor:  ");
            scanf( " %[^\n]" , &autor );
            printf( " Informe a quantidade de páginas:  ");
            scanf( "%d" , &pag );
            Livro* endGerado = gerarEndereco( titulo, autor , pag);
            if( topo != NULL ){
                endGerado->prox = topo;
            }
            topo = endGerado;
        }
        
        if( opcao == 2){
            if( topo == NULL ){
                printf( "A Pilha está vazia!");
            }else{
                Livro* aux = topo;
                strcmp( titulo , topo->titulo );
                topo = topo->prox;
                free( aux );
                printf( "Livro %s, removido da Pilha!" , titulo);
            }
        }
        
        if( opcao == 3){
            printf("\nPilha: \n");
			if( topo == NULL) 
                printf("A Pilha está vazia!");
            else{
                Livro* aux = topo;
                while( aux != NULL){
                    printf("\nTítulo: %s", aux->titulo);
                    printf("\nAutor: %s", aux->autor);
                    printf("\nPáginas: %d", aux->paginas);
                    printf("\n------------------------------------\n");
                    aux = aux->prox;
                }
            }
			
        }
    }
    return 0;
}