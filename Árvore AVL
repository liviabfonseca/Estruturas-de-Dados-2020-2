#include <stdio.h>
#include <stdlib.h>

/*Estrutura da arvore*/
typedef struct no {
  int v;
  int balanceamento;
  struct no *filhoEsquerda;
  struct no *filhoDireita;
} No;

/*Função que retornar a altura da arvore*/
int altura(No* t) {
  if (t == NULL){
  return 0;
  }
  int alturaEsquerda = altura(t->filhoEsquerda);  
  int alturaDireita = altura(t->filhoDireita);
   
  if(alturaEsquerda>alturaDireita){
    return alturaEsquerda+1;
  }
  return alturaDireita+1;
}

/*Função que retorna um no criado*/
No* cria(int v, No* filhoEsquerda, No* filhoDireita) {
  No* no = (No*) malloc (sizeof(No));
  no->v = v;
  no->balanceamento = altura(filhoDireita) - altura(filhoEsquerda);
  no->filhoEsquerda = filhoEsquerda;
  no->filhoDireita = filhoDireita;
  return no;
}

/*------FUNÇÕES DE ROTAÇÃO-------*/

/*Rotação Left-left e realização do balanceamento*/
void LL(No** r) {
  No* b = *r;
  No* a = b->filhoEsquerda;
  b->filhoEsquerda = a->filhoDireita;
  a->filhoDireita = b;
  a->balanceamento = 0;
  b->balanceamento = 0;
  *r = a;
}

/*Rotação Right-Right e realização do balanceamento*/
void RR(No** r) {
  No* a = *r;
  No* b = a->filhoDireita;
  a->filhoDireita = b->filhoEsquerda;
  b->filhoEsquerda = a;
  a->balanceamento = 0;
  b->balanceamento = 0;
  *r = b;
}
/*Rotação Left-Right e balanceamento*/
void LR(No** r) {
  No *c = *r;
  No *a = c->filhoEsquerda;
  No *b = a->filhoDireita;
  c->filhoEsquerda = b->filhoDireita;
  a->filhoDireita = b->filhoEsquerda;
  b->filhoEsquerda = a;
  b->filhoDireita = c;

  if((b->balanceamento = -1)){
    a->balanceamento = 0;
    c->balanceamento = 1;
  }
  if((b->balanceamento = 0)){
    a->balanceamento = 0;
    c->balanceamento = 0;
  }
  if((b->balanceamento = 1)){
    a->balanceamento = -1;
    c->balanceamento = 0;
  }

  b->balanceamento = 0;
  *r = b;
}

/*Rotação Right-Left e balanceamento*/
void RL(No** r) {
  No *a = *r;
  No *c = a->filhoDireita;
  No *b = c->filhoEsquerda;
  c->filhoEsquerda = b->filhoDireita;
  a->filhoDireita = b->filhoEsquerda;
  b->filhoEsquerda = a;
  b->filhoDireita = c;

  if((b->balanceamento = -1)){
    a->balanceamento = 0;
    c->balanceamento = 1;
  }
  if((b->balanceamento = 0)){
    a->balanceamento = 0;
    c->balanceamento = 0;
  }
  if((b->balanceamento = 1)){
    a->balanceamento = -1;
    c->balanceamento = 0;
  }

  b->balanceamento = 0;
  *r = b;
}

/*-----FUNÇÕES PARA INSERIR ELEMENTO-----*/
int aux_insere(No** t, int v, int *cresceu) {
  if (*t == NULL) {
    *t = cria(v, NULL, NULL);
    *cresceu = 1;
    return 1;
  }
    
  if (v == (*t)->v){
    return 0;
  }

  if (v < (*t)->v) {
    if (aux_insere(&(*t)->filhoEsquerda, v, cresceu)) {
      if (*cresceu) {
        switch ((*t)->balanceamento) {
        case -1:
          if ((*t)->filhoEsquerda->balanceamento == -1){
            LL(t);
          }
          else{
            LR(t);
            *cresceu = 0;
          } 
          break;
        case 0:
          (*t)->balanceamento = -1;
          *cresceu = 1;
          break;
        case +1:
          (*t)->balanceamento = 0;
          *cresceu = 0;
          break;
        }
      }
      return 1;
    }
    return 0;
  }
  
  if (aux_insere(&(*t)->filhoDireita, v, cresceu)) {
    if (*cresceu) {
      switch ((*t)->balanceamento) {
      case -1:
        (*t)->balanceamento = 0;
        *cresceu = 0;
        break;
      case 0:
        (*t)->balanceamento = +1;
        *cresceu = 1;
        break;
      case +1:
        if ((*t)->filhoDireita->balanceamento == +1){
          RR(t);
        }
        else{
          RL(t);
          *cresceu = 0;
        }
        break;
      }
    }
    return 1;
  }
  return 0;
}

int insere(No **t, int v) {
  int cresceu;
  return aux_insere(t, v, &cresceu);
}

/*Função que imprime os elementos com sua altura*/
void imprime(No* r) {
  if (r != NULL) {
    printf("%d(%d) ", r->v, altura(r));
    imprime(r->filhoEsquerda);
    imprime(r->filhoDireita);
  }
}

int main() {
  int n, numero;
  char c,x;
 
  scanf("%c %d",&x, &numero);
  No* t = cria(numero,NULL,NULL);
  
  while(scanf("%c", &c) != EOF){
    if(c == 'i'){
      scanf("%d", &n);
      insere(&t,n);
    }
    if(c == 'p'){
      imprime(t); 
      printf("\n");     
    }
  }
  return 0;
}
