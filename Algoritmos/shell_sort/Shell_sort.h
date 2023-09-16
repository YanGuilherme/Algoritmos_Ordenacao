#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include "../Algoritmo.h"
#include "../../DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../Arquivo.h"

class ShellSort: public Algoritmo{

public:
    ShellSort();
    ~ShellSort();
    void ordenar(DadosEntrada*);
};

#endif


