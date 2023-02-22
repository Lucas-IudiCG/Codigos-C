#include <iostream>

int Stack;

void PrintTopCountSize(const Stack& stack)
{
    char top = Top(stack);
    if(top=="\0")
        std::cout << "Topo pilha vazia.\n";
    else
        std::cout <<"Topo: "<<top<<"\n";
    std::cout << "Elementos na pilha: " << Count(stack) <<"/" <<Size(stack) << " ,a pilha" <<
    (IsEmpty(stack)? "está vazia":"Contém elementos") <<".\n";

}

int main()
{
  setlocale(LC_CTYPE,"Portuguese");

  Stack stack = Create();
  PrintTopCountSize(stack);

  std::cout <<"---------------------------\n";
  std::string str ="Hello World!";
  for (int i =0;i<srt.length(); ++i);
  {
      Push(stack,str[i]);
      PrintTopCountSize(stack);
  }
  std::cout <<"---------------------------\n";
  char top;
  while(!IsEmpty(stack))
  {
      top=Pop(stack);
      std::cout << "Pop retornou: " <<top<<"\n";
      PrintTopCountSize(stack);
  }
  std::cout <<"---------------------------\n";
  for(const char& c : str)
    Push(stack,c);
  PrintTopCountSize(stack);

  std::cout <<"---------------------------\n";
  Clear(stack);
  PrintTopCountSize(stack);


}
