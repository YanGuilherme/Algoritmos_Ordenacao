#include "insertion_sort/Insertion_sort.h"
#include "insertion_sort/DadosEntrada.h"

using namespace std;

Algoritmo* selecionarAlgoritimo(){
    int algoritmo;
    printf("Selecione o algoritmo: \n");
    printf("1.Insertion Sort\n");
    scanf("%d", &algoritmo);
    
    switch (algoritmo){
    case 1:
        return new InsertionSort;    
    default:
        cout << "Comando invalido" << endl;
        break;
    }
} 

using namespace std;
int main(){
    
    DadosEntrada entrada;
    Algoritmo *algoritmo;
    algoritmo = selecionarAlgoritimo();
    int opcao;
    printf("Digite o tamanho da entrada que deseja dentre as opcoes: \n");
    printf("1. 10\n2. 100\n3. 1000\n4. 10000\n5. 100000\n6. 1000000\n7. Todos os tamanhos acima.\n"); 
    scanf("%d", &opcao);
    if(opcao <= 6 && opcao > 0){
        entrada.escolha_tamanho(opcao);
        //cout << "Tamanho: " << entrada.tamanho << endl;
        
        entrada.escolha_entrada();
        cout << "Tamanho: " << entrada.tamanho << endl;

        entrada.make_vector();
        cout << "Tamanho: " << entrada.tamanho << endl;

        algoritmo->processar(&entrada);
        cout << "Tamanho: " << entrada.tamanho << endl;

    } else if(opcao == 7){
        entrada.escolha_entrada();
        for(int i = 1; i < 5 ; i++){
            entrada.escolha_tamanho(i);
            entrada.make_vector();
            algoritmo->processar(&entrada);

        }
    } else {
        cout << "Entrada inválida.\n";
    }
    return 0;

}
