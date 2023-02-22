#include <iostream>

// main.cpp
#include <iostream>
#include <clocale>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
	int count;
    Node *head;
    Node *tail;
    Node *temp;

bool isEmpty()
{
    return head == NULL;
}

    void Insert(int x)
    {
        temp = new Node;
        temp->data = x;
        temp->next = NULL;
        tail = temp;
        head = temp;
    }

    void Append(int x)
    {
        temp = new Node;
        temp->data = x;
        temp->next = NULL;
            head = temp;
            tail = temp;
    }

    void RemoveNode(Node *LinkedList,int x)
    {
        temp = head;
        Node *prev;
        while(temp->next != NULL && temp->data != x)
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp->data == x)
        {
            prev->next = temp->next;
            delete temp;
        }
        else if(temp->next == NULL)
        {
            cout << "Error: Number Not found..." << endl;
        }
    }
    void display(Node *List)
    {
        if(!isEmpty()){
            for(temp = head; temp != NULL; temp=temp->next)
                cout << temp->data << " ";
            cout << endl;
        }
        else
        {
            cout << "List is Empty!" << endl;
        }
    }
};


void Print(const LinkedList* list)
{
    while(list!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
void PrintListInfo(const LinkedList* list)
{
 if (IsEmpty())
 {
 cout << "Lista vazia!\n";
 }
 else
 {
 cout << "Lista: ";
 Print(list);
 }
}

int main()
{
 setlocale(LC_CTYPE, "Portuguese");
 cout << "*** Lista Ligada/Encadeada (Linked List) ***\n";
 LinkedList* list = Create();
 PrintListInfo(list);
 Insert(list, 1);
 Insert(list, 2);
 Insert(list, 3);
 Append(list, 4);
 Append(list, 5);
 Append(list, 6);
 PrintListInfo(list);
 Clear(list);
 PrintListInfo(list);
 Insert(list, 77);
 Append(list, 88);
 Insert(list, 99);
 Append(list, 3);
 Insert(list, 2);
 Append(list, 1);
 Insert(list, 0);
 PrintListInfo(list);
}