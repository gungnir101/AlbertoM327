#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 3

int requests = 200;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

struct worker_thread {
    pthread_t thread;
    int id;
};


void nap_random() {
    struct timespec sleep_time;
    sleep_time.tv_sec = 0;
    // Generate a value between 0 and 1 second
    // 1,000,000,000 ns = 1000 milliseconds
    sleep_time.tv_nsec = rand() % (1000000000L / 4L);
#ifdef DEBUG
    // 1,000,000 ns = 1 ms
    fprintf(stderr, "main: sleeping for %ld nanoseconds (%ld milliseconds).\n",
            sleep_time.tv_nsec, sleep_time.tv_nsec / 1000000L);
#endif
    nanosleep(&sleep_time, NULL);
}

int is_prime(int n) {
    if (n == 1) return 0;
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int process_request(struct worker_thread* params){
    
    int total = 0; 

    while (requests > 0)
    {   
        pthread_mutex_lock(&lock);
        
        //printf("thread-%d processed a request\n", params->id);
        //printf("Requests left: %d\n", requests);

        //works on request
        for(int i = 0; i < 30000; i++){
            is_prime(i);
        }
        
        total++;
        requests--;

        pthread_mutex_unlock(&lock);  

        nap_random();
    }

    printf("thread-%d exiting. Processed %d requests\n", params->id, total);

    return 1;    
}

void* do_work(void* params){
    while(1){
        if(process_request(params)) break;
    }
    return NULL;
}


pthread_t start_thread(struct worker_thread* params){

    pthread_t thread;

    printf("thread-%d starting...\n", params->id);

    pthread_create(&thread, NULL, do_work, params);
    
    return thread;
}

void create_thread(struct worker_thread* t, int id){
    
    struct worker_thread* aux = malloc(sizeof(struct worker_thread));    
    t->id = id;
    aux->id = id;
    t->thread = start_thread(aux);
}

int main(){

    struct worker_thread* threads[NUM_THREADS];
    //initialize threads
    for(int i = 0; i < NUM_THREADS; i++){
        threads[i] = malloc(sizeof(struct worker_thread));
    }
    //create and start threads 
    for(int i = 0; i < NUM_THREADS; i++){
        create_thread(threads[i], i + 1);
    }
    //join threads
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i]->thread, NULL);
    }
    
}