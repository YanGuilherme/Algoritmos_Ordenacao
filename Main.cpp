
#include "DadosEntrada.h"
#include "Arquivo.h"
#include "Algoritmos/Algoritmo.h"
#include "Algoritmos/heap_sort/Heap_min.h"
#include "Algoritmos/heap_sort/Heap_minimum.h"
#include "Algoritmos/heap_sort/Heap_sort_min.h"
#include <vector>

using namespace std;



vector<Algoritmo*> selecionarAlgoritimo(){
    vector<Algoritmo*> vetorDeAlgoritmos;
    int algoritmo;
    cout << "Escolha a operacao:" << endl;
    cout << "|1|. HeapSort (Minimum)" << endl;
    cout << "|2|. Heap Minimum (show)" << endl;
    cout << "|3|. Heap Extract Minimo" << endl;
    cout << "|4|. Heap Increase Key" << endl;
    cout << "|5|. Max Heap Insert" << endl;
    cout << "Digite a opcao: ";
    cin >> algoritmo;
    system("cls");
    switch (algoritmo){
    case 1:
        vetorDeAlgoritmos.push_back(new HeapSortMin);
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        cout << "Comando invalido" << endl;
        break;
    }
    return vetorDeAlgoritmos;
} 

vector<int> selecionarTamanhos(){
    vector<int> vetorDeTamanhos;
    int opcao_tamanho, tamanho_escolhido;
    cout << "Selecione o tamanho:" << endl;
    cout << "|1|. 10" << endl;
    cout << "|2|. 100" << endl;
    cout << "|3|. 1000" << endl;
    cout << "|4|. 10000" << endl;
    cout << "|5|. 100000" << endl;
    cout << "|6|. 1000000" << endl;
    cout << "|7|. Todos acima." << endl;
    cout << "|8|. Digitar valor." << endl;
    cout << "Digite a opcao: ";
    cin >> opcao_tamanho;
    system("cls");
    switch (opcao_tamanho){
    case 1:
        vetorDeTamanhos.push_back(10);
        break;
    case 2:
        vetorDeTamanhos.push_back(100);
        break;
    case 3:
        vetorDeTamanhos.push_back(1000);
        break;
    case 4:
        vetorDeTamanhos.push_back(10000);
        break;
    case 5:
        vetorDeTamanhos.push_back(100000);
        break;
    case 6:
        vetorDeTamanhos.push_back(1000000);
        break;
    case 7:
        vetorDeTamanhos.push_back(10);
        vetorDeTamanhos.push_back(100);
        vetorDeTamanhos.push_back(1000);
        vetorDeTamanhos.push_back(10000);
        vetorDeTamanhos.push_back(100000);
        vetorDeTamanhos.push_back(1000000);
        break;

    case 8:
        cout << "Digite o tamanho do vetor: " ;
        cin >> tamanho_escolhido;
        vetorDeTamanhos.push_back(tamanho_escolhido);
        system("cls");
        break;
    default:
        cout << "Comando invalido!" << endl;
        break;
    }
    return vetorDeTamanhos;
} 

vector<TipoEntrada> selecionarTiposEntrada(){
    vector<TipoEntrada> vetorDeTipos;
    int tamanho;
    cout << "Selecione o tipo:" << endl;
    cout << "|1|. Crescente" << endl;
    cout << "|2|. Decrescente" << endl;
    cout << "|3|. Aleatorio" << endl;
    cout << "|4|. Todos" << endl;
    cout << "Digite a opcao: ";
    cin >> tamanho;
    system("cls");
    switch (tamanho){
    case 1:
        vetorDeTipos.push_back(CRESCENTE);
        break;
    case 2:
        vetorDeTipos.push_back(DECRESCENTE);
        break;
    case 3:
        vetorDeTipos.push_back(RANDOM);
        break;
    case 4:
        vetorDeTipos.push_back(CRESCENTE);
        vetorDeTipos.push_back(DECRESCENTE);
        vetorDeTipos.push_back(RANDOM);
        break;
       
    default:
        cout << "Comando invalido!" << endl;
        break;
    }
    return vetorDeTipos;
} 

void processar(DadosEntrada entrada, Algoritmo* algoritmo){
    entrada.make_vector();
    Arquivo::salvar_entrada(algoritmo->getNome(), entrada); //        save.salvar_entrada(algortimo, entrada); 
    algoritmo->executar(&entrada);
    Arquivo::salvar_saida(algoritmo->getNome(), entrada);
    Arquivo::salvar_tempo(algoritmo->getNome(), entrada, abs(algoritmo->duracao));
    cout << entrada.tamanho << " - " << entrada.getTipo() << " - " << algoritmo->getNome() << " - pronto!" << endl;
    entrada.destroy_vector();
}

int main(){
    vector<Algoritmo*> algoritmos;
    int opcao;

    while(true){
        system("cls");
        cout << "\t\t-----INICIO----- " << endl << endl;
        cout << ("|1|. Operacacoes com Heap\n");
        cout << ("|2|. Apagar pastas geradas\n");
        cout << ("|3|. Visualizar tempos") << endl;
        cout << ("|4|. Creditos") << endl;
        cout << ("|0|. Sair do programa\n");
        cout << ("Digite a opcao: ");
        cin >> opcao;
        system("cls");

        if(opcao == 1){
        vector<Algoritmo*> algoritmos = selecionarAlgoritimo();
        vector<int> tamanhos = selecionarTamanhos();
        vector<TipoEntrada> entradas = selecionarTiposEntrada();
        for (Algoritmo* algoritmo : algoritmos) {
            for(int tamanho: tamanhos){
                for(TipoEntrada tipoEntrada: entradas){
                    DadosEntrada entrada = DadosEntrada(tipoEntrada, tamanho);
                    processar(entrada, algoritmo);
                }
                cout << "-----------------------------------------------" << endl;
            }
            cout << "-----------------------------------------------" << endl;
        }
        system("pause");
        
        }else if(opcao == 2){
            cout << "|1|. Escolher uma pasta para apagar" << endl;
            cout << "|2|. Apagar todas as pastas" << endl;
            cout << "|0|. Sair" << endl;
            cout << "Digite a opcao: ";
            int choose;
            cin >> choose;
            if(choose == 1){
                Arquivo::apagar_pasta_especifica();
            }else if(choose == 2){
                system("apagar_pastas.bat");
            }else if(choose == 0){
                cout << " ";
            }else{
                cout << "Opcao invalida." << endl;
            }
            // system("pause");
        }else if(opcao == 3){
            Arquivo::visualizar_tempos();
        }else if(opcao == 4){
            cout << "Trabalho apresentado para obtencao de creditos na disciplina  SIN213 - Projeto de Algoritmos " << endl << "da Universidade Federal de Vicosa - Campus de Rio Paranaiba," << endl << "ministrada pelo Professor Pedro Moises de Souza." << endl;
            cout << "Implementado por: Yan Guilherme Viana Leite - 5992" << endl;
            system("pause");
        }else if(opcao == 0){
            exit(1);
        }else{
            cout << "Entrada invalida!\n";
        }
    }
    for (Algoritmo* algoritmo : algoritmos) {
        delete algoritmo;
    }
    return 0;
}
