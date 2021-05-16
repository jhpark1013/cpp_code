#include <stdlib.h>
#include <iostream>


class Header{
    public:
    Header *ptr;
    int size;
};

Header base; // empty list to get started
Header *freep = NULL; // start of free list

void *malloc(int nbytes){
    Header *p, *prevp;
    int nunits;
    nunits = (nbytes+sizeof(Header)-1)/sizeof(Header)+1;

    // no free list yet
    if((prevp = freep) == NULL){
        base.ptr = freep = prevp = &base;
        base.size = 0;
    }

    for(p=prevp->ptr ; ; prevp=0, p=p->ptr){
        //big enough
        if(p->size >= nunits){
            //exact
            if(p->size == nunits){
                prevp->ptr = p->ptr;
            }
            //allocate tail end
            else{
                p->size -= nunits;
                p += p->size;
                p->size = nunits;
            }
            freep = prevp;
            return (void *)(p+1);
        }
    }

    //wrapped around free list
    // if(p==freep)
    //     if((p = morecore(nunits)) == NULL)
    //         return NULL;
}

/*
scans the free list starting at freep, looking 
for place to insert the free block. Either between
two blocks or one end of the list. If block being 
free is adjacent to free block, adjacent blocks are
combined.
*/

// put block ap? in free list
void free(void *ap){
    // bp: block pointer points to header
    Header *bp, *p;

    //point to block header
    bp = (Header *)ap - 1;
    for(p=freep; !(bp>p && bp<p->ptr) ; p=p->ptr){
        // freed blok at start or end of arena
        if(p>=p->ptr && (bp>p || bp<p->ptr) )
            break;
    }
    // join upper nbr
    if(bp+bp->size == p->ptr){
        bp->size += p->ptr->size;
        bp->ptr = p->ptr->ptr;
    }
    else{
        bp->ptr = p->ptr;
    }
    // join lower nbr
    if(p+p->size == bp){
        p->size += bp->size;
        p->ptr = bp->ptr;
    }
    else{
        p->ptr = bp;
    }
    freep = p;
}

int main(){
    malloc(100);
    free();
    return 0;
}