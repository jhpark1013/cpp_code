#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdint>
using namespace std;

#define HEAP_START_ADDR (uint32_t)0
#define HEAP_LEN        (uint32_t)10000
#define HEAP_END_ADDR   (uint32_t)(HEAP_START_ADDR + HEAP_LEN -1)

typedef struct node{
    uint32_t base_addr;
    uint32_t len;
    struct node* next;
    node(int b, int l, struct node* n = nullptr):base_addr(b), len(l), next(n){}
}NODE;

NODE* Head = nullptr;

void* Malloc(uint32_t size){
    // 0. currently at head (above if statement)
    // 1. look for free space at start of heap before Head?
    // 2. look for first available Free space after at or after curr
    // 3. currently at last node, make sure it is within limits 
    NODE* p = nullptr;
    if(size!=0){
        // CASE #0
        if(Head == nullptr){
            if(size <= HEAP_LEN){
                NODE* new_node = new NODE(HEAP_START_ADDR, size, nullptr); // error here if not in struct 
                Head = new_node;
                p = Head;
                return (void*)(p);
            }
        }
        else{
            NODE* curr;
            curr = Head;

            // CASE #1
            if(curr->base_addr != HEAP_START_ADDR){
                //if size of data is less than curr base
                if((HEAP_START_ADDR + size - 1) < curr->base_addr){
                    NODE* new_node = new NODE(HEAP_START_ADDR, size, curr);
                    Head = p = new_node;
                    return (void*)(p);
                }
            }
            // CASE #2
            while(curr->next != nullptr){
                
            }
            // CASE #3
            if(curr->next == nullptr && 
                (curr->base_addr + curr->len + size - 1) < HEAP_END_ADDR){
                    NODE* new_node = new NODE(curr->base_addr + curr->len, size, curr->next);
                    curr->next = p = new_node;
                    return (void*)(p);
                }
        }
    }
    if(p == nullptr){
        cout<<"can't allocate memory size " << size<<endl;
    }
    return (void*) p;

}

// Free doesn't have * (unlike malloc)
// p and curr are type casted -- how does this work?
// Free should remove the most recent malloc block.  
void Free(void* p){
    NODE* curr, * prev;
    uint32_t free_addr =  (intptr_t)p;

    // delete the curr node, take back the head.
    if(Head->base_addr == free_addr){
        curr = Head;
        Head = curr->next;
        delete((NODE*) curr);
        return;
    }
    curr = Head, prev = nullptr;
    while(curr != nullptr){
        // ??
        if(curr->base_addr == free_addr){
            prev->next = curr->next; // deleting node by arranging pointers.
            delete((NODE*) curr); // is this garbage collection?
            return ;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "can't free memory " << free_addr << endl;
}

void Print(){
    NODE* curr = Head;
    while(curr != nullptr){
        cout << curr->base_addr << "(" << curr->len << ")" << "->";
        curr = curr->next;
    }
    cout << endl;
}

int main(){
	int *p1 = (int *)Malloc(1000);	Print();
	int *p2 = (int *)Malloc(2000);	Print();
	int *p3 = (int *)Malloc(500);	Print();
	int *p4 = (int *)Malloc(1000);	Print();
	Free(p3);						Print();
	int *p5 = (int *)Malloc(500);	Print();
	Free(p1);						Print();
	int *p6 = (int *)Malloc(200);	Print();
	Free(p2);						Print();
	Free(p4);						Print();
	Free(p5);						Print();
	Free(p6);						Print();
	return 0;    
}