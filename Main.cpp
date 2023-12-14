
#include "DadosEntrada.h"
#include "Arquivo.h"
#include "Algoritmos/Algoritmo.h"
#include "Algoritmos/heap_sort/Heap_min.h"
#include "Algoritmos/heap_sort/Heap_minimum.h"
#include "Algoritmos/heap_sort/Heap_sort_min.h"
#include "Algoritmos/heap_sort/Heap_extract_min.h"
#include "Algoritmos/heap_sort/Heap_increase_key.h"
#include "Algoritmos/heap_sort/Max_heap_insert.h"
#include "Algoritmos/sort_algorithms/bubble_sortv2/Bubble_sortv2.h"
#include "Algoritmos/sort_algorithms/bubble_sortv1/Bubble_sortv1.h"
#include "Algoritmos/sort_algorithms/insertion_sort/Insertion_sort.h"
#include "Algoritmos/sort_algorithms/merge_sort/Merge_sort.h"
#include "Algoritmos/sort_algorithms/quick_sort_v1/Quick_Sort_v1.h"
#include "Algoritmos/sort_algorithms/quick_sort_v2/Quick_Sort_v2.h"
#include "Algoritmos/sort_algorithms/quick_sort_v3/Quick_Sort_v3.h"
#include "Algoritmos/sort_algorithms/quick_sort_v4/Quick_Sort_v4.h"
#include "Algoritmos/sort_algorithms/selection_sort/Selection_sort.h"
#include "Algoritmos/sort_algorithms/shell_sort/Shell_sort.h"


#include <vector>

using namespace std;

vector<Algoritmo*> selecionarHeaps(){
    vector<Algoritmo*> vetorDeAlgoritmos;
    int algoritmo;
    cout << "Escolha a operacao:" << endl;
    cout << "|1|. HeapSort (Minimum)" << endl;
    cout << "|2|. Heap Minimum (show)" << endl;
    cout << "|3|. Heap Extract Minimo" << endl;
    cout << "|4|. Heap Increase Key" << endl;
    cout << "|5|. Max Heap Insert" << endl;
    cout << "|0|. Sair" << endl;
    cout << "Digite a opcao: ";
    cin >> algoritmo;
    system("cls");
    switch (algoritmo){
    case 1:
        vetorDeAlgoritmos.push_back(new HeapSortMin);
        break;
    case 2:
        vetorDeAlgoritmos.push_back(new HeapMinimum);
        break;
    case 3:
        vetorDeAlgoritmos.push_back(new HeapExtractMin);
        break;
    case 4:
        vetorDeAlgoritmos.push_back(new MaxIncreaseKey);
        break;
    case 5:
        vetorDeAlgoritmos.push_back(new MaxHeapInsert);
        break;
    case 0:
        exit(1);
    default:
        cout << "Comando invalido" << endl;
        break;
    }
    return vetorDeAlgoritmos;
} 


vector<Algoritmo*> selecionarAlgoritimo(){
    vector<Algoritmo*> vetorDeAlgoritmos;
    int algoritmo;
    cout << "Escolha a operacao:" << endl;
    cout << "|1|. Operacacoes com Heap <----- NOVO!" << endl;
    cout << "|2|. Insertion Sort" << endl;
    cout << "|3|. Bubble Sort (versao 1)" << endl;
    cout << "|4|. Bubble Sort (versao 2) otimizado" << endl;
    cout << "|5|. Selection Sort" << endl;
    cout << "|6|. Quick Sort (versao 1) Pivo inicio" << endl;
    cout << "|7|. Quick Sort (versao 2) Pivo media" << endl;
    cout << "|8|. Quick Sort (versao 3) Pivo mediana" << endl;
    cout << "|9|. Quick Sort (versao 4) Pivo aleatorio" << endl;
    cout << "|10|. Shell Sort" << endl;
    cout << "|11|. Merge Sort" << endl;
    cout << "|12| Todos (2 a 11)" << endl;
    cout << "|0|. Sair" << endl;
    cout << "Digite a opcao: ";
    cin >> algoritmo;
    system("cls");
    switch (algoritmo){
    case 1:
        vetorDeAlgoritmos = selecionarHeaps();
        break;
    case 2:
        vetorDeAlgoritmos.push_back(new InsertionSort);
        break;
    case 3:
        vetorDeAlgoritmos.push_back(new BubbleSortv1);
        break;
    case 4:
        vetorDeAlgoritmos.push_back(new BubbleSortv2);
        break;
    case 5:
        vetorDeAlgoritmos.push_back(new SelectionSort);
        break;
    case 6:
        vetorDeAlgoritmos.push_back(new QuickSortV1);
        break;
    case 7:
        vetorDeAlgoritmos.push_back(new QuickSortV2);
        break;
    case 8:
        vetorDeAlgoritmos.push_back(new QuickSortV3);
        break;
    case 9:
        vetorDeAlgoritmos.push_back(new QuickSortV4);
        break;
    case 10:
        vetorDeAlgoritmos.push_back(new ShellSort);
        break;
    case 11:
        vetorDeAlgoritmos.push_back(new MergeSort);
        break;
    case 12:
        vetorDeAlgoritmos.push_back(new InsertionSort);
        vetorDeAlgoritmos.push_back(new BubbleSortv1);
        vetorDeAlgoritmos.push_back(new BubbleSortv2);
        vetorDeAlgoritmos.push_back(new SelectionSort);
        vetorDeAlgoritmos.push_back(new QuickSortV1);
        vetorDeAlgoritmos.push_back(new QuickSortV2);
        vetorDeAlgoritmos.push_back(new QuickSortV3);
        vetorDeAlgoritmos.push_back(new QuickSortV4);
        vetorDeAlgoritmos.push_back(new ShellSort);
        vetorDeAlgoritmos.push_back(new MergeSort);
        break;

    case 0:
        exit(1);
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
    cout << "|3|. 1.000" << endl;
    cout << "|4|. 10.000" << endl;
    cout << "|5|. 100.000" << endl;
    cout << "|6|. 1.000.000" << endl;
    cout << "|7|. Todos acima." << endl;
    cout << "|8|. Digitar valor." << endl;
    cout << "|0|. Sair" << endl;
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
    case 0:
        exit(1);
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
    cout << "|0|. Sair" << endl;
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
    case 0:
        exit(1);
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
    cout <<"Tamanho: "<< entrada.tamanho << " - " <<"Tipo: "<< entrada.getTipo() << " - " << algoritmo->getNome() << " - pronto!" << endl;
    // cout << "--------------------------------------------------------------" << endl;

    entrada.destroy_vector();
}

int main(){
    vector<Algoritmo*> algoritmos;
    int opcao;

    while(true){
        system("cls");
        cout << "\t\t-----INICIO----- " << endl << endl;
        cout << ("|1|. -----> Algoritmos <-----\n");
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
                    // cout << "--------------------------------------------------------------" << endl;
                }
                cout << "--------------------------------------------------------------" << endl;
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
