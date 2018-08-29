#include <stdio.h>
#include <string.h>

int main()
{
  
  int n,i;
  char line[30];
  printf("Enter n parameter, please: ");
  //scanf("%d", &n); 
  scanf("%s", line);
  sscanf(line, "%d", &n); 
  int j, k;
  for(i=0;i<=n;i++){
      
      for(j=0; j<=n-i; j++){
          printf(" ");
      }
      for(k=0; k<2*i-1;k++){
          printf("*");
      }
      printf("\n");
      
  }
      return(0); 
}
