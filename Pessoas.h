

#ifndef PESSOAS_H
#define PESSOAS_H

#include <stdlib.h>
#include <string.h>

typedef struct Pessoas Pessoa;

Pessoa* InserePessoa(char* nome);

Pessoa* InsereAmizade(Pessoa* p);


#endif //PESSOAS_H
