#include <iostream>
using namespace std;

int main()
{
    int n=0;
    cout<<"Digite o tamanho de linhas matriz: ";
    cin>>n;
    int n2=0;
    cout<<"Digite o tamanho de coluna matriz: ";
    cin>>n2;
    n=n+2;
    n2=n2+2;
    int Arr[n][n2];
    int Arr2[n][n2];
    for(int i=0;i<n;i++){
        for(int j=0;j<n2;j++){
        Arr[i][j]=0;
        Arr2[n][n2]=0;
    }
    }
    for(int i=1;i<n-1;i++){
        cout<<"\n";
        for(int j=1;j<n2-1;j++){
        cout<<Arr[i][j]<<"|";
    }
    }
    int n1=0;
    cout<<"\nDigite o número de vizinhos a serem inseridos: ";
    cin>>n1;
    
    for(int i=0;i<n1;i++){
        int x=0;
        int y=0;
        bool veri=false;
        while(veri==false){		
        cout<<"digite a coluna: ";
        cin>>x;
        cout<<"digite a linha: ";
        cin>>y;
    	if(x>0 && x<n && y>0 && y<n){
        Arr[x][y]=1;
        veri=true;
	}
		else{
		cout<<"Error"<<endl;
		}
}
}
beginning:  
    for(int i=1;i<n-1;i++){
        cout<<"\n";
        for(int j=1;j<n2-1;j++){
        cout<<Arr[i][j]<<"|";
    }
    }
    int x=0;
    for(int i=1;i<n-1;i++){
    x++;
    for(int j=1;j<n2-1;j++){
    int a=i;
	int c=j;
	int SUM=-1;	
    for(int b=a-1;b<a+2;b++){
    	for(int d=c-1;d<c+2;d++){
    		if(Arr[b][d]==1){
    		SUM++;
			}
    	}
	}
		if (SUM<=1 && Arr[i][j]==1){
            	Arr2[i][j]=0;
			}
			else if (SUM>=4 && Arr[i][j]==1){
            	Arr2[i][j]=0;
			}
			else if (2<=SUM<=3 && Arr[i][j]==1){
            	Arr2[i][j]=1;
			}
			else if (SUM==2 && Arr[i][j]==0){
            	Arr2[i][j]=1;
			}
			else{
				Arr2[i][j]=0;
			}	
}
}
		cout<<"\n";
        cout<<"\n";
for(int i=1;i<n-1;i++){
        cout<<"\n";
        for(int j=1;j<n2-1;j++){
        cout<<Arr2[i][j]<<"|";
        Arr[i][j]=Arr2[i][j];
        Arr2[i][j]=0;
    }
    }
	int H;
	cout<<"\nO Programa é para continuar: ";
	cin>>H;
	if(H==1){
	goto beginning;
}
	else{
    return 0;
}
}

