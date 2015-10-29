#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <mpi.h>
  
using namespace std;

int main(int argc, char* argv[]){
  
  int matrix_size = atoi(argv[1]);
  int multime = atoi(argv[2]);  
  
  int rank, prosize;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &prosize)
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
  if(rank == 0){
    double* result = (double*)malloc(sizeof(double) * matrix_size);
    double* matrix = (double*)malloc(sizeof(double) * matrix_size);
  
    ifstream infile;
    infile.open("matrix.txt");
    double d = 0;
    for(int i=0; i<matrix_size; i++){
      for(int j=0; j<matrix_size; j++){
        infile >> d;
        matrix[i*matrix_size + j] = result[j*matrix_size + i] = d;
        //cout << d << " ";
      }
    }
    infile.close();
    
    int startline = matrix_size / prosize + ( matrix_size % prosize == 0 ) ? 0 : 1;
    for(int i = 1; i < prosize; i++){
      int lines[] = { matrix_size, 
                     matrix_size / prosize + ( matrix_size % prosize < i ) ? 1 : 0;
      MPI_Send(lines, 2, MPI_INT, i, 0, MPI_COMM_WORLD);
    }    
    
  }else{
      int lines[2];
      MPI_Status status;
      MPI_Recv(lines, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
      double* result = (double*)malloc(sizeof(double) * lines[1] * lines[1]);
      double* matrix_a = (double*)malloc(sizeof(double) * lines[1] * lines[2]);
      double* matrix_b = (double*)malloc(sizeof(double) * lines[1] * lines[2]);
    
  }
  return 0;
}