#include <stdio.h>
#include <memory.h>

void swap(char*, char*);

int main()
{
    int l;
    char line[256];
    printf("Enter the string, please: \n") ;
    scanf("%s", line);
    l = strlen(line);
    int i;
    char *start = line;
    char *end = line+l-1;
    for(i=0; i<=l/2; i++)
    {
        swap(start,end);
        start++;
        end--;
    }
    
    printf("%s", line);
}
void swap(char *a, char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}