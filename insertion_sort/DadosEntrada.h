#ifndef DADOSENTRADA_H
#define DADOSENTRADA_H

#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <random>
#include <math.h>
#include <iostream>

enum TipoEntrada{
    CRESCENTE,
    DECRESCENTE,
    RANDOM
};

class DadosEntrada{
    private:
    public:
        int tamanho, *vector;
        TipoEntrada tipo_entrada;
        DadosEntrada();
        DadosEntrada(int, TipoEntrada);

        void make_vector();
        void exibe_vector();
        void escolha_entrada();
        void escolha_tamanho(int);
};









#endif