#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>

void *thread_test(void *arg)
{
    printf("hello from thread %lx \n", pthread_self());
}

int main(int argc, char *argv[])
{
    pthread_t t1, t2, t3;
    printf("main thread %lx starting a new thread \n", pthread_self());
    pthread_create(&t1, NULL, thread_test, NULL);
    pthread_create(&t2, NULL, thread_test, NULL);
    pthread_create(&t3, NULL, thread_test, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    return 0;
}