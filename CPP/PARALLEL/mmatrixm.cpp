#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <mpi.h>
  
using namespace std;

void multimatrix(double* matrix_a, double* matrix_b, double* result, 
                 int matrix_size, int lines);
void addmatrix(double* matrix_r, double* matrix_a, int size);

void revertM(double * matrix, int size);

int main(int argc, char* argv[]){
  
  MPI_Init(&argc, &argv);
  
  int matrix_size = atoi(argv[1]);
  int multime = 3;  
  
  int rank = 0;
  int prosize = 0;
  
  MPI_Comm_size(MPI_COMM_WORLD, &prosize);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
  if(rank == 0){
    double* result = (double*)malloc(sizeof(double) * matrix_size * matrix_size);
    double* matrix = (double*)malloc(sizeof(double) * matrix_size * matrix_size);
  
    ifstream infile;
    infile.open("matrix.txt");
    double d = 0;
    for(int i=0; i<matrix_size; i++){
      for(int j=0; j<matrix_size; j++){
        infile >> d;
        matrix[i*matrix_size + j] = result[i*matrix_size + j] = d;
        //cout << d << " ";
      }
    }
    infile.close();
    
    for(int counter = 1; counter < multime; counter++){
      revertM(result, matrix_size);

      int startline = 0;

      for(int i = 1; i < prosize; i++){
        int lines[] = { matrix_size, 
                       matrix_size / prosize + ( matrix_size % prosize < i ) ? 0 : 1};
        MPI_Send(lines, 2, MPI_INT, i, 0, MPI_COMM_WORLD);
        MPI_Send(result + startline * matrix_size, lines[0] * lines[1], MPI_DOUBLE, i, 1, MPI_COMM_WORLD);
        MPI_Send(matrix + startline * matrix_size, lines[0] * lines[1], MPI_DOUBLE, i, 2, MPI_COMM_WORLD);
        startline += lines[1];
      }
      double* res = (double*)malloc(sizeof(double) * matrix_size);
      multimatrix(result + startline * matrix_size, matrix + startline * matrix_size,
                  res, matrix_size, matrix_size - startline);
      for(int i = 0; i<matrix_size * matrix_size; i++){
        result[i] = res[i];
      }
      MPI_Status status;
      for(int i = 1; i < prosize; i++){      
        MPI_Recv(res, matrix_size * matrix_size, MPI_DOUBLE, i, 3, MPI_COMM_WORLD, &status);  
        for(int i = 0; i<matrix_size * matrix_size; i++){
          result[i] += res[i];
        }
      }
      for(int i = 0; i<matrix_size * matrix_size; i++){
          cout << result[i] << " ";
      }
    }
  }else{
    int lines[2];
    MPI_Status status;
    MPI_Recv(lines, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    double* result = (double*)malloc(sizeof(double) * lines[0] * lines[0]);
    double* matrix_a = (double*)malloc(sizeof(double) * lines[0] * lines[1]);
    double* matrix_b = (double*)malloc(sizeof(double) * lines[0] * lines[1]);
    MPI_Recv(matrix_a, lines[0] * lines[1], MPI_DOUBLE, 0, 1, MPI_COMM_WORLD, &status);
    MPI_Recv(matrix_b, lines[0] * lines[1], MPI_DOUBLE, 0, 2, MPI_COMM_WORLD, &status);
    multimatrix(matrix_a, matrix_b, result, lines[0], lines[1]);
    
    MPI_Send(result, lines[0] * lines[0], MPI_DOUBLE, 0, 3, MPI_COMM_WORLD);
    delete result;
    delete matrix_a;
    delete matrix_b;
  }
  
  MPI_Finalize();
  return 0;
}

void multimatrix(double* matrix_a, double* matrix_b, double* result, 
                 int matrix_size, int lines){
  
  memset(result, matrix_size * matrix_size * sizeof(double), 0);

  for(int i=0; i<matrix_size; i++){
    for(int j=0; j<matrix_size; j++){
      result[i * matrix_size + j] = 0;
      for(int k = 0; k<lines; k++){
        result[i * matrix_size + j] += matrix_a[k*matrix_size + i] * matrix_b[k*matrix_size + j];
      }
    }
  }
}

void addmatrix(double* matrix_r, double* matrix_a, int size){

  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
      matrix_r[i*size + j] += matrix_a[i*size +j];
    }
  }
}

void revertM(double * matrix, int size){

  for(int i=0; i<size; i++){
    
    for(int j = 0; j<size; j++){
      if(i<j){
        double tmp = matrix[i*size +j];
        matrix[i*size +j] = matrix[j*size +i];
        matrix[j*size + i] = tmp;
      }
    }
  }
}