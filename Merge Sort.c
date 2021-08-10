/*
*Nome: Livia Barbosa Fonseca
*DRE:118039721
*/
#include <stdio.h>
#include <stdlib.h>

void merge(int vetor[], int esquerda, int meio, int direita) {
    int e, m, k, tamanho, *aux;
    tamanho = direita - esquerda;
    /*Alocando memória para uma lista auxiliar*/
    aux = malloc(tamanho*sizeof(int));

    e = esquerda;
    m = meio;
    k = 0;
    
/*Comparando os números para colocar, em ordem crescente, no vetor auxiliar*/
    while(direita > m  && meio > e ) {
        /*Se o valor do número no índice "e" for menor ou igual ao do índice "m", o número do índice "e" vai ser passado para o vetor auxiliar e vamos somar um para os índices "k" e "e". Caso ocorra o contrario, teremos o auxiliar recebendo o número no índice "m" e teremos o incremento de "k" e "m"*/
        if(vetor[m] >= vetor[e]){
            aux[k] = vetor[e];
            k++;
            e++;
        }
        else{
            aux[k] = vetor[m];
            k++;
            m++;
        }     
    }
    /*Enquanto o valor de "e" for menor do que o do meio, o vetor auxiliar vai receber o número que está no índice "e" do vetor "vetor" e as variaveis "k" e "e" vão ser incrementadas*/
    while(meio > e){
        aux[k] = vetor[e];
        k++;
        e++;
    }
    /*Enquanto "m" for menor do que "direita" então o vetor auxiliar vai receber o número do índice "m" e as variaveis "k" e "m" vão ser incrementadas*/
    while(direita > m){
        aux[k] = vetor[m];
        k++;
        m++;
    }

    /*Enquanto "e" for menor que "direita" o vetor na posição "e" vai receber o valor do auxiliar na posição "e-esquerda"*/
    e = esquerda;
    while(e < direita){
        vetor[e] = aux[e - esquerda];
        e++;
    }
    /*Libendo a memória ocupada*/
    free(aux);
}

void mergesort(int vetor[], int esquerda, int direita){
    int meio;
    /*Se o tamanho da lista for maior do que 1 ele executa*/
    if (direita - esquerda > 1) {
        /*Dividindo a lista em listas menores*/
        meio = (esquerda + direita) / 2;
        /*Ordenando a lista da esquerda*/
        mergesort(vetor, esquerda, meio);
        /*Ordenando a lista da direita*/
        mergesort(vetor, meio, direita);
        /*Utilizando a função merge para juntar de forma ordenada as listas */
        merge(vetor, esquerda, meio, direita);
    }
}

int main(void){
    int contador = 0, tamanho_do_vetor = 1;
    int numero, i;
    int *vetor = (int *)malloc(sizeof(int));

    if(vetor == NULL){
        printf("erro - alocacao");
    }

    /*Recebendo números até chegar o fim do arquivo*/
    while(scanf("%d", &numero)!= EOF){
        /*Alocando a quantidade de memoria necessaria e colocando os números dentro do vetor*/
        if(contador == tamanho_do_vetor){
        tamanho_do_vetor = contador + tamanho_do_vetor;
        vetor = (int *)realloc(vetor, tamanho_do_vetor*sizeof(int));
        }
        
        vetor[contador] = numero;  
        contador++;
    }

    /*Utilizando a função mergesorte para organizar o vetor em ordem crescente*/
    mergesort(vetor, 0, contador);

    /*Imprimindo os números em ordem crescente*/
    for(i = 0; i<contador;i++){
        printf("%d\n",vetor[i]);
    }
    return 0;
}

