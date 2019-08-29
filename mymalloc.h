#include <stdio.h>
#include<stddef.h>
#include <stdlib.h>

#define malloc( x ) mymalloc(x, __FILE__, __LINE__)
#define free( x ) myfree(x,__FILE__, __LINE__)



struct block{ //11 bytes
short size;
char free;
struct block *next;
    
}__attribute__((packed));

void split(struct block *fitting_slot, short size);
void *mymalloc(short noOfBytes, char *file, int line);
void plist();
void myfree(void* ptr, char *file, int line);

