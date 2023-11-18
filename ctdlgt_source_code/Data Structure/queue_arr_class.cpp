#include <iostream>

using namespace std;

#define MAX_SIZE 100

struct Queue
{
	int data[MAX_SIZE];
	int head;
	int tail;
};

void initialize(Queue* &queue)
{
	queue->head = 0;
	queue->tail = 0;
}

bool isEmpty(const Queue* queue)
{
	return (queue->head == 0) && (queue->tail == 0);
}

void push(Queue* queue, int val)
{
	if (isEmpty)
	{
		queue->data[0] = val;
	}

}

void pop(Queue* queue);

int front(const Queue* queue);

void deinitialize(Queue** queue);


int main()
{


	return 0;
}