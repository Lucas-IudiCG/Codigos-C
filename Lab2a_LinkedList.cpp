#include <iostream>
#include <clocale>
#include "LinkedList.h"
using namespace std;
 
int main()
{
 setlocale(LC_CTYPE, "Portuguese");
 cout << "*** Lista Ligada/Encadeada (Linked List) ***\n";
 LinkedList* lista = Creates();
 PrintListInfo(lista);
 Insert(lista, 1);
 Insert(lista, 2);
 Insert(lista, 3);
 Append(lista, 4);
 Append(lista, 5);
 Append(lista, 6);
 PrintListInfo(lista);

}