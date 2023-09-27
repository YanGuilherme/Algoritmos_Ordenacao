#include "Insertion_sort.h"

using namespace std;

InsertionSort::InsertionSort():Algoritmo("insertion_sort"){}

InsertionSort::~InsertionSort(){}

void InsertionSort::ordenar(DadosEntrada *entrada){
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





