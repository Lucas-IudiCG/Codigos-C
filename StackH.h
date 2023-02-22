#ifndef STACKH_H_INCLUDED
#define STACKH_H_INCLUDED

//Lucas Iudi Corregliano Gallinari
//Mátricula: 32138628
//Turma 3G
//"Materia: Estrutura de Dados I
//"Professor: André Kishimoto

//para mexer com estruturas e como deve ser utilizado eu utilizei principalmente como base o codigo que mostrava o Struct Student apresentado em aula
const int Capacity = 4096;//define como constante a variavel (int) chamada capacity, que  posteriormente será usada para determinar o tamanho do array

struct Stack//cria um estratura chamada "Stack", que contém um char array[capacidty] e o int top, que determina o elemento do top da pilha.
{
    char arr[Capacity];
    int top;
};
Stack Create()//cria e retorna uma pilha baseado na estrutura acima
{
    Stack pilha ={{},0};
    return pilha;
    //o restos das duvidas com struct,eu achei no link abaixo:
    // https://docs.microsoft.com/pt-br/cpp/cpp/struct-cpp?view=msvc-170
};
char Top(Stack &pilha){//determina qual é o ultimo elemento da pilha,e informa qual é o top baseado em comparação com o NULL.
    //nesse e em muitas outras funções eu precisei afiliar um tipo com a função e descobri isso no site abaixo
    // https://www.w3schools.com/cpp/cpp_function_return.asp
    bool confirma=false;
    int i =0;
    char Topo;
    if (pilha.arr[0]== NULL){//estava muito dificil criar uma comparação para verificar o resultado, e eu utilizei uma discussão em um forum para me ajudar link abaixo.
        // https://pt.stackoverflow.com/questions/177619/qual-a-diferen%C3%A7a-entre-null-0-e-0
            confirma=true;
            pilha.top=0;
            return NULL;
            }
    while(confirma==false){
        if(pilha.arr[i]== NULL){
            pilha.top=i;
            confirma=true;
            Topo=pilha.arr[i-1];
            return Topo;
        }
        ++i;
    }
    }
char Pop(Stack &pilha){
    bool confirma=false;//pega o elemento do topo e utiliza ele para remover o ultimo elemento e o retorna para informar o elemento que foi removido
    char Rmv;
    int Up=pilha.top;
    --Up;
    if (pilha.arr[0]== NULL){
            confirma=true;
            return NULL;
            }
    if(confirma==false){
            Rmv=pilha.arr[Up];
            pilha.arr[Up]=NULL;

            }
            return Rmv;
        }
void Clear(Stack &pilha){//ele substitui todos os elementos da pilha por NULL indiscriminadamente
    for(int i=0;i<=4095;++i){
        if (pilha.arr[i]!= NULL){
            pilha.arr[i]= NULL;

    }
    }
}
void Print(Stack &pilha){//apenas uma maneira pratica e direta de verificar todos os elementos da pilha
    bool veri=false;
    for(int i=0;i<=4095;++i){
        if (pilha.arr[i]!= NULL){
            std::cout<<"Elemento na pilha: "<<pilha.arr[i]<<"| Número: "<<(i+1)<<"\n";
            veri=true;
    }
    }
    if(veri==true){
        std::cout<<"A pilha contém elementos\n";
    }
    if(veri==false){
        std::cout<<"A pilha não contém elementos\n";
    }
}
int Count(Stack &pilha){//retorna o elemento top, já que a quantidade de elementos tambem é o topo
    return pilha.top;
}
void Push(Stack &pilha,char value){//encaixa um novo elemento na pilha baseado no elemento do topo.
    int Up=pilha.top;
    if(Up==4095){
        std::cout<<"Esta cheia\n";
    }
    else{
        pilha.arr[Up]=value;
            }
        }
int Size(Stack &pilha){//retorna o tamanho da pilha:4096
    return 4096;
}
bool IsEmpty(Stack &pilha){//como os elementos são empilhados um em cima do outro, se o elemento 0, for nulo, então todos são, retornando true, se não, false
    if(pilha.arr[0]== NULL){
        return true;
    }
    else{
        return false;
    }
}
void PrintTopCountSize(Stack& pilha)//esse dai é o codigo do teste no enunciado do trabalho,é nescessario varias funções
{
 char top = Top(pilha);//pega o elemento pilha.top
 if (top == '\0')//se top for nulo
 std::cout << "Topo: Pilha vazia.\n";
 else//apenas neste else, chama a função, top,count,size e IsEmpty
 std::cout << "Topo: " << top << '\n';
 std::cout << "Elementos na pilha: " << Count(pilha) << '/' << Size(pilha)
 << ", a pilha " << (IsEmpty(pilha) ? "está vazia" : "contém elementos") << ".\n";
}

void Comands(){//apenas da o print dos comandos para a tabela de comandos utilizada para testar as funções e criar as proprias pilhas.
    std::cout<<"\nTabela de comandos\n";
    std::cout<<"-1=refazer o codigo teste\n0=Comandos\n1=Print\n2=Push\n3=Pop\n4=Top\n5=Size\n6=Count\n7=IsEmpty\n8=Clear\n9=Creditos\n10= Finalizar o Programa \n\n";
}
void Credits(){//imprime quem fez o trabalho,matricula,turma, materia e professor.
    for(int i=0;i<2;++i){
            std::cout<<"\n";
        }
    std::cout<<"Lucas Iudi Corregliano Gallinari\n" <<"Mátricula: 32138628\n"<<"Turma 3G\n" << "Materia: Estrutura de Dados I \n" <<"Professor: André Kishimoto\n";
    for(int i=0;i<2;++i){
            std::cout<<"\n";
        }
}
#endif // STACKH_H_INCLUDED
