#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <malloc.h>

void *realloc_my(void *ptr, size_t size){
    
    void *ptr2;
    if(!ptr){
        ptr2 = malloc(size * sizeof(int));
    }
    if(size == 0){
        free(ptr);
    }
        memcpy(ptr2, ptr, sizeof(&ptr));
    free(ptr);
}    
     
int main() {
    int *array = (int*) malloc(10*sizeof(int));
    int i;
    for(i=0; i<10; i++){
        array[i] = 100;
        printf(" array[%d] = %d \n ", i, array[i]);
        
    }
    int *array2 = (int*) realloc_my(array, 9);
        
    for(i=0; i<9; i++){
        printf(" array2[%d] = %d \n ", i, array[i]);
    }
}
    