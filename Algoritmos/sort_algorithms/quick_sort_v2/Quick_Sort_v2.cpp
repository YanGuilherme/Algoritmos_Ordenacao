#include "Quick_sort_v2.h"

QuickSortV2::QuickSortV2():Algoritmo("quick_sort_v2_pivo_media"){}
QuickSortV2::~QuickSortV2(){
}

void QuickSortV2::executar(DadosEntrada* entrada){
    double inicio = getTempoAtual();
    quick_sort_v2(entrada->vector, 0, entrada->get_tamanho());
    double fim = getTempoAtual();
    duracao = fim-inicio;
}

void QuickSortV2::quick_sort_v2(int * entrada, int inicio, int fim){
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
		quick_sort_v2(entrada, inicio, j+1);
	if(i < fim)
		quick_sort_v2(entrada, i, fim);
}
