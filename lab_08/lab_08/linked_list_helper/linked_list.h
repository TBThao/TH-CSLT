#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

struct Node {
    int key;
    Node *pNext;
};

struct List {
    Node *pHead;
    Node *pTail;
};

Node *createNode(int data);

List *createList(Node *pNode);

bool addHead(List *&L, int data);

bool addTail(List *&L, int data);

bool addPos(List *&L, int val, int pos);

bool addBefore(List *&L, int data, int val);

bool addAfter(List *&L, int data, int val);

void removeHead(List *&L);

void removeTail(List *&L);

void removePos(List *&L, int pos);

void removeAll(List *&L);

void removeBefore(List *L, int val);

void removeAfter(List *L, int val);

void printList(List *L);

int countElements(List *L);

List *reverseList(List *L);

void removeDuplicate(List *&L);

bool removeElement(List *&L, int val);

#endif
