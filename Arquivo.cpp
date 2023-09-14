#include "Arquivo.h"


using namespace std;


void Arquivo::salvar_entrada(string nome_algorithm, DadosEntrada entrada){
    char entrada_arquivo[200];
    FILE* arquivo = NULL;
    const char* caminho_arquivo;
    string nome_pasta;
    const char* path_pasta;
    if(entrada.tipo_entrada == CRESCENTE){
        nome_pasta = "Algoritmos/" + (nome_algorithm + "/arquivos_entrada/crescente/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); 
        string numStr = to_string(entrada.tamanho);
        nome_pasta += ("entrada_crescente_" + numStr + ".txt");

    }if(entrada.tipo_entrada == DECRESCENTE){                   
        nome_pasta = "Algoritmos/" + (nome_algorithm + "/arquivos_entrada/decrescente/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); 
    
        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += ("entrada_decrescente_" + numStr + ".txt");


    }else if(entrada.tipo_entrada == RANDOM){
        nome_pasta = "Algoritmos/" + (nome_algorithm + "/arquivos_entrada/random/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); 
        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += ("entrada_random_" + numStr + ".txt");

    }
    caminho_arquivo = nome_pasta.c_str();  
    arquivo = fopen(caminho_arquivo, "w"); 
    if(arquivo == NULL){cout << "Nao foi possivel abrir o arquivo" << endl;exit(1);}
    sprintf(entrada_arquivo, "%d\n", entrada.tamanho);
    fprintf(arquivo,"%s", entrada_arquivo);
    for(int i = 0; i < entrada.tamanho ; i++){
        sprintf(entrada_arquivo, "%d\n", entrada.vector[i]);
        fprintf(arquivo,"%s", entrada_arquivo);
    }
    fclose(arquivo);

}

void Arquivo::salvar_saida(string nome_algorithm, DadosEntrada entrada){ //to do neguin
    char entrada_arquivo[200];
    FILE* arquivo = NULL;
    const char* path_pasta;
    const char* caminho_arquivo;
    string nome_pasta;
    string tamanho_Str;

    if(entrada.tipo_entrada == CRESCENTE){                       
        nome_pasta = "Algoritmos/" + (nome_algorithm + "/arquivos_saida/crescente/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); 
        tamanho_Str = std::to_string(entrada.tamanho);
        nome_pasta += ("saida_crescente_" + tamanho_Str + ".txt");

    }else if(entrada.tipo_entrada == DECRESCENTE){                       
        nome_pasta = "Algoritmos/" + (nome_algorithm + "/arquivos_saida/decrescente/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); 
        tamanho_Str = std::to_string(entrada.tamanho);
        nome_pasta += ("saida_decrescente_" + tamanho_Str + ".txt");


    }else if(entrada.tipo_entrada == RANDOM){                       
        nome_pasta = "Algoritmos/" + (nome_algorithm + "/arquivos_saida/random/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); //confere se tem a pasta criada e cria se nao tiver
        tamanho_Str = std::to_string(entrada.tamanho);
        nome_pasta += ("saida_random_" + tamanho_Str + ".txt");
    }

    caminho_arquivo = nome_pasta.c_str(); 
    arquivo = fopen(caminho_arquivo, "w"); 
    if(arquivo == NULL){cout << "Nao foi possivel abrir o arquivo" << endl;exit(1);}

    for(int i = 0; i < entrada.tamanho ; i++){
        sprintf(entrada_arquivo, "%d\n", entrada.vector[i]);
        fprintf(arquivo,"%s", entrada_arquivo);
    }
    fclose(arquivo);


}

void Arquivo::salvar_tempo(string nome_algorithm, DadosEntrada entrada, double duracao){
    FILE *arq;
    char tempos_execucao[50];
    string nome_pasta;
    const char* path_pasta;
    const char* caminho_arquivo;
    string tamanho_Str;

    if(entrada.tipo_entrada == CRESCENTE){
        nome_pasta = "Algoritmos/" + (nome_algorithm + "/arquivos_tempo/crescente/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); 
        tamanho_Str = to_string(entrada.tamanho);
        nome_pasta += ("tempo_crescente_" + tamanho_Str + ".txt");
    }else if(entrada.tipo_entrada == DECRESCENTE){
        nome_pasta = "Algoritmos/" + (nome_algorithm + "/arquivos_tempo/decrescente/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); 
        tamanho_Str = to_string(entrada.tamanho);
        nome_pasta += ("tempo_decrescente_" + tamanho_Str + ".txt");
    }else if(entrada.tipo_entrada == RANDOM){
        nome_pasta = "Algoritmos/" + (nome_algorithm + "/arquivos_tempo/random/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); 
        tamanho_Str = to_string(entrada.tamanho);
        nome_pasta += ("tempo_random_" + tamanho_Str + ".txt");
    }

    caminho_arquivo = nome_pasta.c_str();
    arq = fopen(caminho_arquivo, "a");
    sprintf(tempos_execucao, "Tempo: %lf Tamanho: %d\n", duracao, entrada.tamanho);
    fprintf(arq,"%s", tempos_execucao);
    fclose(arq);
}

bool existe_diretorio(const char* path){
    DWORD fileAttributes = GetFileAttributesA(path);
    return (fileAttributes != INVALID_FILE_ATTRIBUTES) && (fileAttributes & FILE_ATTRIBUTE_DIRECTORY);
}

void Arquivo::criar_pasta(const char* path){
    if (existe_diretorio(path)) {
        //std::cout << "O diretorio existe." << std::endl; //se necessario avisar, só ligar
    } else {
        char command[100]; // Ajuste o tamanho conforme necessário
        snprintf(command, sizeof(command), "mkdir \"%s\"", path);
        // Execute o comando usando system()
        system(command);
    }
}


