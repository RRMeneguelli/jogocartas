#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 52

typedef struct {
    char face[3];
    char naipe[2];
    int valor;
    char nome[20];
} Tcarta;

int sorteio(int *t){
    *t=rand()%N;
}


void main(){
    Tcarta cr[N]; 
    FILE *baralho;
    char op[2];
    int t;

    srand((unsigned)time(NULL));

    baralho = fopen("baralho.txt","r");
    
    if (baralho == NULL){
        printf("Arquivo nao encontrado");
        return;
    }

    for(int i=0; i<N; i++) {
        fscanf(baralho, "%s %s %d %[^\n]s", cr[i].face, cr[i].naipe, &cr[i].valor, cr[i].nome);
    }

    fclose(baralho);

	t=0;
    printf("Deseja sortear uma carta? (s/n)\n");
    scanf("%s",op);
        
    while(strcmp(op,"s") == 0 || strcmp(op,"S") == 0){
        sorteio(&t);
        printf("O numero sorteado foi: %d. \n",t);
        printf("A carta sorteada foi: %s. \n",cr[t-1].nome);
        printf("Deseja sortear outra carta? (s/n)\n");
        scanf("%s",op);
    }
}
