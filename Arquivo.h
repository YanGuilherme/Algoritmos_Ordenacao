#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "DadosEntrada.h"
#include "Algoritmos/Algoritmo.h"
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
#include <dirent.h>
using namespace std;
class Arquivo{
    public:
        static void salvar_entrada(string, DadosEntrada);
        static void salvar_saida(string, DadosEntrada);
        static void salvar_tempo(string, DadosEntrada, double);
        static void criar_pasta(const char*);
        static void apagar_pasta_especifica();
        static void visualizar_tempos();
    private:
};

#endif