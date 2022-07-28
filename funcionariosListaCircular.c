#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipoFuncionario{
    char nome[40];
    float salario;
} tipoFuncionario;

typedef struct tipoNo{
    tipoFuncionario dado;
    struct tipoNo *prox;
} tipoNo;

typedef struct tipoListaCircular{
    tipoNo *atual;
} tipoListaCircular;

void criaListaCircular(tipoListaCircular *l){
    l->atual = NULL;
}

void insereNaListaCircular(tipoListaCircular *l, tipoFuncionario *func){
    tipoNo *aux;
    aux = (tipoNo*) malloc(sizeof(tipoNo));
    aux->dado = *func;
    if (!l->atual){
        l->atual = aux;
        aux->prox = aux;
    }
    else{
        aux->prox = l->atual->prox;
        l->atual->prox = aux;
    }
}

void mostraFuncionario(tipoFuncionario func){
    printf("NOME: %s\n", func.nome);
    printf("SALÁRIO: %.2f\n", func.salario);
}




void mostraListaCircular(tipoListaCircular *l){
    tipoNo *aux;
    aux = l->atual;
    do {
        mostraFuncionario(aux->dado);
        aux = aux->prox;
    } while(aux != l->atual);
}

void removeDaListaCircular(tipoListaCircular *l, char *nome){
    tipoNo *aux, *seguinte;
    if (l->atual){
        aux = l->atual;
        seguinte = aux->prox;
        while(seguinte != l->atual){
            if (!strcmp(nome, seguinte->dado.nome)){
                aux->prox = seguinte->prox;
                free(seguinte);
            }
            aux = seguinte;
            seguinte = seguinte->prox;
        }
        if (!strcmp(nome, seguinte->dado.nome)){
            if (seguinte == aux){
                l->atual = NULL;
            }
            aux->prox = seguinte->prox;
            l->atual = seguinte->prox;
            free(seguinte);
        }
    }
}


int main() {
  tipoListaCircular l1;
  int x;
  tipoFuncionario tmp;
  char nome[30];

 criaListaCircular(&l1);

  for(x = 0 ; x<5; x++) {
    printf("Entre com o nome: ");
    scanf("%[^\n]%*c",tmp.nome);
    printf("Entre com o salario: ");
    scanf("%f%*c",&tmp.salario);
    insereNaListaCircular(&l1,&tmp);
  }
    mostraListaCircular(&l1);
    printf("Entre com um nome: ");
    scanf("%[^\n]%*c", nome);
    removeDaListaCircular(&l1, nome);
    mostraListaCircular(&l1);
}