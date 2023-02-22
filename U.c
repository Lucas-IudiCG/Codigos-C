#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int verificar(int elemento,int vetor[],int tamanho);

int main()
{
int vet1[TAM];
int vet2[TAM];
int i;

for(i = 0; i < TAM; i++){
    printf("Digite o valor de vet1[%d]:",i);
    scanf("%d",&vet1[i]);
}

printf("\n\n");

for(i = 0; i < TAM; i++){
    printf("Digite o valor de vet2[%d]:",i);
    scanf("%d",&vet2[i]);
}

system("cls");

printf("Valores: ");
for(i = 0; i < TAM; i++){
    printf("%d ",vet1[i]);
}

for(i = 0 ; i < TAM ; i++){

    if(verificar(vet2[i],vet1,TAM)){
       printf("%d ",vet2[i]);
    }

}

return 0;
}


int verificar(int elemento,int vetor[],int tamanho){

int j;
for(j = 0; j < tamanho; j++){
    if(elemento == vetor[j]){
        return 0;
    }
}
 return 1;
}