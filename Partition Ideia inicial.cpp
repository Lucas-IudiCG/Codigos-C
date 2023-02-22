#include <iostream>

int main()
{
    int V[9]={5,2,3,9,8,6,4,1,7};
    int Vmen[9];
    int Vmai[9];
    int P=V[0];
    int X=0;
    int Y=0;
    
    for(int i=1;i<9;i++){
    if(P<=V[i]){
        Vmen[X]=V[i];
        X++;
    }
    if(P>V[i]){
        Vmai[Y]=V[i];
        Y++;
    }
    }
    
    int Z=0;
    for(int i =0; i<X;i++){
    V[Z]=Vmen[i];
    Z++;
    }
    
    V[Z]=P;
    Z++;
    
    for(int i =0;i<Y;i++){
    V[Z]=Vmai[i];
    Z++;
    }
    
    for(int i =0; i<9;i++){
    std::cout<<V[i]<<"|";
    }
    
    return 0;
}