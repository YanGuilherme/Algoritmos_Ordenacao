#include "DadosEntrada.h"

using namespace std;
int calcularPotencia(int base, int expoente) {
    if (expoente == 0) {
        return 1;
    }

    int resultado = 1;

    for (int i = 0; i < abs(expoente); i++) {
        resultado *= base;
    }

    return resultado;
}
string DadosEntrada::getTipo(){
    map<TipoEntrada, string> mapaTipoEntrada;
    mapaTipoEntrada[CRESCENTE] = "Crescente";
    mapaTipoEntrada[DECRESCENTE] = "Decrescente";
    mapaTipoEntrada[RANDOM] = "Random";
    return mapaTipoEntrada[tipo_entrada]; 
}
DadosEntrada::DadosEntrada(){
    
}

DadosEntrada::DadosEntrada(TipoEntrada tipoEntrada, int tamanho){
    this->tipo_entrada = tipoEntrada;
    this->tamanho = tamanho;
}

void DadosEntrada::make_vector() {
    vector = (int*)malloc(tamanho * sizeof(int));

    if (tipo_entrada == CRESCENTE) {
        for (int i = 0; i < tamanho; i++) {
            vector[i] = i + 1;
        }
    } else if (tipo_entrada == DECRESCENTE) {
        for (int i = 0; i < tamanho; i++) {
            vector[i] = tamanho - i;
        }
    } else if (tipo_entrada == RANDOM) {
        // Inicializa a semente para a função rand() usando o tempo atual
        srand(time(0));

        for (int i = 0; i < tamanho; i++) {
            vector[i] = rand() % 100000 + 1;
        }
    }
}
void DadosEntrada::exibe_vector(){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vector[i]);
    }
    printf("\n\n");
}

void DadosEntrada::destroy_vector(){
    free(vector);
}

int DadosEntrada::get_tamanho()
{
    return this->tamanho;
}
