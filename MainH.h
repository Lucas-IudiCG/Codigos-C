#ifndef MAINH_H_INCLUDED
#define MAINH_H_INCLUDED

const int Capacity = 4096;

struct Stack
{
    char arr[Capacity];
    int top;
};
Stack Create()
{
    Stack pilha ={{},0};
    return pilha;
};
void Top(Stack &pilha){
    bool confirma=false;
    int i =0;
    if (pilha.arr[0]== NULL){
            std::cout<<"\0 \n";
            confirma=true;
            pilha.top=0;
            }
    while(confirma==false){
        if(pilha.arr[i]== NULL){
            pilha.top=i;
            confirma=true;

        }
        ++i;
    }
    }
void Pop(Stack &pilha){
    bool confirma=false;
    char Rmv;
    int Up=pilha.top;
    --Up;
    if (pilha.arr[0]== NULL){
            std::cout<<"deu certo \n";
            confirma=true;
            }
    if(confirma==false){
            Rmv=pilha.arr[Up];
            pilha.arr[Up]=NULL;
            std::cout<<"Removido do topo: "<<Rmv<<"\n";
            }
        }
void Clear(Stack &pilha){
    for(int i=0;i<=4095;++i){
        if (pilha.arr[i]!= NULL){
            pilha.arr[i]= NULL;

    }
    }
}
void Print(Stack &pilha){
    for(int i=0;i<=4095;++i){
        if (pilha.arr[i]!= NULL){
            std::cout<<"Elemento: "<<pilha.arr[i]<<"| Número: "<<(i+1)<<"\n";
    }
    }
    if(pilha.arr[0]==NULL){
        std::cout<<"A pilha não contém elementos\n";
    }
}
void Count(Stack &pilha){
    std::cout<<"Tem "<<pilha.top<<" Elementos na pilha \n";
}
void Push(Stack &pilha,char value){
    int Up=pilha.top;
    if(Up==4095){
        std::cout<<"Esta cheia\n";
    }
    else{
        pilha.arr[Up]=value;
        std::cout<<"Topo: "<<pilha.arr[Up]<<"\nElementos na pilha: "<<(Up+1)<<"|4096, a pilha contém elementos.\n";
            }
        }
void Size(Stack &pilha){
    std::cout<<"Ainda tem: "<<pilha.top<<"|4096 de capacidade na pilha \n";
}
void IsEmpty(Stack &pilha){
    if(pilha.arr[0]== NULL){
        std::cout<<"Está vazio \n";
    }
    else{
        std::cout<<"Está não vazio \n";
    }
}
void Comands(){
    std::cout<<"\nMenu Principal \n";
    std::cout<<"0=Comandos\n1=Print\n2=Push\n3=Pop\n4=Top\n5=Size\n6=Count\n7=IsEmpty\n8=Clear\n9=Creditos\n10= Finalizar o Programa \n \n";
}
void Credits(){
    std::cout<<"Lucas Iudi Corregliano Gallinari\n" <<"Mátricula: 32138628\n"<<"Turma 3G\n" << "Materia: Estrutura de Dados I \n" <<"Professor: André Kishimoto\n";
    for(int i=0;i<2;++i){
            std::cout<<"\n";
        }
}
#endif // MAINH_H_INCLUDED
