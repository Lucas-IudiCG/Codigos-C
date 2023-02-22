#include <iostream>
#include "Ap1H.h"


int main() {
    setlocale(LC_CTYPE,"Portuguese");
    Cal S1 =Create();
    std::string equacao;

    std::cout << "Digite o Calculo: ";
    std::getline (std::cin,equacao);
    for (int i = 0; i < equacao.length(); ++i)
     {
    Filtro(S1,equacao[i]);
     }

     for (int i = 0; i < equacao.length(); ++i){
            if(i%2==0){
            int Num;
            std::cout<<"Variavel: "<<S1.Op[i]<<"| ";
            std::cin>>Num;
            PushA(S1,Num,i);
     }
     }
    //prioridade e contas com tamanhos variados

     for(int i =0; i< S1.Top;++i){
            if(i%2==0){
                int num1=S1.Equacao[i];
                int num2=S1.Equacao[i+2];
                char op=S1.Op[i+1];
               int calc=Calculator(num1,op,num2);
               PushA(S1,calc,i+1);
            }
     }
        int Soma=0;

        for(int i =0; i< S1.Top;++i){
            if(i%2!=0){

                int num3=S1.Equacao[i];
                int num4=S1.Equacao[i+4];
                char op=S1.Op[i+2];
                int calc=Calculator(num3,op,num4);
                std::cout<<"calc: "<<calc<<"\n";
                std::cout<<"Soma: "<<Soma<<"\n";
                Soma=Soma+calc;
            }
        }
        std::cout<<"Soma: "<<Soma<<"\n";

     PrintNormal(S1);
     return 0;
}

