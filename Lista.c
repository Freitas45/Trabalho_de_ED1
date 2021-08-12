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
    cel* ult;
};

void imprimelista(lista* l){
  cel* pa;
for(pa = l->ult ; pa!=NULL;pa = pa->prox){
    printa_nome(pa->dado);
}
}
lista* inicia_lista(){
  lista* l = (lista*) malloc (sizeof(lista));
  l->prim = NULL;
  l->ult = NULL;
  return l;
}

void InsereLista_pessoas(lista* Lista, Pessoa* p){
  cel *nova = (cel*) malloc (sizeof(cel));
  nova->dado = p;

  nova->prox = Lista->ult;
  Lista->ult = nova;
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
  char*nome,*amigo;
  char aux[1000];
  FILE* ami;
  int n = 0;
  ami = fopen("amizade.txt","r");

  while(fgets(aux,sizeof(aux),ami)!=NULL){
    if(n == 0){
      nome = strtok(aux, ";");
      while(nome!=NULL){
        p = InserePessoa(nome);
        InsereLista_pessoas(l,p);
        nome = strtok(NULL, ";");
      }
      imprimelista(l);
      n++;
    }else{
      nome = strdup(strtok(aux, ";"));
      amigo = strdup(strtok(NULL,"\n"));
      printf("%s, %s\n",nome,amigo);
      // p = ProcuraPessoa(l,nome);
      // a = ProcuraPessoa(l,amigo);
      // InsereAmizade(p,a);

    }
  }
  fclose(ami);
}
