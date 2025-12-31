#include "linked_list.h"

Node *createNode(int data) {
    // TODO 
    Node* newnode = new Node;
    newnode->key = data;
    newnode->pNext = nullptr;
    return newnode;
  	// END TODO
    return nullptr;
}

List *createList(Node *pNode) {
    // TODO 
    List *L = new List;
    L->pHead = pNode;
    L->pTail = pNode;
    return L;
  	// END TODO
    return nullptr;
}

bool addHead(List *&L, int data) {
    // TODO 
    if(L != nullptr){
      Node* p = createNode(data);
      if(L->pHead == nullptr){
        L->pHead = p;
        L->pTail = p;
      }
      else{
        p->pNext = L->pHead;
        L->pHead = p;
      }
      return true;
    }
  	// END TODO
    return false;
}

bool addTail(List *&L, int data) {
    // TODO 
    if(L != nullptr){
      Node *p = createNode(data);
      if(L->pHead == nullptr){
        L->pHead = L->pTail = nullptr;
      }else{
        L->pTail->pNext = p;
        L->pTail = p;
      }
      return true;
    }
  	// END TODO
    return false;
}

bool addPos(List *&L, int val, int pos) {
    // TODO 
    if (L == nullptr || pos < 0) return false;
    if (pos == 0) return addHead(L, val);
    Node *cur = L->pHead;
    int idx = 0;
    while (cur != nullptr && idx < pos - 1) {
        cur = cur->pNext;
        idx++;
    }
    if (cur == nullptr) return false;
    Node *p = createNode(val);
    p->pNext = cur->pNext;
    cur->pNext = p;

    if (p->pNext == nullptr){
        L->pTail = p;
    }
    return true;
  	// END TODO
    return false;
}

bool addBefore(List *&L, int data, int val) {
    // TODO 
    if (L == nullptr || L->pHead == nullptr) return false;
    if (L->pHead->key == val) {
        return addHead(L, data);
    }
    Node *prev = L->pHead;
    while (prev->pNext != nullptr) {
        if (prev->pNext->key == val) {
            Node *p = createNode(data);
            p->pNext = prev->pNext;
            prev->pNext = p;
            return true;
        }
        prev = prev->pNext;
    }
    
  	// END TODO
    return false;
}

bool addAfter(List *&L, int data, int val) {
    // TODO 
    if (L == nullptr) return false;
    for (Node *i = L->pHead; i != nullptr; i = i->pNext){
        if (i->key == val) {
            Node *p = createNode(data);
            p->pNext = i->pNext;
            i->pNext = p;
            if (i == L->pTail){
                L->pTail = p;
            }
            return true;
        }
    }
  	// END TODO
    return false;
}

void removeHead(List *&L) {
    // TODO 
    if(L == nullptr) return;
    if(L->pHead == L->pTail){
      delete L->pHead;
      L->pHead = L->pTail = nullptr;
      return;
    }
    Node *p = L->pHead;
    L->pHead = p->pNext;
    delete L->pHead;
  	// END TODO
}

void removeTail(List *&L) {
    // TODO 
    if(L == nullptr) return;
    if(L->pHead == L->pTail){
      L->pHead = L->pTail = nullptr;
      return;
    }
    for(Node *i = L->pHead; i != nullptr; i = i->pNext){
      if(i->pNext == L->pTail){
        i->pNext = nullptr;
        delete L->pTail;
        L->pTail = i;
        return;
      }
    }
  	// END TODO
}

void removePos(List *&L, int pos) {
    // TODO 
    if (L == nullptr || L->pHead == nullptr || pos < 0) return;
    if (pos == 0) {
        removeHead(L);
        return;
    }
    Node *prev = L->pHead;
    int idx = 0;
    while (prev->pNext != nullptr && idx < pos - 1){
        prev = prev->pNext;
        idx++;
    }
    if (prev->pNext == nullptr) return;

    Node *tmp = prev->pNext;
    prev->pNext = tmp->pNext;

    if (tmp == L->pTail){
        L->pTail = prev;
    }
    delete tmp;
  	// END TODO
}

void removeAll(List *&L) {
    // TODO 
    if(L == nullptr) return;
    if(L->pHead == L->pTail){
      delete L->pHead;
      L->pHead = L->pTail = nullptr;
      return;
    }
    Node *p = L->pHead;
    while(p != nullptr){
      Node *tmp = p->pNext;
      delete p;
      p = tmp;
    }
    L->pHead = nullptr;
    L->pTail = nullptr;
  	// END TODO
}

void removeBefore(List *L, int val) {
    // TODO 
    if (L == nullptr || L->pHead == nullptr || L->pHead->pNext == nullptr) return;
    if (L->pHead->pNext->key == val){
        removeHead(L);
        return;
    }
    Node *prev = L->pHead;
    while (prev->pNext != nullptr && prev->pNext->pNext != nullptr){
        if (prev->pNext->pNext->key == val) {
            Node *toDelete = prev->pNext;
            prev->pNext = toDelete->pNext;
            delete toDelete;
            return;
        }
        prev = prev->pNext;
    }
  	// END TODO
}

void removeAfter(List *L, int val) {
    // TODO 
    if (L == nullptr) return;
    for (Node *i = L->pHead; i != nullptr; i = i->pNext){
        if (i->key == val) {
            if (i->pNext == nullptr) return;
            Node *toDelete = i->pNext;
            i->pNext = toDelete->pNext;
            if (toDelete == L->pTail){
                L->pTail = i;
            }
            delete toDelete;
            return;
        }
    }
  	// END TODO
}

void printList(List *L) {
    // TODO 
    if(L == nullptr) return;
    for(Node *i = L->pHead; i != nullptr; i = i->pNext){
      std::cout << i->key << " ";
    }
  	// END TODO
}

int countElements(List *L) {
    // TODO 
    if(L != nullptr){
      int cnt = 0;
      for(Node *i = L->pHead; i != nullptr; i = i->pNext){
        cnt++;
      }
      return cnt;
    }
    
  	// END TODO
    return 0;
}

List *reverseList(List *L) {
    // TODO 
    if (L == nullptr || L->pHead == nullptr) return L;
    Node *prev = nullptr;
    Node *curr = L->pHead;
    Node *next = nullptr;
    L->pTail = L->pHead;
    while (curr != nullptr) {
        next = curr->pNext;
        curr->pNext = prev;
        prev = curr;
        curr = next;
    }
    L->pHead = prev;
    return L;
  	// END TODO
    return nullptr;
}

void removeDuplicate(List *&L) {
    // TODO 
    if (L == nullptr || L->pHead == nullptr) return;
    Node *p1 = L->pHead;
    while (p1 != nullptr && p1->pNext != nullptr) {
        Node *p2 = p1;
        while (p2->pNext != nullptr) {
            if (p1->key == p2->pNext->key) {
                Node *dup = p2->pNext;
                p2->pNext = dup->pNext;
                if (dup == L->pTail) {
                    L->pTail = p2;
                }
                delete dup;
            } else {
                p2 = p2->pNext;
            }
        }
        p1 = p1->pNext;
    }
  	// END TODO
}

bool removeElement(List *&L, int val) {
    // TODO 
    if (L == nullptr || L->pHead == nullptr) return false;
    bool found = false;
    while (L->pHead != nullptr && L->pHead->key == val){
        removeHead(L);
        found = true;
    }
    if (L->pHead == nullptr) return found;
    Node *curr = L->pHead;
    while (curr->pNext != nullptr){
        if (curr->pNext->key == val){
            Node *toDelete = curr->pNext;
            curr->pNext = toDelete->pNext;
            if (toDelete == L->pTail){
                L->pTail = curr;
            }
            delete toDelete;
            found = true;
        } else{
            curr = curr->pNext;
        }
    }
    return found;
  	// END TODO
    return false;
}