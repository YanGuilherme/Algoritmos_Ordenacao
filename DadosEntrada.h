#ifndef DADOSENTRADA_H
#define DADOSENTRADA_H

#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <random>
#include <math.h>
#include <iostream>
#include <map>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum TipoEntrada{
    CRESCENTE,
    DECRESCENTE,
    RANDOM
};


class DadosEntrada{
    private:
        string tipo;
    public:
        string getTipo();
        int tamanho, *vector;
        TipoEntrada tipo_entrada;
        DadosEntrada();
        DadosEntrada(TipoEntrada, int);
        void make_vector();
        void exibe_vector();
        void destroy_vector();
        int get_tamanho();
};









#endif