#include "Algoritmos/insertion_sort/Insertion_sort.h"
#include "DadosEntrada.h"
#include "Arquivo.h"
#include "Algoritmos/Algoritmo.h"
#include "Algoritmos/bubble_sort/Bubble_sort.h"
#include "Algoritmos/selection_sort/Selection_sort.h"



using namespace std;

Algoritmo* selecionarAlgoritimo(){
    int algoritmo;
    printf("Selecione o algoritmo: \n");
    printf("1.Insertion Sort\n");
    printf("2.Bubble Sort\n");
    printf("3.Selection Sort\n");
    cout << "Digite: ";
    cin >> algoritmo;
    system("cls");
    switch (algoritmo){
    case 1:
        return new InsertionSort;
    case 2:
        return new BubbleSort;
    case 3:
        return new SelectionSort;
    default:
        cout << "Comando invalido" << endl;
        break;
    }
    return nullptr;
} 

void executar(DadosEntrada entrada, Algoritmo* algoritmo, Arquivo save){
    entrada.make_vector();
    save.salvar_entrada(algoritmo->nome, entrada); //        save.salvar_entrada(algortimo, entrada); 
    algoritmo->ordenar(&entrada);
    save.salvar_saida(algoritmo->nome, entrada);
    save.salvar_tempo(algoritmo->nome, entrada, algoritmo->duracao);
    cout << entrada.tamanho << " - pronto!" << endl;
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
        printf("2. Apagar todas as pastas geradas\n");
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
                printf("1. Crescente\n2. Decrescente\n3. Random\n4. Todos os tipos");
                cin >> escolha_tipo ;
                if(escolha_tipo == 4){
                    for(int i = 1; i < 4; i++){
                        entrada.escolha_tipo_entrada(i);
                        executar(entrada, algoritmo, save);
                    }
                cout << endl;
                }else{
                    entrada.escolha_tipo_entrada(escolha_tipo);
                    executar(entrada, algoritmo, save);
                }
                cout << endl;


            } else if(opcao == 7){
                int escolha_tipo;
                printf("Digite o tipo de entrada dentre as opcoes:\n");
                printf("1. Crescente\n2. Decrescente\n3. Random\n4. Todos os tipos\n");
                cin >> escolha_tipo ;
                if(escolha_tipo == 4){
                    for(int i = 1; i < 4; i++){
                    entrada.escolha_tipo_entrada(i);
                    for(int i = 1; i < 5 ; i++){
                        entrada.escolha_tamanho(i);
                        executar(entrada, algoritmo, save);
                        }
                    }
                cout << endl;
                }else{
                    entrada.escolha_tipo_entrada(escolha_tipo);
                    for(int i = 1; i < 5 ; i++){
                    entrada.escolha_tamanho(i);
                    executar(entrada, algoritmo, save);
                    }
                }
                cout << endl;
            }


        }else if(opcao == 2){
            system("apagar_pastas.bat");
        }else if(opcao == 0){
            exit(1);
        }else{
            cout << "Entrada invalida.\n";
        }
    }
    return 0;
}
