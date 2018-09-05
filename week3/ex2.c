#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int[], int);
void swap(int*,int*);

int main(){
    int  i, size;
   printf("Enter array size, please: ");
   scanf("%d", &size);
  
   printf("Enter array elements, please:\n");
   int a[size];
   for (i = 0; i<size; i++) {
    printf("a[%d] = ", i);
    scanf("%d", &a[i]); 
  }
    bubble_sort(a,size);

    printf("The sorted array: ");
    for(i=0; i<size ;i++){
        printf("%d", a[i]);
        printf(" ");
    }
}
void swap (int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
    
void bubble_sort(int arr[],int size){
    int i,j;
    for(i=0; i<size-1; i++){
        for(j=0; j<size-1-i;j++){
            if(arr[j] > arr[j+1]){
               swap(&arr[j], &arr[j+1]);
            }
        }
    }
}






