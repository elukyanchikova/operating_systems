#include <stdio.h>
#include <stdlib.h>

void quick_sort(int[], int, int);
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
    quick_sort(a,0, size-1);

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

void quick_sort(int arr[],int first, int last){
    
    if (first < last)
    {
        int left = first;
        int right = last;
        int piv = arr[(left + right) / 2];
        
         while (arr[left] < piv){ 
             left++;
         }
         while (arr[right] > piv){ 
             right--;
         }
         if (left <= right) {
            swap(&arr[left], &arr[right]);
            right--;
            left++;
            }
            
        while(left<=right){
            while (arr[left] < piv) left++;
            while (arr[right] > piv) right--;
            if (left <= right)
            {   swap(&arr[left], &arr[right]);
                right--;
                left++;
            }
        }
        quick_sort(arr, first, right);
        quick_sort(arr, left, last);
    }

}
    










