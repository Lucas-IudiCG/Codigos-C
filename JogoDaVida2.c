#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int n, m = 0;
  int geracao = 1;
  bool veri = true;

  //entra com o numero de linhas e colunas da matriz, verifica se e um numero valido
  while(veri){
    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &n);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &m);

    if(n>0 && m>0){
      veri=false;
    }else{
      printf("\nErro. O numero de linhas e colunas nao pode ser negativo\n\n");
    }
  }

  int nLin = n+2;
  int nCol = m+2;

  //cria a matriz original e a matriz resultado
  int Arr[nLin][nCol];
  int ArrR[nLin][nCol];

  //seta os elementos da matriz para 0
  for(int i=0; i<nLin; i++){
    for(int j=0;j<nCol; j++){
      Arr[i][j] = 0;
      ArrR[i][j] = 0;
    }
  }

  //seta a primeira e ultima linha para 3
  for(int i=0;i<nCol; i++){
    Arr[0][i] = 3;
    Arr[n+1][i] = 3;
    ArrR[0][i] = 3;
    ArrR[n+1][i] = 3;
  }
  //seta a primeria e ultima coluna para 3
  for(int i=0; i<=nLin; i++){
    Arr[i][0] = 3;
    Arr[i][m+1] = 3;
    ArrR[i][0] = 3;
    ArrR[i][m+1] = 3;
  }

  int numCels;
  printf("\nDigite o numero de celulas vivas para inicializar a matriz: ");
  scanf("%d",&numCels);

  //preenche a matriz com as celulas vivas
  for(int i=0; i<numCels; i++){
    int lin, col;
    printf("\nPara a celula %d digite\n  a linha: ",i+1);
    scanf("%d",&lin);
    printf("  a coluna: ");
    scanf("%d",&col);
    
    if(lin<=0){
      lin=1;
    }else if(lin>=n+1){
      lin = n;
    }
    if(col<=0){
      col = 1;
    }else if(col>=m+1){
      col=m;
    }
    Arr[lin][col] = 1;
  } 

  //printa a matriz inicial
  for(int i=1; i<n+1; i++){
    printf("\n");
    printf("|");
    for(int j=1; j<m+1;j++){
      printf("%d|",Arr[i][j]);
    }
  }

  beginning:

  //passa por cada celula da matriz e compara com todos os seus vizinhos se sao iguais a 1 ou 0. Se forem iguais a 1, incrementa a variavel sum, que representa a quantidade de vizinhos vivos que a celula Arr[i][j] tem
  for(int i=1;i<n-1;i++){
    for(int j=1;j<m-1;j++){
      int celLin = i;
      int celCol = j;
      int sum = -1;

      for(int vLin = celLin-1; vLin<celLin+2; vLin++){
        for(int vCol = celCol-1; vCol<celCol+2; vCol++){
          if(Arr[vLin][vCol] == 1){
            sum++;
          }
        }
      }
      //compara o valor de soma para definir se a celula Arr[i][j] vive ou morre
      if(sum<=1 && Arr[i][j]==1){
        ArrR[i][j] = 0;
      }else if(sum>=4 && Arr[i][j]==1){
        ArrR[i][j] = 0;
      }else if(sum>=2 && sum<=3 && Arr[i][j]==1){
        ArrR[i][j] = 1;
      }else if(sum==2 && Arr[i][j]==0){
        ArrR[i][j] = 1;
      }else{
        ArrR[i][j] = 0;
      }
    }
  }

  //passa para a proxima geracao
  printf("\n\nResultado da geracao %d:",geracao);
   geracao+=1;

  //printa o resultado, copia os valores para a matriz original e reseta o resultado
  for(int i=1;i<n+1; i++){
    printf("\n");
    printf("|");
    for(int j=1; j<m+1;j++){
      printf("%d|",ArrR[i][j]);
      Arr[i][j] = ArrR[i][j];
      ArrR[i][j] = 0;
    }
  }

  //pergunta se o usuario quer continuar
  int op;
  printf("\n\nContinuar o programa e passar para a proxima geracao? (1 - SIM): ");
  scanf("%d",&op);
  if(op==1){
    goto beginning;
  }else{
    printf("\nEncerrando o programa...");
    return 0;
  }
  
}