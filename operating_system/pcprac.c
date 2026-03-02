#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include <pthread.h>
#include<unistd.h>

#define buffersize 5
int buffer[buffersize];
int in=0;
int out=0;
sem_t full;
sem_t empty;
sem_t mutex;

void* producer(void* args)
{
  while(1)
  {
    item=rand()%100;
    sem_wait(&empty);
    sem_wait(&mutex);
    buffer[in]=item;
    printf("produced %d\n",buffer[in]);
    in=(in+1)%buffersize;
    sem_post(&full);
    sem_post(&mutex);
  }
  sleep(1);

}
void* consumer(void* args)
{
  while(1)
  {
    sem_wait(&full);
    sem_wait(&mutex);

    item=buffer[out];
    printf("consumed %d",item);
    out=(out+1)%buffersize
    sem_post(&empty);
    sem_post(&mutex);
  }
  sleep(1);
}
void main()
{
  pthread_t prod,pthread_t cons;
  sem_init(&empty,0,buffersize);
  sem_init(&full,0,0);
  sem_init(&mutex,0,1);
  pthread_create(pro,NULL,producer,NULL);
  pthread_create(cons,NULL,consumer,NULL);
  pthread_join(pro,NULL);
  pthread_join(cons,NULL);
  sem_destroy(&empty);
  sem_destroy(&full);
  sem_destroy(&full);
}