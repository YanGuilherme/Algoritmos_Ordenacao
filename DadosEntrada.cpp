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
DadosEntrada::DadosEntrada(){
}

DadosEntrada::DadosEntrada(int t, TipoEntrada name){
    tipo_entrada = name;
}

void DadosEntrada::make_vector(){
    vector = (int*)malloc(tamanho * sizeof(int));

    if(tipo_entrada == CRESCENTE){
            for(int i = 0; i < tamanho; i++){
                vector[i] = i+1;
        }
    }else if(tipo_entrada == DECRESCENTE){
            for(int i = 0; i < tamanho; i++){
                vector[i] = tamanho - i;
        }
    }else if(tipo_entrada == RANDOM){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(1, 100000);

       for(int i = 0; i < tamanho; i++){
           vector[i] = dis(gen);
        }
    }
}

void DadosEntrada::exibe_vector(){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vector[i]);
    }
    printf("\n\n");
}

void DadosEntrada::escolha_tipo_entrada(int b){
    switch (b){
    case 1:
        tipo_entrada = CRESCENTE;
        tipo = "Crescente";
        break;
    case 2:
        tipo_entrada = DECRESCENTE;
        tipo = "Decrescente";
        break;
    case 3:
        tipo_entrada = RANDOM;
        tipo = "Random";
        break;
    default:
        printf("Escolha invalida.\n");
        break;
    }
    // system("clear");

}

void DadosEntrada::escolha_tamanho(int opcao){
    this->tamanho = calcularPotencia(10,opcao);
}

void DadosEntrada::destroy_vector(){
    free(vector);
}
