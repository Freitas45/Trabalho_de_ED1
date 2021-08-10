
#include "Pessoas.h"

struct Pessoa
{
    char* nome;
    Lista* amizade;

};

Pessoa* InserePessoa(char* nome){
  Pessoa* p = (Pessoa*) malloc(sizeof(Pessoa));
  p->amizade = (Lista*) malloc(sizeof(Lista));
  return p;
}

void InsereAmizade(Pessoa* p, Pessoa* amigo){
  InsereLista_pessoas(p->amizade,amigo);
  InsereLista_pessoas(amigo->amizade,p);
}
