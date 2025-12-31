#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>

struct DNode {
    int key;
    DNode *pNext;
    DNode *pPrev;
};

struct DList {
    DNode *pHead;
    DNode *pTail;
};

DNode *createDNode(int data);

DList *createDList(DNode *pNode);

bool addHead(DList *&L, int data);
bool addTail(DList *&L, int data);
bool addPos(DList *&L, int val, int pos);

bool addBefore(DList *&L, int data, int val);
bool addAfter(DList *&L, int data, int val);

void removeHead(DList *&L);
void removeTail(DList *&L);
void removePos(DList *&L, int pos);

void removeAll(DList *&L);

void removeBefore(DList *L, int val);
void removeAfter(DList *L, int val);

void printList(DList *L);

int countElements(DList *L);

DList *reverseList(DList *L);

void removeDuplicate(DList *&L);

bool removeElement(DList *&L, int val);

#endif
