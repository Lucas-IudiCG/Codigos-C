#Include<iostream>

++Medidor;

int main() {


    setlocale(LC_CTYPE,"Portuguese");

    std::cout<<"Lucas Iudi Corregliano Gallinari \n" <<"Mátricula: 32138628 \n"<<"Turma 3G \n" << "Materia: Estrutura de Dados I \n" <<"Professor: André Kishimoto";
    bool Menu= false;
    int valor;
    int Medidor=1;
    while(Menu==false){
        int Comando;
        std::cout<<"\nMedidor: "<<Medidor;
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

        if(Comando==1){
                std::cout<<"Jesus";


        }
        if(Comando==2){
                std::cin >>valor;
                std::cout<<valor;
                Push(S1,valor);
                ++Medidor;
        }

}

}
