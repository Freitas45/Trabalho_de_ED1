

#ifndef PESSOAS_H
#define PESSOAS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
typedef struct Pessoas Pessoa;


Pessoa* InserePessoa(char* nome);

void InsereAmizade(Pessoa* p, Pessoa* amigo);

Pessoa* ProcuraPessoa(char* nome);

char* VoltaNome();



#endif //PESSOAS_H
