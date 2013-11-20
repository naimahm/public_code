#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 10

int global_counter;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *increment(void *threadid){
	int tid, sum;	
	struct timespec req = {0};
	
	req.tv_sec = 0;
	req.tv_nsec = 10;
	pthread_mutex_lock(&mutex);
	tid = (int) threadid;	
	fprintf(stderr, "hello I'm thread #%d\n", tid);
	nanosleep(&req, (struct timespec *)NULL);
	
	sum = global_counter;	
	fprintf(stderr, "thread #%d: local value = %d\n", tid, sum);
	nanosleep(&req, (struct timespec *)NULL);
	
	sum += 10;
	fprintf(stderr, "thread #%d: new local value = %d\n", tid, sum);
	global_counter = sum;
	nanosleep(&req, (struct timespec *)NULL);
	pthread_mutex_unlock(&mutex);		
	
	pthread_exit(0);
}

int main (int argc, const char * argv[]) {
	
	pthread_t tid[NUM_THREADS];
	int i;
	
	global_counter = 0;
	
	pthread_mutex_init(&mutex, NULL);
	
	//create the threads
	for(i = 0; i< NUM_THREADS; i++)	
		pthread_create(&tid[i], NULL, increment, i);
	
	//join the threads
	for(i=0; i<NUM_THREADS; i++)
		pthread_join(tid[i], NULL);
	
	
	printf("\nGlobal counter = %d",global_counter);
	pthread_mutex_destroy(&mutex);
}
