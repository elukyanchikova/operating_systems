#include <stdio.h>
//#include <string.h>

void first(int);
void second(int);
void third(int);

int main()
{
  
  int n;
  char line[30];
  printf("Enter n parameter, please: ");
  scanf("%d", &n); 
  //scanf("%s", line);
  //sscanf(line, "%d", &n); 

    first(n);
    second(n);
    third(n);
  
  return(0); 
}
void first(int h){
    int i,j;
    for(i=0;i<=h;i++){
      for(j=0; j<=i; j++){
          printf("*");
      }
      printf("\n");
  }
}

void second(int h){ 
    int i,j;
    
    for(i=0;i<h/2;i++){
      for(j=0; j<=i; j++){
          printf("*");
      }
      printf("\n");
    }    
    
    if(h%2!= 0){
        int t;
        for(t=0; t<=i;t++){
            printf("*");
        }
        printf("\n");
    }
    
    for(i=h/2-1; i>=0;i--){
        for(j=0;j<=i;j++){
            printf("*");
        }
    printf("\n");
    }
  }
void third (int h){
    int i,j;
    for(i=0;i<h;i++){
      for(j=0; j<2*h-1; j++){
          printf("*");
      }
      printf("\n");
  }
}
