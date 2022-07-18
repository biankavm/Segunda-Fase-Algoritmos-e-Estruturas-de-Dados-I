/* Algoritmo Merge Sort*/

/*Função para intercalar elementos*/
# include <stdio.h>
# include <stdlib.h>
void intercalacao(int v[], int inicio, int meio, int fim, int aux[]){
    int i = inicio, j = meio+1, k = inicio;
    while((i <= meio) && (j <= fim)){
        if(v[i] < v[j]){
            aux[k] = v[i];
            i++;
        }
        else{
            aux[k] = v[j];
            j++;
        }
        k++;
    }
    while(i <= meio){
        aux[k] = v[i];
        i++;
        k++;
    } 
    while(j <= fim){
        aux[k] = v[j];
        j++;
        k++;
    }
    // Devolver os elementos para o vetor original!
    for (i = inicio; i <= fim; i++){
        v[i] = aux[i];
    }

}

void mergeSortR(int v[], int inicio, int fim, int aux[]){
    int meio;
    if(inicio < fim){
        meio = (inicio+fim) / 2;
        mergeSortR(v, inicio, meio, aux);
        mergeSortR(v, meio+1, fim, aux);
        intercalacao(v, inicio, meio, fim, aux );
    }
}

void mergeSort(int v[], unsigned tam){
    int *aux;
    aux = (int*) malloc(sizeof(int) * tam); // aloca-se memória para a criação do vetor auxiliar.
    mergeSortR(v, 0, tam-1, aux);
    free(aux); // desaloca a memória.
}

void mostraVetor(int v[], unsigned tam){
    int i;
    for (i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
}



int main(){
    int i, tamanho;
    printf("Entre com o tamanho do vetor para ordenar: \n");
    scanf("%d", &tamanho);
    int vet[tamanho];
    for (i = 0; i < tamanho; i++){
        printf("Elemento da posição [%d]: ", i);
        scanf("%d", &vet[i]);
    }
    mergeSort(vet, tamanho);
    for (i = 0; i < tamanho; i ++){
        printf("%d ", vet[i]);
    }
    printf("\n");


}

