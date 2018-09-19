#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#define awake 1
#define true 1
#define asleep 0

pthread_t thread_id[2];
int producer_f = 1, consumer_f = 1; 
int buf_cur_size=0, buf_max_size = 100;
char buffer_m[100];

void* producer();
void* consumer();

void main(){
    srand(time(0));
    pthread_create(&thread_id[0], NULL, producer, NULL);
	pthread_create(&thread_id[1], NULL, consumer, NULL);
	printf("Hey!) Producer and Consumer have smth to do...\n");
	while (true) {
		sleep(5);
		printf("Number of symbols in buffer is %d. Last input symbol is %c;\n", buf_cur_size, buffer_m[buf_cur_size]);
		sleep(5);
	}
    return 0;
}

/**
 * If buffer is empty, consumer fall asleep
 * If consumer is awake, it takes char from buffer and decrease the counter
 * If buffer is not full, give a sign to producer it can work
*/
void *consumer(){
while(true){
		if (buf_cur_size <= 0) {
			consumer_f = 0;
		}
		if (consumer_f) {
			buffer_m[buf_cur_size] = '-';
			buf_cur_size--;
		}
		if (buf_cur_size < buf_max_size) {
			producer_f = awake;
		}
	}
}
/**
 * Choose a symbol.
 * If buffer is full, producer fall asleep
 * If producer is awake, put the smbol in buffer and increase the counter
 * If buffer is not empty, give a sign to consumer to work, assigning its flag as 1
 */
void *producer(){
	while(true){
	    char i;
	    int t=rand()%2;
	    if(t==1){
	        i = '&';
	    }
	    else{
	        i = (rand() % 100);
	    }
		if (buf_cur_size >= buf_max_size) {
			producer_f = asleep;
		}
		if (producer_f) {
			buffer_m[buf_cur_size] = i;
			buf_cur_size++;
		}
		if (buf_cur_size > 0) {
			consumer_f = awake;
		}
	}
	pthread_exit(0);
}

