#include "Insertion_sort.h"
#include <windows.h>
#include <cstring> // Para a função strcpy
#include <cstdio>
#include <fstream>
using namespace std;

InsertionSort::InsertionSort(){}

InsertionSort::~InsertionSort(){}


double getTempoAtual(){
    auto agora = chrono::steady_clock::now();
    chrono::duration<double> duracao = agora.time_since_epoch();
    return duracao.count();
}


void InsertionSort::ordenar(DadosEntrada *entrada)
{
    double inicio = getTempoAtual();
    int chave;
    int index;
    for(int i = 1; i < entrada->tamanho ; i++){
        chave = entrada->vector[i];
        index = i-1;   
        while(index >= 0 && entrada->vector[index] > chave){
            entrada->vector[index + 1] = entrada->vector[index];
            index--;
        }
        entrada->vector[index + 1] = chave;      
    }
    double fim = getTempoAtual();
    duracao = fim-inicio;
}




void InsertionSort::exibir_duracao(DadosEntrada entrada){
    printf("\nTempo gasto para vetor de tamanho %d: %lf segundos.\n\n",entrada.tamanho, duracao);
}


