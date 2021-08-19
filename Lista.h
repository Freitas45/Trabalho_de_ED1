
#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct Pessoas Pessoa;

Pessoa* InserePessoa(char* nome);

void InsereAmizade(Pessoa* p, Pessoa* amigo);

Pessoa* confere_pessoa(Pessoa* p,char* n);

void printa_nome(Pessoa* p);

typedef struct Lista lista;

typedef struct Celula cel;

cel* retornaCelula(lista* l,char *nome);
lista* inicia_lista();

void InsereLista_pessoas(lista* Lista, Pessoa* p);

void DestroiLista_pessoas(lista* l);

void InsereLista_pessoas(lista* Lista, Pessoa* p);

void DestroiLista_pessoas(lista* l);

Pessoa* ProcuraPessoa(lista* l,char* nome);

void LeArqAmizade(lista* l);

#endif //LISTA_H
