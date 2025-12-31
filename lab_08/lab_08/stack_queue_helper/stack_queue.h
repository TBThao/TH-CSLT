#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H

#include <iostream>
struct SNode {
    int key;
    SNode *pNext;
};

struct Stack {
    SNode *pTop;
};

void initStack(Stack &S);

bool push(Stack &S, int data);

bool pop(Stack &S, int &out);

int countStack(const Stack &S);

bool isEmptyStack(const Stack &S);

struct Queue {
    SNode *pHead;
    SNode *pTail;
};

void initQueue(Queue &Q);

bool enqueue(Queue &Q, int data);

bool dequeue(Queue &Q, int &out);

int countQueue(const Queue &Q);

bool isEmptyQueue(const Queue &Q);

#endif
