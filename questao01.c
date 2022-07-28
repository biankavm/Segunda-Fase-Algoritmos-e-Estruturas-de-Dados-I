/*Considere que os seguintes tipos foram definidos:

typedef struct { char nome[20];
char endereço[40];
int id;

} tipoDados;

 

Faça um programa  (fazer o programa completo) que leia via teclado um vetor de elementos do tipo dados. 
Seu programa deve ler primeiro o número de elementos do vetor e em seguida os dados de cada pessoa. 
Os dados de cada pessoa serão entrados na odem nome, endereco e id, sendo fornecido um campo por linha.
Seu programa deve então ordenar de forma DECRESCENTE os elementos utilizando o algoritmo MERGESORT e imprimir 
os dados ordenados em seguida, apresentando os valores dos campos da mesma forma que foram apresentados os dados.
Utilize o nome como chave de ordenação.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    char endereco[40];
    int id;
} tipoDados;

void intercala(tipoDados v[], int inicio, int meio, int fim, tipoDados aux[]){ // Função para intercalar os semi vetores ordenados do merge sort.
    int i = inicio, j = meio + 1, k = inicio;
    while((inicio <= meio) && (j <= fim)){
        if (strcmp(v[i].nome, v[j].nome) > 0){
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
    for (i = inicio; i < k; i++){
        v[i] = aux[i];
    }
}

void mergeSortR(tipoDados v[], int inicio, int fim, tipoDados aux[]){ // Merge Sort recursivo
    int meio;
    if (inicio < fim){
        meio = (inicio+fim)/2; // Acha o meio do vetor
        mergeSortR(v, inicio, meio, aux); // chama a função para encontrar o meio novamente de um lado
        mergeSortR(v, meio+1, fim, aux); // chama a função para encontrar o meio novamente do outro
        intercala(v, inicio, meio, fim, aux); // intercala os vetores menores para ordená-los com o merge.
    }
}

void mergeSort(tipoDados v[], unsigned tam){ // reduzir a chamada da função
    tipoDados *aux;
    aux = (tipoDados *) malloc(sizeof(tipoDados)*tam);
    mergeSortR(v, 0, tam-1, aux);
    free(aux);
}

void lerDados(tipoDados v[], unsigned tam){
    unsigned i;
    for (i = 0; i < tam; i++){
        printf("Digite um nome: ");
        scanf("%[^\n]%*c", v[i].nome);
        printf("Entre com o endereço: ");
        scanf("%[^\n]%*c", v[i].endereco);
        printf("Digite a id: ");
        scanf("%d%*c", &v[i].id);
    }
}

void mostraDados(tipoDados v[], unsigned tam){
    unsigned i;
    for (i = 0; i < tam; i++){
        printf("%s\n", v[i].nome);
        printf("%s\n", v[i].endereco);
        printf("%d\n", v[i].id);
    }
}

int main(){
    int tam;
    printf("Digite o tamanho do seu vetor de dados para ser ordenado: ");
    scanf("%d%*c", &tam);
    tipoDados vetor[tam];
    lerDados(vetor, tam);
    mergeSort(vetor, tam);
    printf("Ordenando os dados: ");
    mostraDados(vetor, tam);
}