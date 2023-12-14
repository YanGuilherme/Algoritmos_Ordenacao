#include "Quick_sort_v1.h"

QuickSortV1::QuickSortV1():Algoritmo("quick_sort_v1_pivo_inicio"){}
QuickSortV1::~QuickSortV1(){
}

void QuickSortV1::executar(DadosEntrada* entrada){
    double inicio = getTempoAtual();
    quick_sort_v1(entrada->vector, 0, entrada->get_tamanho());
    double fim = getTempoAtual();
    duracao = fim-inicio;
}

void QuickSortV1::quick_sort_v1(int * entrada, int inicio, int fim){
    int i, j, pivo, aux;
	i = inicio;
	j = fim-1;
	pivo = entrada[inicio];
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
		quick_sort_v1(entrada, inicio, j+1);
	if(i < fim)
		quick_sort_v1(entrada, i, fim);
}
