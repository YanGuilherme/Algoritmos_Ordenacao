#include "Arquivo.h"


using namespace std;

const char* DIRETORIO_RAIZ = "Arquivos_IO/";

void Arquivo::salvar_entrada(string nome_algorithm, DadosEntrada entrada){
    char entrada_arquivo[200];
    FILE* arquivo = NULL;
    const char* caminho_arquivo;
    string nome_pasta;
    const char* path_pasta;
    if(entrada.tipo_entrada == CRESCENTE){
        nome_pasta = DIRETORIO_RAIZ + (nome_algorithm + "/arquivos_entrada/crescente/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); 
        string numStr = to_string(entrada.tamanho);
        nome_pasta += ("entrada_crescente_" + numStr + ".txt");

    }if(entrada.tipo_entrada == DECRESCENTE){                   
        nome_pasta = DIRETORIO_RAIZ + (nome_algorithm + "/arquivos_entrada/decrescente/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); 
    
        string numStr = std::to_string(entrada.tamanho);
        nome_pasta += ("entrada_decrescente_" + numStr + ".txt");


    }else if(entrada.tipo_entrada == RANDOM){
        nome_pasta = DIRETORIO_RAIZ + (nome_algorithm + "/arquivos_entrada/random/");
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
        nome_pasta = DIRETORIO_RAIZ + (nome_algorithm + "/arquivos_saida/crescente/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); 
        tamanho_Str = std::to_string(entrada.tamanho);
        nome_pasta += ("saida_crescente_" + tamanho_Str + ".txt");

    }else if(entrada.tipo_entrada == DECRESCENTE){                       
        nome_pasta = DIRETORIO_RAIZ + (nome_algorithm + "/arquivos_saida/decrescente/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); 
        tamanho_Str = std::to_string(entrada.tamanho);
        nome_pasta += ("saida_decrescente_" + tamanho_Str + ".txt");


    }else if(entrada.tipo_entrada == RANDOM){                       
        nome_pasta = DIRETORIO_RAIZ + (nome_algorithm + "/arquivos_saida/random/");
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
    char tempos_execucao[100];
    string nome_pasta;
    const char* path_pasta;
    const char* caminho_arquivo;
    string tamanho_Str;


    if(entrada.tipo_entrada == CRESCENTE){
        nome_pasta = DIRETORIO_RAIZ + (nome_algorithm + "/arquivos_tempo/crescente/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); 
        tamanho_Str = to_string(entrada.tamanho);
        nome_pasta += ("tempo_crescente_" + tamanho_Str + ".txt");
    }else if(entrada.tipo_entrada == DECRESCENTE){
        nome_pasta = DIRETORIO_RAIZ + (nome_algorithm + "/arquivos_tempo/decrescente/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); 
        tamanho_Str = to_string(entrada.tamanho);
        nome_pasta += ("tempo_decrescente_" + tamanho_Str + ".txt");
    }else if(entrada.tipo_entrada == RANDOM){
        nome_pasta = DIRETORIO_RAIZ + (nome_algorithm + "/arquivos_tempo/random/");
        path_pasta = nome_pasta.c_str();
        criar_pasta(path_pasta); 
        tamanho_Str = to_string(entrada.tamanho);
        nome_pasta += ("tempo_random_" + tamanho_Str + ".txt");

    }

    caminho_arquivo = nome_pasta.c_str();
    arq = fopen(caminho_arquivo, "a");
    sprintf(tempos_execucao, "Tempo: %lf Tamanho: %d\n", abs(duracao), entrada.tamanho);
    fprintf(arq,"%s", tempos_execucao);
    fclose(arq);

}

bool existe_diretorio(const char* path){
    DWORD fileAttributes = GetFileAttributesA(path);
    return (fileAttributes != INVALID_FILE_ATTRIBUTES) && (fileAttributes & FILE_ATTRIBUTE_DIRECTORY);
}

void Arquivo::criar_pasta(const char* path){
    if (existe_diretorio(path)) {
    } else {
        char command[100]; // Ajuste o tamanho conforme necessário
        snprintf(command, sizeof(command), "mkdir \"%s\"", path);
        system(command);
    }
}

bool listarDiretoriosExistents(const char* rootPath, std::vector<std::string>& diretorios) {
    string searchPath = string(rootPath) + "\\*";

    WIN32_FIND_DATAA findFileData;
    HANDLE hFind = FindFirstFileA(searchPath.c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        cout << "Nenhum diretorio encontrado." << endl;
        return false;
    }

    do {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
                diretorios.push_back(findFileData.cFileName);
            }
        }
    } while (FindNextFileA(hFind, &findFileData) != 0);

    FindClose(hFind);
    return true;
}

void Arquivo::apagar_pasta_especifica(){
    const char* rootPath = "Arquivos_IO";
    vector<string> diretorios;
    if (listarDiretoriosExistents(rootPath, diretorios)) {
        cout << "Diretorios existentes em " << rootPath << ":" << endl;
    for (size_t i = 0; i < diretorios.size(); ++i) {
        cout << i + 1 << ". " << diretorios[i] << endl;
        }
    }

    cout << "Escolha o diretorio a ser apagado (0 para sair): ";
    int escolha;
    cin >> escolha;
    if (escolha > 0 && escolha <= static_cast<int>(diretorios.size())) {
        string dirPath = string(rootPath) + "\\" + diretorios[escolha - 1];
        cout << "Apagando o diretorio " << dirPath << "..." << endl;
        string command = "rmdir /s /q \"" + dirPath + "\"";
        system(command.c_str());
    }

}

void exibirConteudoArquivoTxt(const string& filePath) {
    ifstream arquivo(filePath);

    if (!arquivo.is_open()) {
        return;
    }

    string linha;
    while (getline(arquivo, linha)) {
        cout << linha << endl;
    }
    arquivo.close();
}

void listarArquivosTxt(const string& dirPath, string tipo_entrada) {
    // Abre o diretório
    DIR* directory = opendir(dirPath.c_str());
    
    if (directory == nullptr) {
        return;
    }
    cout << "Tempo " + tipo_entrada << ":" << endl;
    struct dirent* entry;
    while ((entry = readdir(directory)) != nullptr) {
        string fileName = entry->d_name;
        
        // Verifica se o arquivo possui extensão .txt
        if (fileName.length() > 4 && fileName.substr(fileName.length() - 4) == ".txt") {

            string filePath = dirPath + "\\" + fileName;
            exibirConteudoArquivoTxt(filePath);
        }
    }

    // Fecha o diretório
    closedir(directory);
}

void Arquivo::visualizar_tempos(){
    const char* rootPath = "Arquivos_IO";
    vector<string> diretorios;
    string num;

    if (listarDiretoriosExistents(rootPath, diretorios)) {
        cout << "Diretorios disponiveis para visualizacao: " << endl;
        for (size_t i = 0; i < diretorios.size(); ++i) {
            cout << i + 1 << ". " << diretorios[i] << endl;
            }
        }
    cout << "Escolha o algoritmo para ser visualizado (0 para sair): ";
    int escolha;
    cin >> escolha;
    if (escolha > 0 && escolha <= static_cast<int>(diretorios.size())) {
        string dirPath = string(rootPath) + "\\" + diretorios[escolha - 1];
        dirPath += "\\arquivos_tempo"; // Adiciona "arquivos_tempo" ao caminho
        cout << "Diretorio: " << dirPath << endl << endl;
        
        // Listar arquivos .txt dentro das subpastas
        listarArquivosTxt(dirPath + "\\crescente", "crescente");
        cout << endl;
        listarArquivosTxt(dirPath + "\\decrescente", "decrescente");
        cout << endl;
        listarArquivosTxt(dirPath + "\\random", "random");
        system("pause");
    }

}
