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
using namespace std;
class Arquivo{
    public:
        void salvar_entrada(string, DadosEntrada);
        void salvar_saida(string, DadosEntrada);
        void salvar_tempo(string, DadosEntrada, double);
        void criar_pasta(const char*);
        void apagar_pasta_especifica();
};

#endif