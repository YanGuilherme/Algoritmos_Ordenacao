#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include "../../Algoritmo.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../../DadosEntrada.h"
#include "../../../Arquivo.h"

class ShellSort: public Algoritmo{

public:
    ShellSort();
    ~ShellSort();
    void executar(DadosEntrada*);
};

#endif


