#include "Lista.h"


struct Celula
{
    void* dado;
    cel* prox;
};

struct Lista
{
    cel* prim;
    cel*prox;
};

lista* inicia_lista(){
  lista* l = (lista*) malloc (sizeof(lista));
  lista->prim = NULL;
  lista->ult = NULL;
  return l;
}

void InsereLista_pessoas(lista* Lista, Pessoa* p){
  cel *nova = (cel*) malloc (sizeof(cel));
  nova->dado = p;
  nova->prox = lista->prim;
  Lista->prim = nova;
  if(Lista->ult == NULL){
            Lista->ult = nova;
        }
}
