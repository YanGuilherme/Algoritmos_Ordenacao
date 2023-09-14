#include "Algoritmos/insertion_sort/Insertion_sort.h"
#include "DadosEntrada.h"
#include "Arquivo.h"
#include "Algoritmos/Algoritmo.h"
#include "Algoritmos/bubble_sort/Bubble_sort.h"

using namespace std;

Algoritmo* selecionarAlgoritimo(){
    int algoritmo;
    printf("Selecione o algoritmo: \n");
    printf("1.Insertion Sort\n");
    printf("2.Bubble Sort\n");
    cout << "Digite: ";
    cin >> algoritmo;
    system("cls");
    switch (algoritmo){
    case 1:
        return new InsertionSort;
    case 2:
        return new BubbleSort;
    default:
        cout << "Comando invalido" << endl;
        break;
    }
    return nullptr;
} 

using namespace std;
int main(){
    Arquivo save;
    DadosEntrada entrada;
    Algoritmo *algoritmo = nullptr;
    int opcao;

    while(true){
        printf("\t-----INICIO-----\n\n");
        printf("1. Escolher algoritmo para ordenar um vetor\n");
        printf("2. Apagar pastas geradas\n");
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
                entrada.escolha_entrada();
                system("cls");
                entrada.make_vector();
                save.salvar_entrada(algoritmo->nome, entrada); //        save.salvar_entrada(algortimo, entrada); 
                algoritmo->ordenar(&entrada);
                save.salvar_saida(algoritmo->nome, entrada);
                save.salvar_tempo(algoritmo->nome, entrada, algoritmo->duracao);
                cout << entrada.tamanho << " - pronto!" << endl;
                entrada.destroy_vector();
            } else if(opcao == 7){
                entrada.escolha_entrada();
                system("cls");
                for(int i = 1; i < 6 ; i++){
                    entrada.escolha_tamanho(i);
                    entrada.make_vector();
                    save.salvar_entrada(algoritmo->nome, entrada);
                    algoritmo->ordenar(&entrada);
                    save.salvar_saida(algoritmo->nome, entrada);
                    save.salvar_tempo(algoritmo->nome, entrada, algoritmo->duracao);
                    cout << entrada.tamanho << " - pronto!" << endl;
                    entrada.destroy_vector();
                }
            }
        }else if(opcao == 2){
            system("apagar_pastas.bat");
        }else if(opcao == 0){
            exit(1);
            }
        else{
            cout << "Entrada invalida.\n";
        }
    }
    return 0;
}
