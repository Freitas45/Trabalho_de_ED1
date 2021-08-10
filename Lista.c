#include "Lista.h"
#include "Pessoas.h"


struct Celula
{
    void* dado;
    cel* prox;
};

struct Lista
{
    cel* prim;
    cel* prox;
};

lista* inicia_lista(){
  lista* l = (lista*) malloc (sizeof(lista));
  l->prim = NULL;
  l->prox = NULL;
  return l;
}

void InsereLista_pessoas(lista* Lista, Pessoa* p){
  cel *nova = (cel*) malloc (sizeof(cel));
  nova->dado = p;
  nova->prox = Lista->prim;
  Lista->prox = nova;
  if(Lista->prim == NULL){
            Lista->prim = nova;
        }
}

Pessoa* ProcuraPessoa(lista* l,char* nome){
  cel* p;
  Pessoa* pes;
  for(p = l->prim ; p!=NULL;p = p->prox){
        pes = confere_pessoa(p->dado,nome);
        if(pes!= NULL){
            break;
        }
    }
    return pes;
}

void LeArqAmizade(lista* l){
  Pessoa* p,*a;
  char* aux,*nome[] = "kasjkas",*amigo;
  FILE* ami;
  int n = 0;
  p = ProcuraPessoa(l,nome);
  printf("%s\n",nome);

  // ami = fopen("amizade.txt","r");
  //
  // while(fgets(aux,sizeof(aux),ami)!=NULL){
  //     if(n = 0){
  //       nome = strdup(strtok(aux, ";"));
  //       while(nome!=NULL){
  //         nome = strdup(strtok(NULL, ";"));
  //         p = InserePessoa(nome);
  //         InsereLista_pessoas(l,p);
  //       }
  //       n++;
  //     }
  //     if(n = 1){
  //       nome = strdup(strtok(aux, ";"));
  //       amigo = strdup(strtok(NULL,"\n"));
  //       p = ProcuraPessoa(l,nome);
  //       a = ProcuraPessoa(l,amigo);
  //       InsereAmizade(p,a);
  //       printf("%s\n",nome);
  //     }
  // }
}
