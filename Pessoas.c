
#include "Pessoas.h"
#include "Lista.h"

struct Pessoas
{
    char* nome;
    lista* amizade;

};

Pessoa* InserePessoa(char* nome){
  lista* a;
  Pessoa* p = (Pessoa*) malloc(sizeof(Pessoa));
  p->amizade = inicia_lista();
  return p;
}

void InsereAmizade(Pessoa* p, Pessoa* amigo){
  InsereLista_pessoas(p->amizade,amigo);
  InsereLista_pessoas(amigo->amizade,p);
}
