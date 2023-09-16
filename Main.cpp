#include "Algoritmos/insertion_sort/Insertion_sort.h"
#include "DadosEntrada.h"
#include "Arquivo.h"
#include "Algoritmos/Algoritmo.h"
#include "Algoritmos/bubble_sortv1/Bubble_sortv1.h"
#include "Algoritmos/bubble_sortv2/Bubble_sortv2.h"
#include "Algoritmos/selection_sort/Selection_sort.h"
#include "Algoritmos/shell_sort/Shell_sort.h"
#include "Algoritmos/merge_sort/Merge_sort.h"



using namespace std;

Algoritmo* selecionarAlgoritimo(){
    int algoritmo;
    cout << "Selecione o algoritmo:" << endl;
    cout << "1. Insertion Sort" << endl;
    cout << "2. Bubble Sort (nao otimizado)" << endl;
    cout << "3. Bubble Sort (otimizado)" << endl;
    cout << "4. Selection Sort" << endl;
    cout << "5. Shell Sort" << endl;
    cout << "6. Merge Sort" << endl;
    cout << "Digite: ";
    cin >> algoritmo;
    system("cls");
    switch (algoritmo){
    case 1:
        return new InsertionSort;
        break;
    case 2:
        return new BubbleSortv1;
        break;
    case 3:
        return new BubbleSortv2;
        break;
    case 4:
        return new SelectionSort;
        break;
    case 5:
        return new ShellSort;
        break;
    case 6:
        return new MergeSort;
        break;
    default:
        cout << "Comando invalido" << endl;
        break;
    }
    return nullptr;
} 

void processar(DadosEntrada entrada, Algoritmo* algoritmo, Arquivo save){
    entrada.make_vector();
    save.salvar_entrada(algoritmo->nome, entrada); //        save.salvar_entrada(algortimo, entrada); 
    algoritmo->ordenar(&entrada);
    save.salvar_saida(algoritmo->nome, entrada);
    save.salvar_tempo(algoritmo->nome, entrada, algoritmo->duracao);
    cout << entrada.tamanho << " - " << entrada.tipo << " - pronto!" << endl;
    entrada.destroy_vector();
}

using namespace std;
int main(){
    Arquivo save;
    DadosEntrada entrada;
    Algoritmo *algoritmo = nullptr;
    int opcao;

    while(true){
        system("cls");
        printf("\t\t-----INICIO-----\n\n");
        printf("1. Escolher algoritmo para ordenar um vetor\n");
        printf("2. Apagar pastas geradas\n");
        cout << "3. Visualizar tempos" << endl;
        printf("0. Sair do programa\n");
        printf("Digite: ");
        cin >> opcao;
        system("cls");


        if(opcao == 1){
            algoritmo = selecionarAlgoritimo();
            printf("Digite o tamanho da entrada que deseja dentre as opcoes: \n");
            printf("1. 10\n2. 100\n3. 1000\n4. 10000\n5. 100000\n6. 1000000\n7. Todos os tamanhos acima.\n"); 
            printf("Digite: ");
            cin >> opcao;
            system("cls");
            if(opcao <= 6 && opcao > 0){
                entrada.escolha_tamanho(opcao);
                int escolha_tipo;
                printf("Digite o tipo de entrada dentre as opcoes:\n");
                printf("1. Crescente\n2. Decrescente\n3. Random\n4. Todos os tipos\n");
                printf("Digite: ");
                cin >> escolha_tipo ;
                if(escolha_tipo == 4){
                    for(int i = 1; i < 4; i++){
                        entrada.escolha_tipo_entrada(i);
                        processar(entrada, algoritmo, save);
                    }
                cout << endl;
                }else{
                    entrada.escolha_tipo_entrada(escolha_tipo);
                    processar(entrada, algoritmo, save);
                }
                cout << endl;


            } else if(opcao == 7){
                int escolha_tipo;
                printf("Digite o tipo de entrada dentre as opcoes:\n");
                printf("1. Crescente\n2. Decrescente\n3. Random\n4. Todos os tipos\n");
                printf("Digite: ");
                cin >> escolha_tipo ;
                if(escolha_tipo == 4){
                    for(int i = 1; i < 4; i++){//itera sobre todos os tipos 
                    entrada.escolha_tipo_entrada(i);
                    for(int i = 1; i < 7 ; i++){ //itera sobre todos os tamanhos de entrada
                        entrada.escolha_tamanho(i);
                        processar(entrada, algoritmo, save);
                        }
                    }
                cout << endl;
                }else{
                    entrada.escolha_tipo_entrada(escolha_tipo);
                    for(int i = 1; i < 7 ; i++){//itera sobre todos os tamanhos de entrada
                    entrada.escolha_tamanho(i);
                    processar(entrada, algoritmo, save);
                    }
                }
                cout << endl;
            }


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
        }else if(opcao == 0){
            exit(1);
        }else{
            cout << "Entrada invalida.\n";
        }
    }
    return 0;
}
