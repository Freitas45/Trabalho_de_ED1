#include "Lista.h"


struct Pessoas
{
    char* nome;
    lista* amizade;

};

Pessoa* InserePessoa(char* n){
  Pessoa* p = (Pessoa*) malloc(sizeof(Pessoa));
  p->nome = (char*) malloc((strlen(n)+1) * sizeof(char));
  strcpy(p->nome,n);
  p->amizade = inicia_lista();
  return p;
}

void InsereAmizade(Pessoa* p, Pessoa* amigo){
  InsereLista_pessoas(p->amizade,amigo);
  InsereLista_pessoas(amigo->amizade,p);
}

Pessoa* confere_pessoa(Pessoa* p,char* n){
  if(strcmp(p->nome,n) == 0){
    return p;
  }else{
    return NULL;
  }
}

void printa_nome(Pessoa* p){
  printf("%s\n",p->nome);
}

struct Celula
{
    Pessoa* dado;
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

cel* retornaCelula(lista* l,char *nome){
cel* aux = l->prim;
while (strcmp(nome,aux->dado->nome) != 0){
aux = aux->prox;
}
return aux;
}


void LeArqAmizade(lista* l){
  Pessoa* p,*a;
  char*nome,*amigo;
  cel* c1,*c2;
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
      n++;
    }else{
      nome = strdup(strtok(aux, ";"));
      amigo = strdup(strtok(NULL,"\n"));
      printf("%s, %s\n",nome,amigo);
      c1 = retornaCelula(l,nome);
      c2 = retornaCelula(l,amigo);
      // p = ProcuraPessoa(l,nome);
      // printa_nome(p);
      // a = ProcuraPessoa(l,amigo);
      InsereAmizade(c1->dado,c2->dado);
      free(nome);
      free(amigo);
    }
  }
  fclose(ami);
}
