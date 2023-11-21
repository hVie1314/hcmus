#include <iostream>

struct Queue
{
    int data;
    Queue* pNext;
};

Queue* createQueue(int data) {
    Queue* queue = new Queue;
    if (!queue) return NULL;
    queue->data = data;
    queue->pNext = NULL;
}

bool empty(Queue* queue) {
    return queue == NULL;
}

int size(Queue* queue) {
    if (!queue) return 0;
    int count = 0;
    Queue* pCurr = queue;
    while (pCurr) {
        ++count;
        pCurr = pCurr->pNext;
    }
    return count;
}

// push back
Queue* enqueue(Queue*& queue, int data) {
    Queue* q = createQueue(data);
    if (!queue) {
        queue = q;
        return queue;
    }
    Queue* pCurr = queue;
    while (pCurr->pNext) {
        pCurr = pCurr->pNext;
    }
    pCurr->pNext = q;
    return queue;
}

// delFront
Queue* dequeue(Queue*& queue) {
    if (!queue) return NULL;
    if (!queue->pNext) {
        delete queue;
        queue = NULL;
        return queue;
    }
    Queue* temp = queue;
    queue = queue->pNext;
    delete temp;
    return queue;
}

int front(Queue* queue) {
    if (!queue) return -10000;
    return queue->data;
}

int back(Queue* queue) {
    if (!queue) return -10000;
    Queue* pCurr = queue;
    while (pCurr->pNext) {
        pCurr = pCurr->pNext;
    }
    return pCurr->data;
}

void delQueue(Queue*& queue) {
    if (!queue) return;
    Queue* temp = NULL;
    while (queue) {
        temp = queue;
        queue = queue->pNext;
        delete temp;
    }
}

int main() {
    Queue* queue = NULL;
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    std::cout << size(queue) << std::endl;

    while (!empty(queue)) {
        std::cout << "front: " << front(queue) << "; back: " << back(queue) << std::endl;
        dequeue(queue);
    }
    return 0;
}
