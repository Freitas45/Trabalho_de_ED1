
#ifndef LISTA_H
#define LISTA_H
#include "Pessoas.h"
#include "Playlists.h"

typedef struct Lista lista;

typedef struct Celula cel;

lista* inicia_lista();

void InsereLista_pessoas(lista* Lista, Pessoa* p);

void DestroiLista_pessoas(lista* l);

void InsereLista_pessoas(lista* Lista, Pessoa* p);

void DestroiLista_pessoas(lista* l);

Pessoa* ProcuraPessoa(lista* l,char* nome);

void LeArqAmizade(lista* l);

#endif //LISTA_H
