// subdividir o array grande em varios arrayszinhos até ter um elemento em cada array
// depois ir fazendo o caminho contrário até ter o array completamente organizado
// dividir e conquistar
// aeeeeeeeeeeee porra funcionouuu
// Theta(nlogn)

#include <stdio.h>
#define false 0
#define true 1
#define MAX 10
#define erro -1

void merge(int a[], int comeco, int meio, int fim){
    int tamanho_esquerda = meio - comeco + 1;   // é um array só mas é como se tivessem dois, pega o tamanho de cada um
    int tamanho_direita = fim - meio;

    int lista_esquerda[tamanho_esquerda]; // cria duas listas auxiliares pra cada um dos lados
    int lista_direita[tamanho_direita];

    for(int i = 0; i < tamanho_esquerda; i++)   // preenche as duas listas auxiliares com cada lado do array original
        lista_esquerda[i] = a[comeco + i];
    for(int i = 0; i < tamanho_direita; i++)
        lista_direita[i] = a[meio+ 1 + i];

    // agora nos vamos rodar as duas listas menores
    int i = 0;  // i é onde estamos na lista esquerda
    int j = 0;  // j é onde estamos na lista direita
    // k é onde estamos na lista principal (vamos reescrever ela inteira, e tudo bem pois os valores estão salvos nas auxiliares)
    for(int k = comeco; k <= fim; k++) {
        if((i <  tamanho_esquerda) && (j >= tamanho_direita || lista_esquerda[i] <= lista_direita[j])){
            // se(i ainda não passou do limite, e (ou j ja passou do limite ou seja nao tem mais nada acrescentar ou o elemento a esquerda é menor que o elemento a direita)) => coloca o elemento a esquerda na lista (ordenação crescente) pq ele é menorrr
            a[k] = lista_esquerda[i];
            i++;
        }
        else{
            a[k] = lista_direita[j];
            j++;
        }
    }   
}

void merge_sort_recursivo(int a[], int comeco, int fim){
    if(comeco < fim){   // se o fim nao é maior q o começo é pq chegou no final da recursão (as listas sao de elementos unicos)
        int meio = (comeco + fim) /2;   // divide a lista no meio
        merge_sort_recursivo(a, comeco, meio);  //   chama recursivamente pra esquerda
        merge_sort_recursivo(a, meio+1, fim);   //   chama recursivamente pra direita

        merge(a, comeco, meio, fim);
    }
}

void merge_sort(int a[], int tamanho){
    merge_sort_recursivo(a, 0, tamanho-1);
}

int main(){
    int lista[MAX] = {9,0,3,1,5,2,6,4,8,7};
    for(int i = 0; i < MAX; i++)
        printf("%d, ", lista[i]);

    printf("\n");
    merge_sort(lista, MAX);

    for(int i = 0; i < MAX; i++)
        printf("%d, ", lista[i]);

    return 0;
}