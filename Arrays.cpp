#include <iostream>
#include "StackH.h"



int main() {


    setlocale(LC_CTYPE,"Portuguese");

    std::cout<<"Lucas Iudi Corregliano Gallinari \n" <<"Mátricula: 32138628 \n"<<"Turma 3G \n" << "Materia: Estrutura de Dados I \n" <<"Professor: André Kishimoto";
    bool Menu= false;
    char valor;
    int Topo=1;
    while(Menu==false){
        int Comando;
        for(int i=0;i<6;++i){
            std::cout<<"\n";
        }
        std::cout<<"Menu Principal \n";
        std::cout<<"1= Print,2=Push,3=Pop,4=Top,5=Size,6=Count,7=IsEmpty,8=Clear,9=Creditos,0= Finalizar o Programa \n \n";
        Stack S1 =Create();



        std::cout<<"Comando: ";
        std::cin>>Comando;

        if(Comando==0){
                Menu=true;
    }
        if(Comando==2){
                std::cout<<S1.arr[0];
                std::cin >>valor;
                Push(S1,valor);

        }


    }
}
