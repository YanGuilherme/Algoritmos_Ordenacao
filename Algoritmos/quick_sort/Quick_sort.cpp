#include "Quick_sort.h"

QuickSort::QuickSort():Algoritmo("quick_sort"){}
QuickSort::~QuickSort(){
}

void QuickSort::ordenar(DadosEntrada* entrada){
    double inicio = getTempoAtual();
    quick_sort(entrada->vector, 0, entrada->get_tamanho());
    double fim = getTempoAtual();
    duracao = fim-inicio;
}

void QuickSort::quick_sort(int * entrada, int inicio, int fim){
    int i, j, pivo, aux;
	i = inicio;
	j = fim-1;
	pivo = entrada[(inicio + fim) / 2];
	while(i <= j)
	{
		while(entrada[i] < pivo && i < fim)
		{
			i++;
		}
		while(entrada[j] > pivo && j > inicio)
		{
			j--;
		}
		if(i <= j)
		{
			aux = entrada[i];
			entrada[i] = entrada[j];
			entrada[j] = aux;
			i++;
			j--;
		}
	}
	if(j > inicio)
		quick_sort(entrada, inicio, j+1);
	if(i < fim)
		quick_sort(entrada, i, fim);
}
