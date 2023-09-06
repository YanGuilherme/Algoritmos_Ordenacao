#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <random>
#include <math.h>
#include <iostream>

#include <windows.h>
#include <cstring> // Para a função strcpy
#include <cstdio>
#include <fstream>

class Arquivo{
    public:
        void salvar_entrada(DadosEntrada);
        void salvar_saida(DadosEntrada);
        void salvar_tempo(DadosEntrada,double);
        void criar_pasta(const char*);
};

#endif