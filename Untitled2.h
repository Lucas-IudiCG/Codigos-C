#include<iostream>

using namespace std;

class Node
{
public:
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




