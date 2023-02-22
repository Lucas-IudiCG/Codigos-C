//Atividade Lab2a
//Materia: Estrutura de Dados I
//Professor: André Kishimoto
//Aluno: Lucas Iudi Corregliano Gallinari
//Matricula: 32138628
//turma: 3G

#include <iostream>
using namespace std;
struct Node //aqui é a estrutura do Node com o int e o *next
{
    int data;
    Node *next;
};
//Para auxilio de como começar o codigo foi utilizados referencias de outro codigo cujo o link está abaixo, foi utilizado apenas como uma ideia inicial do projeto.
//https://gist.github.com/harish-r/873ce92a91bb7b685b81
class LinkedList // eu resolvi criar como classe, para testar e ver qual dos metodos eu prefiro trabalhar, por conta disto o codigo da main sofreu alterações
{
    private://aqui estão os valores da da Lista, a head indicando o inicio, a tail indicando o fim, e o count indicando o número de elementos na lista
    int count=0;
    Node *head,*tail;
    
    public:// aqui tem Todas as funções da Lista.
LinkedList(){//cria a lista com Head e Tail =0.
    head=NULL;
    tail=NULL;
    }
bool IsEmpty(){ // para verificar se está vazio, basta verificar a head, como ela aponta para o primeiro elemento, mesmo se a cabeça for removida, outra assumirá o lugar, enquanto ainda tiver elementos na lista.
    if(head==NULL){// logo se head==Null, a lista está vazia, logo retorna true
	
        return true;
    }
    else{// caso contrario retorna false
    	return false;
	}
}
void Print() {
    if(head!=NULL){// se head diferente de null, temp é igual a head, o temp será usado para percorrer a lista, pegando as datas de cada nó e atravessando toda a lista até chegar no final(tail)
    Node *Temp = head;
	
	while(Temp) {
		cout << Temp->data <<" ";
		Temp = Temp->next;
	}
	}
	else{
	cout<<"Lista vazia";// se head=null lista vazia.
	}
	cout << "\n";
    }
    
void Append(int n){//para adicionar é nescessario um node auxiliar chamado "Temp".
        Node *Temp =new Node;
        Temp->data= n;//o data do temp é igual ao valor a ser adicionado
        Temp->next = NULL;// e o next é nulo
        count++;// foi adicionado um elemento count=count+1
    if (head== NULL){//se head for null, então esse é p primeiro elemento.
        head=Temp;
        tail=Temp;
    }
    else// caso contrario ele é posicionado na cauda
    {
        tail->next=Temp;
        tail=tail->next;
    }
    }
void Insert(int n){//para adicionar é nescessario um node auxiliar chamado "Temp".
        Node *Temp =new Node;
        Temp->data= n;
    if (head== NULL){// se for o primeiro elemento ele será adicionado no começo
        Temp->next=NULL;//next do temp é nulo
        tail=Temp;//tail =temp
        Temp->next=head;// next do temp= next da cabeça
        head=Temp;//cabeça é o temp
    }
    else//caso contrario
    {
        Temp->next=head;//next do temp =next head
        head=Temp;//temp= head
        
    }
    count++;// foi adicionado um elemento count=count+1
    }
    void PrintListInfo()
	{
	 if (IsEmpty())
	 {
	 cout << "Lista vazia!\n";
	 }
	 else
	 {
	 cout << "Lista: ";
	 Print();
	 }
	}
	void GetNode(int n)
    {
        Node *Temp =new Node;//temp é o node auxiliar adicionado
		Temp = head;// temp é igual a cabeça
        for(int i=1;Temp->next != NULL && Temp->data != n;Temp = Temp->next, i++){// percorre a lista procurando um nó que tem o data = n
		
        if(Temp->data == n)// se existir ele printa a posição
        {
            cout << "O valor: "<< n <<"Está no nó"<< i << "\n";
        }
        else if(Temp->next == NULL)// se não existir...
        {
            cout << "Não existe: "<<n << " nesta Lista \n";
        }
    }
}
    int GetHead()
    {
    	Node *Temp =head;// node auxilar = head
        return Temp->data;//return data do vetor auxiliar
    }
    int GetTail()
    {
    	Node *Temp =tail;// node auxilar = tail
        return Temp->data;//return data do vetor auxiliar
    }
    int Count()
    {
        return count;// devolve o contador
    }
   	int RemoveHead(){
        if (head != NULL)//se head não for nulo, ou seja tem elementos na lista
        {
        	Node *Temp;// node auxiliar
            Temp = head;//head = node auxiliar
            head = head->next;/// head passar para o segundo elemento pois o primeiro virou o temp.
            int RMV = Temp->data;// salva o número do data que vai ser deletado deletado
            delete Temp;//apaga o temp
            count--;//reduz o count, pois subtraiu um elemento
            return RMV;//devolve o elemento apagado
        }
        else// se head== null, lista vazia
        {
            cout << "Lista está vazia\n";
            return 0;
        }
    }
	int RemoveTail()
    {
        Node* Temp1 = head;// primeiro nó auxiliar que vai percorrer a lista até achar, e depois vai servir para unir a lista
        Node* Temp2;// vetor secundario que vai ser deletado
        if (Temp1 == NULL)
        {
        	cout << "Lista está vazia\n";// se temp1 que é = a head, for null, head= null, lista vazia
        }
        if (Temp1->next != NULL)//percorre a lista até achar
        {
            while ((Temp1->next)->next != NULL)
            {
                Temp1 = Temp1->next;
            }
            Temp2 = Temp1->next;
            Temp1->next = NULL;
        }
        else
        {
            Temp2  = Temp1;// em todos os casos salva o temp1 em temp2
        }
        int RMV = Temp2 ->data;//salva o elemento a ser deletado
        delete Temp2 ;//deleta temp2
        count--;//reduz um elemento
        return RMV;//devolve o elemento
    }
    
void Clear(){
	while(IsEmpty()==false) {//enquanto IsEmpty for falso, ou seja tem elementos 
		RemoveHead();//remove a cabeça
	}
    }
    
void Destroy(){//destroy so um o clear
	Clear();
	}
//O delete foi feito utilizando como referencia o link abaixo.
//https://www.geeksforgeeks.org/delete-a-given-node-in-linked-list-under-given-constraints/	
int RemoveNode(int n){
    Node* Atual = head;// primeiro nó auxiliar que vai percorrer os nós
    Node* Temp = NULL;//o nó auxiliar secundario que vai unir
    if (Atual != NULL && Atual->data == n)// se o head não for nulo e for o elemento da um "remove head"
    {
        head = Atual->next; 
        int RMV = Atual->data;
        delete Atual;
        count--;
        return RMV;
    }
      else
    {
    while (Atual != NULL && Atual->data != n)// Atual percorre a lista
    {
        Temp =Atual;
        Atual = Atual->next;
    }
    if (Atual == NULL){// chegou no fim da lista, e não achou
    	cout << "Não existe: "<<n << "nesta Lista \n";
    	return -1;
    }
    Temp->next =Atual->next;// sai do while o temp vira o atual e une
    int RMV =Atual->data;// pega o elemento
    delete Atual;//atual é deletado
    count--;//desce o contador
    return RMV;//retorna o RMV
    }

 }
	};
// varios outros pequenos detalhes foram feitos utilizando a referencia do link abaixo, e foi utilizado em muitas partes diferentes do codigo
//https://www.bogotobogo.com/cplusplus/linkedlist.php


void menu(){
cout<<"\n\n\n----------------------------------------------------------------\n\n";
cout<<"0= Finalizar\n";
cout<<"1= Imprimir\n";
cout<<"2= Insert\n";
cout<<"3= Append\n";
cout<<"4= Remove\n";
cout<<"5= Clear\n";
cout<<"6= Refazer o Teste\n";
cout<<"7= Informações\n";
cout<<"8= Creditos\n";
cout<<"9= Menu de Comandos\n";
}
void Creditos(){
cout<<"Atividade Lab2a Lista Conectada\n Materia: Estrutura de Dados I\nProfessor: André Kishimoto\nAluno: Lucas Iudi Corregliano Gallinari\nMatricula: 32138628 \nTurma: 3G\n";
}

void CodigoTeste(){
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
}