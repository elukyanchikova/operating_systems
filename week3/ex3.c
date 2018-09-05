#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void print_list();
void insert_node(int);
void delete_node(int);

struct node{
    int value;
    struct node *next;
};

static int count=0;

struct node *head = NULL;
struct node *tail= NULL;

int main() {
    insert_node(1);
    insert_node(3);
    insert_node(6);
    print_list();
    delete_node(3);
    print_list();
}
void insert_node(int key){
    /*int insert_node(int value) {
    if (count == 0) {
        current = malloc(sizeof(struct Node));
        current->data = value;
        head = current;
        current->next = NULL;
    } else {
        struct Node *temp = malloc(sizeof(struct Node));
        temp->data = value;
        temp->next = NULL;
        current->next = temp;
        current = temp;
    }
    count++;
    return 0;
}*/
    if(count==0){
        tail = malloc(sizeof(struct node));
        tail->value = key;
        head= tail;
        tail->next = NULL;
    }
    else{
        struct node *temp = malloc(sizeof(struct node));
        temp->value = key;
        temp->next = NULL;
        tail->next = temp;
        tail=temp;
}
        count++;
}
void print_list(){
    struct node *cur = head;
    int i;
    for(i=0; i<count; i++){
        printf("%d", cur->value);
        printf(" ");
        cur = cur->next;
    }
      printf("\n ");
}

void delete_node(int key){        
    struct node *p = head;
    int f = 0;
    while(f!=1){
    if(head->value!=key){
        if(p->next->value==key){
            free(p->next);
            p->next=p->next->next;
            f=1;
        }
    }
    else{
        p=p->next;
    }
	}
	}


