

#ifndef PESSOAS_H
#define PESSOAS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Pessoas Pessoa;


Pessoa* InserePessoa(char* nome);

void InsereAmizade(Pessoa* p, Pessoa* amigo);

Pessoa* confere_pessoa(Pessoa* p,char* n);



#endif //PESSOAS_H
