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

int test_pthread(int thread_num);
void* dowork(void *);
void* submulti(void *);

typedef struct arg {
  double* matrix;
  double* rev_ma;
  int start;
  int num;
  int size;
} arg;

int main(int argc, char* argv[]){
  
  int thread_num = atoi(argv[1]);
  int matrix_size = atoi(argv[2]);
  
  double* matrix = new double[matrix_size * matrix_size];  
  double* rev_ma = new double[matrix_size * matrix_size];
  
  ifstream infile;
  infile.open("matrix.txt");
  double d = 0;
  for(int i=0; i<matrix_size; i++){
    for(int j=0; j<matrix_size; j++){
      infile >> d;
      matrix[i*matrix_size + j] = rev_ma[j*matrix_size + i] = d;
      //cout << d << " ";
    }
  }
  infile.close();
  
  pthread_t *pthread_list = (pthread_t *)malloc(sizeof(pthread_t) * thread_num);
  int worksize = matrix_size / thread_num;
  
  //clock_t t = clock(); 
  
  int multi_num = 2;
  while(multi_num-- > 0){
    int start = 0;
    for(int i=0; i<thread_num; i++){
      arg* param = (arg*)malloc(sizeof(arg));
      param->matrix = matrix;
      param->rev_ma = rev_ma;
      param->start = start;
      param->num = worksize + ( i < (matrix_size % thread_num) ? 1 : 0 );
      param->size = matrix_size;

      start += param->num;
      pthread_create(&pthread_list[i], NULL, submulti, param);    
    }
    for(int i=0; i<thread_num; i++){
      pthread_join(pthread_list[i], NULL);
    }
  }
  
  //t = clock() - t;
  //cout << t << " ";
  
  /**
   ** Out put result matrix
  for(int i=0; i<matrix_size*matrix_size; i++){
    cout << matrix[i] << " ";
  }
  cout << endl;
  */
  
  delete matrix;
  delete rev_ma;
  
  return 0;
  //return test_pthread(thread_num);  
}

void* submulti(void *p){
  
  arg* param = (arg*)p;
  double* fm = param->matrix;
  double* sm = param->rev_ma;
  int start = param->start;
  int num = param->num;
  int size = param->size;
  
  double rlist[size];
  for(int r = start; r < num + start; r++){
    for(int c = 0; c < size; c++){
      rlist[c] = 0;
      for(int i = 0; i < size; i++){
        rlist[c] += fm[r*size + i] * sm[c*size + i];
      }
    }
    for(int j=0; j < size; j++){
      fm[r*size + j] = rlist[j];
    }
  }
  
  free(param);
  return NULL;
}

int test_pthread(int thread_num){
  
  pthread_t *pthread_list = (pthread_t *)malloc(sizeof(pthread_t) * thread_num);
  
  for(int i=0; i<thread_num; i++){
    int id = i;
    pthread_create(&pthread_list[i], NULL, dowork, &id);    
  }
  
  for(int i=0; i<thread_num; i++){
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






