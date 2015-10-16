/**
  pmatrixm thread_num matrix_size
  
  using pthread to speed up
  
  g++ [--std=c++11] pmatrixm.cpp -o pmatrixm -lpthread 
  :: position of -lpthread
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#if defined(__cplusplus)
extern "C"
#endif

int test_pthread(int thread_num);

int main(int argc, char* argv[]){
  
  int thread_num = atoi(argv[1]);
  return test_pthread(thread_num);
}

void* dowork(void *);

int test_pthread(int thread_num){
  
  pthread_t *pthread_list = (pthread_t *)malloc(sizeof(pthread_t) * thread_num);
  
  for(int i=0; i<thread_num; i++){
    int id = i;
    pthread_create(&pthread_list[i], NULL, dowork, &id);
    pthread_join(pthread_list[i], NULL);
  }
  
  free(pthread_list);
  return 0;
}

void* dowork(void *threadid){
  int * id = (int *)threadid;
  cout << "This is output of thread: " << *id << endl;
  return NULL;
}






