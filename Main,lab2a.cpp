//Atividade Lab2a
//Materia: Estrutura de Dados I
//Professor: André Kishimoto
//Aluno: Lucas Iudi Corregliano Gallinari
//Matricula: 32138628
//turma: 3G

#include <iostream>
#include <clocale>
#include "LinkedList.h"
using namespace std;
int main()
{
setlocale(LC_CTYPE, "Portuguese");
cout << "*** Lista Ligada/Encadeada (Linked List) ***\n";
LinkedList Lista;
Lista.PrintListInfo();
Lista.Insert(1);
Lista.Insert(2);
Lista.Insert(3);
Lista.Append(4);
Lista.Append(5);
Lista.Append(6);
Lista.PrintListInfo();
Lista.Clear();
Lista.PrintListInfo();
Lista.Insert(77);
Lista.Append(88);
Lista.Insert(99);
Lista.Append(3);
Lista.Insert(2);
Lista.Append(1);
Lista.Insert(0);
Lista.PrintListInfo();
int n=Lista.RemoveNode(3);
cout << "Nó removido: " << n <<  '\n';
Lista.PrintListInfo();
n=Lista.RemoveHead();
cout << "Nó removido: " << n << '\n';
Lista.PrintListInfo();
n=Lista.RemoveTail();
cout << "Nó removido: "<< n << '\n';
Lista.PrintListInfo();
cout << "Fim.\n";
Lista.Destroy();
 Creditos();
 menu();
 bool Menu=false;
 cout<<"\n\n\nNova Lista foi criada\n";
 LinkedList L;
 while(Menu==false){
 	int Comando;
 	cout<<"Digite o Comando: ";
 	cin>>Comando;
 	if(Comando==1){
 	L.PrintListInfo();
	 }
 	else if(Comando ==2){
 	int x;
 	cout<<"Digite o proximo elemento da lista: ";
 	cin>>x;
 	L.Insert(x);
	 }
	else if(Comando ==3){
 	int x;
 	cout<<"Digite o proximo elemento da lista: ";
 	cin>>x;
 	L.Append(x);
	 }
	 else if(Comando ==6){
 	CodigoTeste();
	 }
	 else if(Comando ==4){
 	int x;
 	cout<<"Digite o elemento que você deseja deletar: ";
 	cin>>x;
 	int n=L.RemoveNode(x);
 	cout << "Nó removido: " << n <<  '\n';
 }
	 else if(Comando ==5){
 	L.Clear();
 	cout << "Lista Esvaziada \n";
	 }
	 else if(Comando ==7){
 	cout<<"Head: "<<L.GetHead()<<"\n";
 	cout<<"Tail: "<<L.GetTail()<<"\n";
 	cout<<"Quantidade de Nós: "<<L.Count()<<"\n";
	 }
	else if(Comando ==8){
 	Creditos();
	 }
	 
	else if(Comando ==9){
 	menu();
	 }
	 else if(Comando ==0){
 	Menu=true;
	 }
 }
 
}