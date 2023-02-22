#ifndef AP1H_H_INCLUDED
#define AP1H_H_INCLUDED

const int Capacity=4096;

struct Cal
{
    char Op[Capacity];
    int Equacao[Capacity];
    int Conta[Capacity];
    int Top;
    int Orienta;
    int Var;
};
Cal Create()
{
    Cal inf ={{},{},{},0,0};
    return inf;
};

void Prioridade(Cal &inf){
    int Up=inf.Top-1;
        if('a'<=inf.Op[Up]<='z'|'A'<=inf.Op[Up]<='Z'){
            inf.Conta[Up]=9;
           }
        if(inf.Op[Up]=='('){
            inf.Conta[Up]=7;
           }
        if(inf.Op[Up]==')'){
            inf.Conta[Up]=8;
           }
        if(inf.Op[Up]=='+'){
            inf.Conta[Up]=1;
           }
        if(inf.Op[Up]=='-'){
            inf.Conta[Up]=2;
           }
        if(inf.Op[Up]=='/'){
            inf.Conta[Up]=3;

           }
        if(inf.Op[Up]=='*'){
            inf.Conta[Up]=4;
           }
        if(inf.Op[Up]=='^'){
            inf.Conta[Up]=5;
           }
    }


void Push(Cal &inf,char value){
    int Up=inf.Top;
    inf.Op[Up]=value;
    ++Up;
    inf.Top=Up;
}
void PushA(Cal &inf,int value, int i){
    inf.Equacao[i]=value;
}

void Filtro(Cal &inf,char value){
    if(value==' '){
        std::cout<<"";
    }
    if(value=='='){
        std::cout<<"";
    }
    else{
        Push(inf,value);
        Prioridade(inf);

    }
}






int Calculator(int Var1,char Operatacao,int Var2){
  int Potencia=0;

  switch(Operatacao) {

    case '+':
         return Var1 + Var2;
      break;

    case '-':
         return Var1-Var2;
      break;

    case '*':
         return Var1*Var2;
      break;

    case '/':
         return Var1/Var2;
      break;

    case '^':
        int Potencia=Var1;
      for(int i=0;i<Var2-1;++i){
        Potencia=Potencia*Var1;
      }
       return Potencia;
      break;
  }
}



void PrintNormal(Cal &inf){
    for(int i=0;i<inf.Top;++i){
        std::cout<<"Elemento: "<<inf.Op[i]<<"| Número: "<<(i+1)<<"| "<<inf.Conta[i]<<"| "<<inf.Equacao[i]<<"\n";
    }
    }
#endif // AP1H_H_INCLUDED
