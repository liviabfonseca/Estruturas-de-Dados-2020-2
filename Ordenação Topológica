#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct No{
    int valor;
    struct No *proximo;
}No;

typedef struct{
    No *inicio;
}Lista;

 /*Cria uma lista*/
 Lista* criaLista(){
    Lista *lista=(Lista*)malloc(sizeof(No));
    lista->inicio = NULL;
    return lista;
 }  

/*Insere um valor no final de uma lista*/
void insereFinal(Lista *lista, int numero){
    No *no, *novo = (No *)malloc(sizeof(No));
    novo->valor = numero;
    novo->proximo = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo;
    }else{
        no = lista->inicio;
        while(no->proximo != NULL){
            no = no->proximo;
        }
        no->proximo = novo;
    }
}


int main(void){
    int i,x;
    char *linha = NULL;
    size_t tamLinha = 0;
    int vertices, arestas;

    int posicao,k,z,c;
    int v,m;
    int pos,numLido,numChars;

    /*Recebendo o número de vertices e arestas*/
    scanf("%d%d\n", &vertices, &arestas);
    /*printf("Li vertices = %d e arestas = %d\n",vertices,arestas);*/
    Lista * vetorAdjacencia[vertices+1];

    /*Criando uma lista para cada vertice*/
    for(x=1;x<=vertices;x++){
        vetorAdjacencia[x] = criaLista();
    }
    
    /*Lendo os valores conectados aos vertices*/
    for(i = 1; i <= vertices; i++){
        getline(&linha,&tamLinha,stdin);
        pos = 0;
        numLido = 0;
        while (sscanf(&linha[pos], " %d %n", &numLido, &numChars) > 0) {
            pos += numChars;
            if(strlen(linha) != 0){
                insereFinal(vetorAdjacencia[i],numLido);
            }
        }
    }

/*BUSCA TOPOLOGICA*/

    int ordem[vertices];
    int grau_entrada[vertices+1];

/*Zerando todas as posições do vetor que receberá a ordem*/
    for(v=1;v<=vertices;v++){
        grau_entrada[v]=0;
    }

    /*Criando um no auxiliar que servirá de "apontador"*/
    No * aux;
    aux = (No*) malloc(sizeof(No*));

    /*Pegando o grau dos vertices*/
    for(z=1;z<=vertices;z++){
        aux = vetorAdjacencia[z]->inicio;
        while(aux != NULL){
            grau_entrada[aux->valor]++;
            aux = aux->proximo;
        }
    }
    
    /*O vetor ordem receberá o primeiro vertice da ordenação*/
    posicao = 0;
    for(m=1;m<=vertices;m++){
        if(grau_entrada[m]==0){
            ordem[posicao] = m;
            posicao++;
        }
    }

    /*Pegando o restante dos vertices ordenados*/
    c=0;
    while(c<posicao){
        aux = vetorAdjacencia[ordem[c]]->inicio;
        while(aux != NULL){
            grau_entrada[aux->valor]--;
            if(grau_entrada[aux->valor]==0){
                ordem[posicao]=aux->valor; 
                posicao++;
            } 
            aux = aux->proximo;
        }
        c++;
    } 

    /*Printando o vetor da ordenação*/
    for(k=0;k<vertices;k++){
        printf("%d ",ordem[k]);
    }
    return 0;
}
