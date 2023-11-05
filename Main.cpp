#include "Algoritmos/insertion_sort/Insertion_sort.h"
#include "DadosEntrada.h"
#include "Arquivo.h"
#include "Algoritmos/Algoritmo.h"
#include "Algoritmos/bubble_sortv1/Bubble_sortv1.h"
#include "Algoritmos/bubble_sortv2/Bubble_sortv2.h"
#include "Algoritmos/selection_sort/Selection_sort.h"
#include "Algoritmos/shell_sort/Shell_sort.h"
#include "Algoritmos/merge_sort/Merge_sort.h"
#include "Algoritmos/quick_sort/Quick_sort.h"
#include "Algoritmos/quick_sort_v1/Quick_Sort_v1.h"
#include "Algoritmos/quick_sort_v2/Quick_Sort_v2.h"
#include <vector>

using namespace std;

vector<Algoritmo*> selecionarAlgoritimo(){
    vector<Algoritmo*> vetorDeAlgoritmos;
    int algoritmo;
    cout << "Selecione o algoritmo:" << endl;
    cout << "1. Insertion Sort" << endl;
    cout << "2. Bubble Sort (nao otimizado)" << endl;
    cout << "3. Bubble Sort (otimizado)" << endl;
    cout << "4. Selection Sort" << endl;
    cout << "5. Shell Sort" << endl;
    cout << "6. Merge Sort" << endl;
    cout << "7. Quick Sort" << endl;
    cout << "8. Quick Sort v1 (Pivo inicio)" << endl;
    cout << "9. Quick Sort v2 (Pivo media)" << endl;

    cout << "10. Todos os algoritmos" << endl;
    cout << "Digite: ";
    cin >> algoritmo;
    system("cls");
    switch (algoritmo){
    case 1:
        vetorDeAlgoritmos.push_back(new InsertionSort);
        break;
    case 2:
        vetorDeAlgoritmos.push_back(new BubbleSortv1);
        break;
    case 3:
        vetorDeAlgoritmos.push_back(new BubbleSortv2);
        break;
    case 4:
        vetorDeAlgoritmos.push_back(new SelectionSort);
        break;
    case 5:
        vetorDeAlgoritmos.push_back(new ShellSort);
        break;
    case 6:
        vetorDeAlgoritmos.push_back(new MergeSort);
        break;
    case 7:
        vetorDeAlgoritmos.push_back(new QuickSort);
        break;
    case 8:
        vetorDeAlgoritmos.push_back(new QuickSortV1);
        break;
    case 9:
        vetorDeAlgoritmos.push_back(new QuickSortV2);
        break;

    case 10:
        vetorDeAlgoritmos.push_back(new InsertionSort);
        vetorDeAlgoritmos.push_back(new BubbleSortv1);
        vetorDeAlgoritmos.push_back(new BubbleSortv2);
        vetorDeAlgoritmos.push_back(new SelectionSort);
        vetorDeAlgoritmos.push_back(new ShellSort);
        vetorDeAlgoritmos.push_back(new MergeSort);
        vetorDeAlgoritmos.push_back(new QuickSort);
        vetorDeAlgoritmos.push_back(new QuickSortV1);
        vetorDeAlgoritmos.push_back(new QuickSortV2);
        break;

        
    default:
        cout << "Comando invalido" << endl;
        break;
    }
    return vetorDeAlgoritmos;
} 

vector<int> selecionarTamanhos(){
    vector<int> vetorDeTamanhos;
    int tamanho;
    cout << "Selecione o tamanho:" << endl;
    cout << "1. 10" << endl;
    cout << "2. 100" << endl;
    cout << "3. 1000" << endl;
    cout << "4. 10000" << endl;
    cout << "5. 100000" << endl;
    cout << "6. 1000000" << endl;
    cout << "7. Todos" << endl;
    cout << "Digite: ";
    cin >> tamanho;
    system("cls");
    switch (tamanho){
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
       
    default:
        cout << "Comando invalido" << endl;
        break;
    }
    return vetorDeTamanhos;
} 

vector<TipoEntrada> selecionarTiposEntrada(){
    vector<TipoEntrada> vetorDeTipos;
    int tamanho;
    cout << "Selecione o tipo:" << endl;
    cout << "1. Crescente" << endl;
    cout << "2. Decrescente" << endl;
    cout << "3. Aleatorio" << endl;
    cout << "4. Todos" << endl;
    cout << "Digite: ";
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
        cout << "Comando invalido" << endl;
        break;
    }
    return vetorDeTipos;
} 

void processar(DadosEntrada entrada, Algoritmo* algoritmo, Arquivo save){
    entrada.make_vector();
    save.salvar_entrada(algoritmo->getNome(), entrada); //        save.salvar_entrada(algortimo, entrada); 
    algoritmo->ordenar(&entrada);
    save.salvar_saida(algoritmo->getNome(), entrada);
    save.salvar_tempo(algoritmo->getNome(), entrada, algoritmo->duracao);
    cout << entrada.tamanho << " - " << entrada.getTipo() << " - " << algoritmo->getNome() << " - pronto!" << endl;
    entrada.destroy_vector();
}

int main(){
    Arquivo save;
    
    vector<Algoritmo*> algoritmos;
    int opcao;

    while(true){
        system("cls");
        cout << "\t\t-----INICIO----- " << endl << endl;
        cout << ("1. Escolher algoritmo para ordenar um vetor\n");
        cout << ("2. Apagar pastas geradas\n");
        cout << ("3. Visualizar tempos") << endl;
        cout << ("4. Creditos") << endl;
        cout << ("0. Sair do programa\n");
        cout << ("Digite: ");
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
                    processar(entrada, algoritmo, save);
                }
            }
            cout << endl;
        }
        system("pause");
        
        }else if(opcao == 2){
            cout << "1. Escolher uma pasta para apagar" << endl;
            cout << "2. Apagar todas as pastas" << endl;
            cout << "0. Sair" << endl;
            cout << "Digite: ";
            int choose;
            cin >> choose;
            if(choose == 1){
                save.apagar_pasta_especifica();
            }else if(choose == 2){
                system("apagar_pastas.bat");
            }else if(choose == 0){
                cout << " ";
            }else{
                cout << "Opcao invalida." << endl;
            }
            // system("pause");
        }else if(opcao == 3){
            save.visualizar_tempos();
        }else if(opcao == 4){
            cout << "Trabalho apresentado para obtencao de creditos na disciplina  SIN213 - Projeto de Algoritmos " << endl << "da Universidade Federal de Vicosa - Campus de Rio Paranaiba," << endl << "ministrada pelo Professor Pedro Moises de Souza." << endl;
            cout << "Implementado por: Yan Guilherme Viana Leite - 5992" << endl;
            system("pause");
        }else if(opcao == 0){
            exit(1);
        }else{
            cout << "Entrada invalida.\n";
        }
    }
    for (Algoritmo* algoritmo : algoritmos) {
        delete algoritmo;
    }
    return 0;
}
