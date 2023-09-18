#include "Algoritmo.h"


Algoritmo::Algoritmo(string nome){
    this->nome = nome;
}

double Algoritmo::getTempoAtual(){
    auto agora = chrono::steady_clock::now();
    chrono::duration<double> duracao = agora.time_since_epoch();
    return duracao.count();
}

void Algoritmo::exibir_duracao(DadosEntrada entrada){
    printf("\nTempo gasto para vetor de tamanho %d: %lf segundos.\n\n",entrada.tamanho, duracao);
}

string Algoritmo::getNome()
{
    return this->nome;
}
