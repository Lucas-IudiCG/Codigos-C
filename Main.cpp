#include <iostream>
#include "StackH.h"

void PrintTopCountSize(const Stack& S1)
{
 char top = Top(S1);
 if (top == '\0')
 std::cout << "Topo: Pilha vazia.\n";
 else
 std::cout << "Topo: " << top << '\n';
 std::cout << "Elementos na pilha: " << Count(S1) << '/' << Size(S1)
 << ", a pilha " << (IsEmpty(S1) ? "está vazia" : "contém elementos") << ".\n";
}
int main()
{
setlocale(LC_CTYPE, "Portuguese");
 Stack S1 = Create();
 PrintTopCountSize(S1);

 std::cout << "--------------------\n";
 std::string str = "Hello, World!";
 for (int i = 0; i < str.length(); ++i)
 {
 Push(S1, str[i]);
 PrintTopCountSize(S1);
 }

 std::cout << "--------------------\n";
 char top;
 while (!IsEmpty(S1))
 {
 top = Pop(S1);
 std::cout << "Pop retornou: " << top << '\n';
 PrintTopCountSize(S1);
 }
 std::cout << "--------------------\n";
 for (const char& c : str)
 Push(S1, c);
 PrintTopCountSize(S1);

 std::cout << "--------------------\n";
 Clear(S1);
 PrintTopCountSize(S1);
}
