#include "Quick_sort_v3.h"

QuickSortV3::QuickSortV3():Algoritmo("quick_sort_v3"){}
QuickSortV3::~QuickSortV3(){
}

void QuickSortV3::ordenar(DadosEntrada* entrada){
    double inicio = getTempoAtual();
    quick_sort_v3(entrada->vector, 0, entrada->get_tamanho());
    double fim = getTempoAtual();
    duracao = fim-inicio;
}

int QuickSortV3::calcularMediana(int a, int b, int c) {
    if ((a <= b && b <= c) || (c <= b && b <= a))
        return b;
    else if ((b <= a && a <= c) || (c <= a && a <= b))
        return a;
    else
        return c;
}


void QuickSortV3::quick_sort_v3(int * entrada, int inicio, int fim){
    if (inicio < fim) {
        int i, j, pivo, aux;

        // Escolha da mediana entre o primeiro, do meio e o último elemento como pivô
        int meio = (inicio + fim) / 2;
        pivo = calcularMediana(entrada[inicio], entrada[meio], entrada[fim - 1]);

        i = inicio;
        j = fim - 1;

        while (i <= j) {
            while (entrada[i] < pivo && i < fim) {
                i++;
            }
            while (entrada[j] > pivo && j > inicio) {
                j--;
            }
            if (i <= j) {
                aux = entrada[i];
                entrada[i] = entrada[j];
                entrada[j] = aux;
                i++;
                j--;
            }
        }

        if (j > inicio)
            quick_sort_v3(entrada, inicio, j + 1);
        if (i < fim)
            quick_sort_v3(entrada, i, fim);
    }
}
