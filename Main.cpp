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
    return nullptr;
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
        entrada.escolha_entrada();
        entrada.make_vector();
        algoritmo->processar(&entrada); //Método virtual "processar" chama todos os metodos necessários 
                                        //  para entrada, ordenação e saída, além de salvar tudo em arquivos.
        entrada.destroy_vector();
        cout << entrada.tamanho << " - pronto!" << endl;
    } else if(opcao == 7){
        entrada.escolha_entrada();
        for(int i = 1; i < 7 ; i++){
            entrada.escolha_tamanho(i);
            entrada.make_vector();
            algoritmo->processar(&entrada);
            entrada.destroy_vector();
            cout << entrada.tamanho << " - pronto!" << endl;
        }
    } else {
        cout << "Entrada invalida.\n";
    }
    return 0;

}
