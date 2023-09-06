#include "Arquivo.h"


using namespace std;


void Arquivo::salvar_entrada(DadosEntrada entrada){
    char entrada_arquivo[200];
    FILE* arquivo = NULL;
    if(entrada.tipo_entrada == CRESCENTE){
        string nome_pasta = "insertion_sort/arquivos_entrada/crescente/";
        const char* path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); //confere se tem a pasta criada e cria se nao tiver
        string numStr = to_string(entrada.tamanho);
        nome_pasta += ("entrada_crescente_" + numStr + ".txt");
        const char* caminho_arquivo = nome_pasta.c_str(); //transformando o caminho do arquivo para char* para ser utilizado na fopen()
        
        arquivo = fopen(caminho_arquivo, "w"); 
        if(arquivo == NULL){cout << "Nao foi possivel abrir o arquivo" << endl;exit(1);}
        sprintf(entrada_arquivo, "%d\n", entrada.tamanho);
        fprintf(arquivo,"%s", entrada_arquivo);
        for(int i = 0; i < entrada.tamanho ; i++){
            sprintf(entrada_arquivo, "%d\n", entrada.vector[i]);
            fprintf(arquivo,"%s", entrada_arquivo);
        }
        fclose(arquivo);

    }if(entrada.tipo_entrada == DECRESCENTE){                   
        string nome_pasta = "insertion_sort/arquivos_entrada/decrescente/";
        const char* path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta);

        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += ("entrada_decrescente_" + numStr + ".txt");

        const char* caminho_arquivo = nome_pasta.c_str(); 
        arquivo = fopen(caminho_arquivo, "w"); 
        if(arquivo == NULL){cout << "Nao foi possivel abrir o arquivo" << endl;exit(1);}
        sprintf(entrada_arquivo, "%d\n", entrada.tamanho);
        fprintf(arquivo,"%s", entrada_arquivo);
        for(int i = 0; i < entrada.tamanho ; i++){
            sprintf(entrada_arquivo, "%d\n", entrada.vector[i]);
            fprintf(arquivo,"%s", entrada_arquivo);
        }
        fclose(arquivo);

    }else if(entrada.tipo_entrada == RANDOM){
                         
        string nome_pasta = "insertion_sort/arquivos_entrada/random/";
        const char* path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta);

        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += ("entrada_random_" + numStr + ".txt");

        const char* caminho_arquivo = nome_pasta.c_str(); 
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

}

void Arquivo::salvar_saida(DadosEntrada entrada){ //to do neguin
char entrada_arquivo[200];
    FILE* arquivo = NULL;

    if(entrada.tipo_entrada == CRESCENTE){                       
        string nome_pasta = "insertion_sort/arquivos_saida/crescente/";
        const char* path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); //confere se tem a pasta criada e cria se nao tiver
        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += ("saida_crescente_" + numStr + ".txt");

        const char* caminho_arquivo = nome_pasta.c_str(); 
        arquivo = fopen(caminho_arquivo, "w"); 
        if(arquivo == NULL){cout << "Nao foi possivel abrir o arquivo" << endl;exit(1);}

        for(int i = 0; i < entrada.tamanho ; i++){
            sprintf(entrada_arquivo, "%d\n", entrada.vector[i]);
            fprintf(arquivo,"%s", entrada_arquivo);
        }
        fclose(arquivo);

    }else if(entrada.tipo_entrada == DECRESCENTE){                       
        string nome_pasta = "insertion_sort/arquivos_saida/decrescente/";
        const char* path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); //confere se tem a pasta criada e cria se nao tiver
        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += ("saida_decrescente_" + numStr + ".txt");


        const char* caminho_arquivo = nome_pasta.c_str(); 
        arquivo = fopen(caminho_arquivo, "w"); 
        if(arquivo == NULL){cout << "Nao foi possivel abrir o arquivo" << endl;exit(1);}

        for(int i = 0; i < entrada.tamanho ; i++){
            sprintf(entrada_arquivo, "%d\n", entrada.vector[i]);
            fprintf(arquivo,"%s", entrada_arquivo);
        }
        fclose(arquivo);

    }else if(entrada.tipo_entrada == RANDOM){                       
        string nome_pasta = "insertion_sort/arquivos_saida/random/";
        const char* path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); //confere se tem a pasta criada e cria se nao tiver
        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += ("saida_random_" + numStr + ".txt");


        const char* caminho_arquivo = nome_pasta.c_str(); 
        arquivo = fopen(caminho_arquivo, "w"); 
        if(arquivo == NULL){cout << "Nao foi possivel abrir o arquivo" << endl;exit(1);}

        for(int i = 0; i < entrada.tamanho ; i++){
            sprintf(entrada_arquivo, "%d\n", entrada.vector[i]);
            fprintf(arquivo,"%s", entrada_arquivo);
        }
        fclose(arquivo);
    }

}

void Arquivo::salvar_tempo(DadosEntrada entrada, double duracao){
    FILE *arq;
    if(entrada.tipo_entrada == CRESCENTE){
        char tempos_execucao[50];

        string nome_pasta = "insertion_sort/arquivos_tempo/crescente/";
        const char* path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); //confere se tem a pasta criada e cria se nao tiver

        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += ("tempo_crescente_" + numStr + ".txt");
        const char* caminho_arquivo = nome_pasta.c_str();

        arq = fopen(caminho_arquivo, "a");
        sprintf(tempos_execucao, "Tempo: %lf Tamanho: %d\n", duracao, entrada.tamanho);
        fprintf(arq,"%s", tempos_execucao);
        fclose(arq);
    }else if(entrada.tipo_entrada == DECRESCENTE){
        char tempos_execucao[50];
        string nome_pasta = "insertion_sort/arquivos_tempo/decrescente/";
        const char* path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); //confere se tem a pasta criada e cria se nao tiver

        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += ("tempo_decrescente_" + numStr + ".txt");
        const char* caminho_arquivo = nome_pasta.c_str();

        arq = fopen(caminho_arquivo, "a");
        sprintf(tempos_execucao, "Tempo: %lf Tamanho: %d\n", duracao, entrada.tamanho);
        fprintf(arq,"%s", tempos_execucao);
        fclose(arq);
    }else if(entrada.tipo_entrada == RANDOM){
        char tempos_execucao[50];
        string nome_pasta = "insertion_sort/arquivos_tempo/random/";
        const char* path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); //confere se tem a pasta criada e cria se nao tiver

        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += ("tempo_random_" + numStr + ".txt");
        const char* caminho_arquivo = nome_pasta.c_str();

        arq = fopen(caminho_arquivo, "a");
        sprintf(tempos_execucao, "Tempo: %lf Tamanho: %d\n", duracao, entrada.tamanho);
        fprintf(arq,"%s", tempos_execucao);
        fclose(arq);
    }
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


