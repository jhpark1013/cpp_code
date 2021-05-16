#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
class phoneList{
public:
int val;
bool canUse;
phoneList* prev;
phoneList* next;
    phoneList(int v){
        val=v;
        prev=next=nullptr;
        canUse=true;
    }
};

class PhoneDirectory {
public:

vector<phoneList*>phoneMap;
phoneList* avaList;

PhoneDirectory(int maxNumbers) {
    avaList=new phoneList(-1);
    
    phoneMap.resize(maxNumbers);
    phoneList* curAvaNode=avaList;
    
    for(int i=0; i<maxNumbers; i++){
        phoneList* newNode=new phoneList(i+1);
        phoneMap[i]=newNode;
        curAvaNode->next=newNode;
        newNode->prev=curAvaNode;
        
        curAvaNode=curAvaNode->next;
    }
    
}

int get() {
    phoneList* node=avaList->next;
    if(!node) return -1;
    int res=node->val -1 ;
    avaList->next=node->next;
    if( node->next ) node->next->prev=avaList;
    
    node->val = node->val *(-1);
    node->next=node->prev=nullptr;
    return res;
}

bool check(int number) {
    return phoneMap[number]->val>0;
}

void release(int number) {
    phoneList* node=phoneMap[number];
    if( node->val > 0 ) return;   
    if( node->val < 0 ) node->val  = node->val *(-1);
    
    phoneList* tmpNode=avaList->next;
    avaList->next=node;
    node->prev=avaList;
    node->next=tmpNode;
    if(tmpNode) tmpNode->prev=node;
}
};

