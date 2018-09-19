#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_message(void *thread_id){
    printf("Hi! I'm the thread #%d\n", thread_id);
}
void thread_seq(){
    pthread_t threads[10];
    int state, i;
        for(i=0; i<10; i++){
                printf("Hey! It's a creation of thread #%d\n", i);
        state = pthread_create(&threads[i], NULL , print_message, NULL);
		pthread_join(threads[i], NULL);
        if(state!=0){
            printf("Some mistake occures, error code is %d\n",state);
            exit(-1);
        }
        sleep(20);
}
    exit(0);
    }
void thread_par(){
    pthread_t threads[10];
    int state, i;
    for(i=0; i<10; i++){
        printf("Hey! It's a creation of thread #%d\n", i);
        state = pthread_create(&threads[i], NULL ,print_message, NULL);
        if(state!=0){
            printf("Some mistake occures, error code is %d\n",state);
            exit(-1);
        }
}
sleep(20);
    exit(0);
    
}
int main(int args){
   thread_par();
   sleep(10);
   thread_seq();
   return 0;
}