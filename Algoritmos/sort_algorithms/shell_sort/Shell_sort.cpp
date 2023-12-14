#include "Shell_sort.h"

ShellSort::ShellSort():Algoritmo("shell_sort"){}


ShellSort::~ShellSort(){}

void ShellSort::executar(DadosEntrada* entrada){
    double inicio = getTempoAtual();
    for (int gap = entrada->tamanho / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < entrada->tamanho; i++) {
        int temp = entrada->vector[i];
        int j;
        for (j = i; j >= gap && entrada->vector[j - gap] > temp; j -= gap) {
            entrada->vector[j] = entrada->vector[j - gap];
            }
        entrada->vector[j] = temp;
        }
    }
    double fim = getTempoAtual();
    duracao = fim-inicio;
}
