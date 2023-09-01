#include "Insertion_sort.h"
#include <windows.h>
#include <cstring> // Para a função strcpy
#include <cstdio>
#include <fstream>
using namespace std;

bool existe_diretorio(const char* path){
    DWORD fileAttributes = GetFileAttributesA(path);
    return (fileAttributes != INVALID_FILE_ATTRIBUTES) && (fileAttributes & FILE_ATTRIBUTE_DIRECTORY);
}
void criar_pasta(const char* path){
    if (existe_diretorio(path)) {
        std::cout << "O diretorio existe." << std::endl;
    } else {
        char command[100]; // Ajuste o tamanho conforme necessário
        snprintf(command, sizeof(command), "mkdir \"%s\"", path);
        // Execute o comando usando system()
        system(command);
    }
}


double getTempoAtual(){
    auto agora = chrono::steady_clock::now();
    chrono::duration<double> duracao = agora.time_since_epoch();
    return duracao.count();
}

InsertionSort::InsertionSort(){
}

InsertionSort::~InsertionSort(){}



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

void InsertionSort::salvar_entrada(DadosEntrada entrada){ 
    char entrada_arquivo[200];
    FILE* arquivo = NULL;

        if(entrada.tipo_entrada == CRESCENTE){

        string nome_pasta = "insertion_sort/entradas/entrada_crescente/";
        const char* path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); //confere se tem a pasta criada e cria se nao tiver
        string numStr = to_string(entrada.tamanho);
        nome_pasta += (numStr + ".txt");
        cout << numStr << endl;
        cout << "----------------------" << endl;
        const char* caminho_arquivo = nome_pasta.c_str(); //transformando o caminho do arquivo para char* para ser utilizado na fopen()
        
        arquivo = fopen(caminho_arquivo, "w"); 
        if(arquivo == NULL){cout << "Nao foi possivel abrir o arquivo" << endl;exit(1);}
        sprintf(entrada_arquivo, "%d\n", entrada.tamanho);
        fprintf(arquivo, entrada_arquivo);
        for(int i = 0; i < entrada.tamanho ; i++){
            sprintf(entrada_arquivo, "%d\n", entrada.vector[i]);
            fprintf(arquivo, entrada_arquivo);
        }
        fclose(arquivo);

    }if(entrada.tipo_entrada == DECRESCENTE){                   
        string nome_pasta = "insertion_sort/entradas/entrada_decrescente/";
        const char* path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta);

        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += (numStr + ".txt");

        const char* caminho_arquivo = nome_pasta.c_str(); 
        arquivo = fopen(caminho_arquivo, "w"); 
        if(arquivo == NULL){cout << "Nao foi possivel abrir o arquivo" << endl;exit(1);}
        sprintf(entrada_arquivo, "%d\n", entrada.tamanho);
        fprintf(arquivo, entrada_arquivo);
        for(int i = 0; i < entrada.tamanho ; i++){
            sprintf(entrada_arquivo, "%d\n", entrada.vector[i]);
            fprintf(arquivo, entrada_arquivo);
        }
        fclose(arquivo);

    }else if(entrada.tipo_entrada == RANDOM){
                         
        string nome_pasta = "insertion_sort/entradas/entrada_random/";
        const char* path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta);

        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += (numStr + ".txt");

        const char* caminho_arquivo = nome_pasta.c_str(); 
        arquivo = fopen(caminho_arquivo, "w"); 
        if(arquivo == NULL){cout << "Nao foi possivel abrir o arquivo" << endl;exit(1);}

        sprintf(entrada_arquivo, "%d\n", entrada.tamanho);
        fprintf(arquivo, entrada_arquivo);
        for(int i = 0; i < entrada.tamanho ; i++){
            sprintf(entrada_arquivo, "%d\n", entrada.vector[i]);
            fprintf(arquivo, entrada_arquivo);
        }
        fclose(arquivo);
    }

}

void InsertionSort::salvar_saida(DadosEntrada entrada){ //to do neguin
char entrada_arquivo[200];
    FILE* arquivo = NULL;

    if(entrada.tipo_entrada == CRESCENTE){
                               
        string nome_pasta = "insertion_sort/entradas/entrada_crescente/";
        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += (numStr + "_ordenado.txt");

        const char* caminho_arquivo = nome_pasta.c_str(); 
        arquivo = fopen(caminho_arquivo, "w"); 
        if(arquivo == NULL){cout << "Nao foi possivel abrir o arquivo" << endl;exit(1);}

        for(int i = 0; i < entrada.tamanho ; i++){
            sprintf(entrada_arquivo, "%d\n", entrada.vector[i]);
            fprintf(arquivo, entrada_arquivo);
        }
        fclose(arquivo);

    }else if(entrada.tipo_entrada == DECRESCENTE){                       
        string nome_pasta = "insertion_sort/entradas/entrada_decrescente/";
        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += (numStr + "_ordenado.txt");


        const char* caminho_arquivo = nome_pasta.c_str(); 
        arquivo = fopen(caminho_arquivo, "w"); 
        if(arquivo == NULL){cout << "Nao foi possivel abrir o arquivo" << endl;exit(1);}

        for(int i = 0; i < entrada.tamanho ; i++){
            sprintf(entrada_arquivo, "%d\n", entrada.vector[i]);
            fprintf(arquivo, entrada_arquivo);
        }
        fclose(arquivo);

    }else if(entrada.tipo_entrada == RANDOM){                       
        string nome_pasta = "insertion_sort/entradas/entrada_random/";
        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += (numStr + "_ordenado.txt");


        const char* caminho_arquivo = nome_pasta.c_str(); 
        arquivo = fopen(caminho_arquivo, "w"); 
        if(arquivo == NULL){cout << "Nao foi possivel abrir o arquivo" << endl;exit(1);}

        for(int i = 0; i < entrada.tamanho ; i++){
            sprintf(entrada_arquivo, "%d\n", entrada.vector[i]);
            fprintf(arquivo, entrada_arquivo);
        }
        fclose(arquivo);
    }

}

void InsertionSort::salvar_tempos(DadosEntrada entrada){
    FILE *arq;
    if(entrada.tipo_entrada == CRESCENTE){
        char tempos_execucao[30];
        arq = fopen("insertion_sort/entradas/entrada_crescente/tempo_gasto.txt", "a");
        sprintf(tempos_execucao, "Tempo: %lf Tamanho: %d\n", duracao, entrada.tamanho);
        fprintf(arq, tempos_execucao);
        fclose(arq);
    }else if(entrada.tipo_entrada == DECRESCENTE){
        char tempos_execucao[30];
        arq = fopen("insertion_sort/entradas/entrada_decrescente/tempo_gasto.txt", "a");
        sprintf(tempos_execucao, "Tempo: %lf Tamanho: %d\n", duracao, entrada.tamanho);
        fprintf(arq, tempos_execucao);
        fclose(arq);
    }else if(entrada.tipo_entrada == RANDOM){
        char tempos_execucao[30];
        arq = fopen("insertion_sort/entradas/entrada_random/tempo_gasto.txt", "a");
        sprintf(tempos_execucao, "Tempo: %lf Tamanho: %d\n", duracao, entrada.tamanho);
        fprintf(arq, tempos_execucao);
        fclose(arq);
    }
}



void InsertionSort::exibir_duracao(DadosEntrada entrada){
    printf("\nTempo gasto para vetor de tamanho %d: %lf segundos.\n\n",entrada.tamanho, duracao);
}


void InsertionSort::processar(DadosEntrada *entrada){
    salvar_entrada(*entrada);
    entrada->exibe_vector();
    ordenar(entrada);
    salvar_saida(*entrada);
    entrada->exibe_vector();
    salvar_tempos(*entrada);
    exibir_duracao(*entrada);
}

