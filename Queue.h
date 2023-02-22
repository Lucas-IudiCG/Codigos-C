#ifndef __QUEUE_H__
#define __QUEUE_H__


int CreateArray(int tamanho);

struct Queue
{
	int front;
	int rear;
	int count;
	int tamanho;
	int values=CreateArray(tamanho);
};

Queue Create(int N);

bool Enqueue(Queue& queue, char value);
char Dequeue(Queue& queue);
char Front(const Queue& queue);
int Size(const Queue& queue);
int Count(const Queue& queue);
bool IsEmpty(const Queue& queue);
void Clear(Queue& queue);

#endif