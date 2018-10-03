#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter N, please: ");
    scanf("%d", &n);
    
    int *array = malloc(n*sizeof(int));
    
    int i;
    
    for(i=0; i<n; i++){
        array[i] = i;
    }
    
     for(i=0; i<n; i++){
        printf(" array[%d] = %d \n ", i, array[i] );
    }
    
    free(array);
}