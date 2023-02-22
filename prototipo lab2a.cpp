struct Node {
	int data;
	Node* next;
};

struct List
{
    Node *head;
    Node *tail;
    Node *next;
}


LinkedList Create()
{
	List lista = {NULL,NULL,NULL};
	return lista;
}