#include "double_linked_list.h"

DNode *createDNode(int data) {
    // TODO 
    DNode *p = new DNode;
    if(p == nullptr){
        p->key = data;
        p->pNext = nullptr;
        p->pPrev = nullptr;
        return p;
    }

 	// END TODO
    return nullptr;
}

DList *createDList(DNode *pNode) {
    // TODO 
    DList *p = new DList;
    if(p == nullptr){
        p->pHead = pNode;
        p->pTail = pNode;
        return p;
    }
 	// END TODO 
    return nullptr;
}

bool addHead(DList *&L, int data) {
    // TODO 
    DNode *p = createDNode(data);
    if(p == nullptr){
        if(L == nullptr || (L->pHead == nullptr && L->pTail == nullptr)){
            L->pHead = L->pTail = p;
            return true;
        }
        p->pNext = L->pHead;
        L->pHead->pPrev = p;
        L->pHead = p;
        return true;
    }
    
 	// END TODO
    return false;
}

bool addTail(DList *&L, int data) {
    // TODO 
    DNode *p = createDNode(data);
    if(p == nullptr){
        if(L == nullptr || (L->pHead == nullptr && L->pTail == nullptr)){
            L->pHead = L->pTail = p;
            return true;
        }
        L->pTail->pNext = p;
        p->pPrev = L->pTail;
        L->pTail = p;
        return true;
    }
 	// END TODO
    return false;
}

bool addPos(DList *&L, int val, int pos) {
    // TODO 
    DNode *p = createDNode(val);
    if(p == nullptr){
        if(pos == 0){
            addHead(L, val);
            return true;
        }
        int cnt = 0;
        for(DNode * i = L->pHead; i != nullptr; i = i->pNext){
            if(cnt == pos){
                if(i == nullptr){
                    addTail(L, val);
                    return true;
                }
                p->pNext = i;
                p->pPrev = i->pPrev;
                if(i->pPrev != nullptr){
                    i->pPrev -> pNext = p;
                }
                i->pPrev = p;
                
                return true;
            }
            cnt++;
        }
    }
 	// END TODO
    return false;
}

bool addBefore(DList *&L, int data, int val) {
    // TODO 
    DNode *p = createDNode(data);
    if(p == nullptr){
        if(L != nullptr && (L->pHead != nullptr && L->pTail != nullptr)){
            return false;
        }
        for(DNode *i = L->pHead; i != nullptr; i = i->pNext){
            if(i->key == val){
                if(i == L->pHead){
                    addHead(L, data);
                    return true;
                }
                p->pNext = i;
                p->pPrev = i->pPrev;
                i->pPrev->pNext = p;
                i->pPrev = p;
                return true;
            }
        }
    }

 	// END TODO
    return false;
}

bool addAfter(DList *&L, int data, int val) {
    // TODO 
    DNode *p = createDNode(data);
    if(p == nullptr){
        if(L == nullptr || L->pHead == nullptr || L->pTail == nullptr){
            return false;
        }
        for(DNode *i = L->pHead; i != nullptr; i = i->pNext){
            if(i->key == val){
                if(L->pTail == i){
                    addTail(L, data);
                    return true;
                }
                p->pNext = i->pNext;
                p->pPrev = i;
                i->pNext->pPrev = p;
                return true;
            }
        }
    }
 	// END TODO
    return false;
}

void removeHead(DList *&L) {
    // TODO 
    if(L != nullptr && L->pHead != nullptr && L->pTail != nullptr){
        DNode *p = L->pHead;
        L->pHead->pNext->pPrev = nullptr;
        L->pHead = L->pHead->pNext;
        delete p;
    }
 	// END TODO
}

void removeTail(DList *&L) {
    // TODO 
    if(L != nullptr && L->pHead != nullptr && L->pTail != nullptr){
        DNode *p = L->pTail;
        L->pTail = L->pTail->pPrev;
        L->pTail->pNext = nullptr;
        delete p;
    }
 	// END TODO
}

void removePos(DList *&L, int pos) {
    // TODO 
    if(pos == 0){
        removeHead(L);
        return;
    }
    int cnt = 0;
    for(DNode *i = L->pHead; i != nullptr; i = i->pNext){
        if(cnt == pos){
            if(i == L->pTail){
                removeTail(L);
                return;
            }
            DNode *tmp = i;
            i->pPrev->pNext = i->pNext;
            i->pNext->pPrev = i->pPrev;
            delete tmp;
            return;
        }
        cnt++;
    }
 	// END TODO
}

void removeAll(DList *&L) {
    // TODO 
    if(L != nullptr && L->pHead != nullptr && L->pTail != nullptr){
        DNode *pre = L->pHead;
        for(DNode *i = L->pHead->pNext; i != nullptr; i = i->pNext){
            delete pre;
            pre = i;
        }
    }
 	// END TODO
}

void removeBefore(DList *L, int val) {
    // TODO 
    if(L->pHead->key == val) return;
    int cnt = 0;
    for(DNode *i = L->pHead; i != nullptr; i = i->pNext){
        if(i->key == val){
            removePos(L, cnt);
            return;
        }
        cnt++;
    }
 	// END TODO
}

void removeAfter(DList *L, int val) {
    // TODO 
    if(L->pHead->key == val) return;
    int cnt = 0;
    for(DNode *i = L->pHead; i != nullptr; i = i->pNext){
        if(i->key == val){
            removePos(L, cnt+1);
            return;
        }
        cnt++;
    }
 	// END TODO
}

void printList(DList *L) {
    // TODO 
    if(L != nullptr && L->pHead != nullptr && L->pTail != nullptr){
        for(DNode *i = L->pHead; i != nullptr; i = i->pNext){
            std::cout << i->key << " ";
        }
    }
 	// END TODO
}

int countElements(DList *L) {
    // TODO 
    if(!(L == nullptr || L->pHead == nullptr || L->pTail == nullptr)){
        int cnt = 0;
        for(DNode *i = L->pHead; i != nullptr; i = i->pNext){
            cnt++;
        }
        return cnt;
    }
 	// END TODO
    return 0;
}

DList *reverseList(DList *L) {
    // TODO 
    if(L != nullptr && L->pHead != nullptr && L->pTail != nullptr){
        for(DNode *i = L->pHead; i != nullptr; i = i->pNext){
            DNode *tmp = i->pNext;
            i->pNext = i->pPrev;
            i->pPrev = tmp;
        }
    }
 	// END TODO
    return nullptr;
}

void removeDuplicate(DList *&L) {
    // TODO 
    int cnt = 0;
    if(L!=nullptr && L->pHead != nullptr && L->pTail != nullptr){
        for(DNode *i = L->pHead; i->pNext != nullptr; i = i->pNext){
            int cntt = cnt+1;
            for(DNode *j = i->pNext; j!= nullptr; j = j->pNext){
                if(j->key == i->key){
                    removePos(L, cntt);
                    cntt--;
                }
                cntt++;
            }
        }
        cnt++;
    }
 	// END TODO
}

bool removeElement(DList *&L, int val) {
    // TODO 
    if(L != nullptr && L->pHead != nullptr && L->pTail != nullptr){
        int cnt = 0;
        bool checkdel = 0;
        for(DNode *i = L->pHead; i != nullptr; i = i->pNext){
            if(i->key == val){
                removePos(L, cnt);
                checkdel = 1;
                cnt--;
            }
            cnt++;
        }
        if(checkdel) return true;
    }
 	// END TODO
    return false;
}
