#include "insertion_sort/Insertion_sort.h"
#include "DadosEntrada.h"
#include "Arquivo.h"

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
    return nullptr;
} 

using namespace std;
int main(){
    Arquivo save;
    DadosEntrada entrada;
    Algoritmo *algoritmo;
    algoritmo = selecionarAlgoritimo();
    int opcao;
    printf("Digite o tamanho da entrada que deseja dentre as opcoes: \n");
    printf("1. 10\n2. 100\n3. 1000\n4. 10000\n5. 100000\n6. 1000000\n7. Todos os tamanhos acima.\n"); 
    scanf("%d", &opcao);
    if(opcao <= 6 && opcao > 0){
        entrada.escolha_tamanho(opcao);
        entrada.escolha_entrada();
        entrada.make_vector();
        save.salvar_entrada(entrada);
        algoritmo->ordenar(&entrada);
        save.salvar_saida(entrada);
        save.salvar_tempo(entrada, algoritmo->duracao);
        cout << entrada.tamanho << " - pronto!" << endl;
        entrada.destroy_vector();
    } else if(opcao == 7){
        entrada.escolha_entrada();
        for(int i = 1; i < 7 ; i++){
            entrada.escolha_tamanho(i);
            entrada.make_vector();
            save.salvar_entrada(entrada);
            algoritmo->ordenar(&entrada);
            save.salvar_saida(entrada);
            save.salvar_tempo(entrada, algoritmo->duracao);
            cout << entrada.tamanho << " - pronto!" << endl;
            entrada.destroy_vector();
        }
    } else {
        cout << "Entrada invalida.\n";
    }
    return 0;

}
