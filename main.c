#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include "smalloc.h"



void *mem;
struct block *freelist;
struct block *allocated_list;

void *smalloc(unsigned int nbytes) {
    if (nbytes > freelist->size){
        return NULL;
    } else {
        if (allocated_list == NULL){
            allocated_list = malloc(sizeof(struct block));
            allocated_list->size = nbytes;
            allocated_list->addr = freelist->addr;
            allocated_list->next = NULL;
            freelist->addr = freelist->addr+1;
        } else {
            allocated_list = malloc(sizeof(struct block));
            allocated_list->size = nbytes;
            allocated_list->addr = freelist->addr;
            allocated_list->next = allocated_list;
            freelist->addr = freelist->addr+1;
        }
        return allocated_list;
    }
}

int sfree(void *addr) {
    struct block *current = allocated_list;
    while (){
        if (current->addr != addr){
            
            current->next = freelist;
            
        }
        current = current->next;
    }
    return -1;
}


/* Initialize the memory space used by smalloc,
 * freelist, and allocated_list
 * Note:  mmap is a system call that has a wide variety of uses.  In our
 * case we are using it to allocate a large region of memory.
 * - mmap returns a pointer to the allocated memory
 * Arguments:
 * - NULL: a suggestion for where to place the memory. We will let the
 *         system decide where to place the memory.
 * - PROT_READ | PROT_WRITE: we will use the memory for both reading
 *         and writing.
 * - MAP_PRIVATE | MAP_ANON: the memory is just for this process, and
 *         is not associated with a file.
 * - -1: because this memory is not associated with a file, the file
 *         descriptor argument is set to -1
 * - 0: only used if the address space is associated with a file.
 */
void mem_init(int size) {
    
    mem = mmap(NULL, size,  PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if(mem == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    allocated_list = NULL;
    freelist = NULL;
    freelist = malloc(sizeof(struct block));
    freelist->size = size;
    freelist->addr = &mem;
    freelist->next = NULL;
}

void mem_clean(){
    
}

