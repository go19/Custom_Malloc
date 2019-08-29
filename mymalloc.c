#include <stdio.h>
#include <stddef.h>
#include "mymalloc.h"

static char myblock[4096] = {'\0'};

void split(struct block *tobereturned, short size){
    
    struct block *mainblock = (void*)((void*)tobereturned + size + sizeof(struct block));
    mainblock->size = (tobereturned->size) - size - sizeof(struct block);
    mainblock->free = 'f';
    mainblock->next = tobereturned->next;
    
    tobereturned->size = size;
    tobereturned->free = 'n';
    tobereturned->next = mainblock;
    
} 
void plist(){
    //printf("sss %ld \n" , sizeof(struct block));
    int i = 0;
    struct block *temp = (void*)myblock;
    while(temp!=NULL){
        
        printf("%d: plistsize: %ld \n",i, temp->size);
        i++;
        temp = temp->next;
    }
}
int obtainprevsize(struct block* focusnode){
    int p;
    struct block* itr = (void*)(myblock);
    while(itr!=NULL){
        if(itr == focusnode){
            p = itr->size;
            break;
        }
        if(itr->next == focusnode){
            p = itr->size;
            break;
        }
        itr = itr->next;
    }
    return p;
}

void myfree(void *ptr, char *file, int line){
 

    int i = sizeof(struct block);
    int p;

    struct block *f_metablock = (void*)(ptr)-sizeof(struct block);
    
    if(f_metablock == NULL  || ptr == NULL ){
        fprintf(stderr, "Cannot free. Pointer was never malloc'ed\n");
        return;
    }

    while(i < 4096){
        //Traverse through the char array and find the address where ptr is pointing to
        if( (( (void*)(&myblock[i])) == ptr)){
            //Initialize Metadata block of interest
            struct block *focusnode = (void*)(&myblock[i-sizeof(struct block)]);
            if(focusnode->free == 'f'){
                fprintf(stderr, "Already been freed. \n");
                return;
            }
            //Traversing node for obtaining size of the previous block in case of need to merge
            p = obtainprevsize(focusnode);
            //Prevnode prep
            struct block *prevnode = (void*)(&myblock[i- 2*sizeof(struct block) - p ]);
            //PrevNode is valid. Perform checks on free conditions with prevnode and next node.
            if(prevnode->free != 'f'){
                if( (focusnode->next) && focusnode->next->free != 'f' ){
              //      printf("a1 \n");
                    focusnode->free = 'f';
               //     printf("%s, --File %s Line %d\n", "Succesfully freed.",file,line);
                    return;
            }
                else if(focusnode->next->free == 'f'){
               //     printf("cc\n");
                    focusnode->size = focusnode->size+ focusnode->next->size + sizeof(struct block);
                    focusnode->next = focusnode->next->next;
                    focusnode->free = 'f';
                   // printf("%s, --File %s Line %d\n", "Succesfully freed and coalesced with next block.",file,line);
                    return;
                }
            }
            //If PrevNode is not free . Perform checks on free conditions with next node.
            if(prevnode->free == 'f'){
               if(focusnode->next->free =='f'){ //merge next and focus to prev node
                //    printf("a2 \n");
                    prevnode->size = focusnode->size + focusnode->next->size + prevnode->size + 2*(sizeof(struct block));
                    prevnode->next = focusnode->next->next;
                    prevnode->free = 'f';
                //    printf("%s, --File %s Line %d\n", "Succesfully freed and coalesced with previous and next block.",file,line);
                    return;
                }
                else if(focusnode->next->free != 'f'){
               //     printf("a3 \n");
                    prevnode->size = prevnode->size + sizeof(struct block) + focusnode->size;
                    prevnode->next = focusnode->next;
                    prevnode->free = 'f';
                //    printf("%s, --File %s Line %d\n", "Succesfully freed and coalesced with previous block.",file,line);
                    return;
                }
            }

            else{
                  fprintf(stderr, "Already freed. \n");
                  return;
            }
        }
        else{
            struct block *temp = (void*)(&myblock[i-sizeof(struct block)]);
            i += sizeof(struct block) + temp->size;
        }
    }
    
    fprintf(stderr, "Cannot free. Pointer was never malloc'ed\n");
    return;
}

void *mymalloc(short numbytes, char *file, int line){
    struct block *p1;
    void *temp;

    struct block *f1 = (void*)myblock;
    
    if(!(f1->size)){
        f1->size = 4096 - sizeof(struct block);
        f1->free = 'f';
        f1->next = NULL;
    }
    p1 = f1;

    while( (((p1-> free)=='n' || (p1->size)<numbytes)) && (p1->next != NULL)){
        p1 = p1->next;
    }

    
//    printf("%d \n", numbytes);
    
    if(numbytes <= 0){
        fprintf(stderr, "Cannot malloc 0 or negative sizes. \n");
        temp = NULL;
        return temp;
    }
    
    else if(p1->size == numbytes && p1->free =='f'){
    
     //   printf("%ld \n", p1->size);
     //   printf("%ld \n", numbytes);
        p1->free = 'n';
        temp = (void *)(++p1);
        return temp;
    }
     else if(p1->size > (numbytes +sizeof(struct block)) && p1->free == 'f'){
       //  printf("%ld \n", p1->size);
       //  printf("%ld \n", numbytes);
       split(p1, numbytes);
       temp = (void*)(++p1);
       return temp;
     }
    
    else{
        fprintf(stderr ,"Not enough memory.\n");
        temp = NULL;
        return temp;

    }
    
}


