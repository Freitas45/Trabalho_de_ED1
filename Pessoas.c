
#include "Pessoas.h"
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
