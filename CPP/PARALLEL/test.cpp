#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
  
using namespace std;

void revertM(double * matrix, int size);

int main(int argc, char* argv[]){
  
  int matrix_size = atoi(argv[1]);
  
  double* matrix = (double*)malloc(sizeof(double) * matrix_size * matrix_size);
  
  ifstream infile;
  infile.open("matrix.txt");
  double d = 0;
  for(int i=0; i<matrix_size; i++){
    for(int j=0; j<matrix_size; j++){
      infile >> d;
      matrix[i*matrix_size + j] = d;
      //cout << d << " ";
    }
  }
  infile.close();
  
  for(int i=0; i<matrix_size; i++){
    for(int j=0; j<matrix_size; j++){
      cout << matrix[i * matrix_size + j] << " ";
    }
    cout << endl;
  }
  
  revertM(matrix, matrix_size);
  
  cout << endl;
  
  for(int i=0; i<matrix_size; i++){
    for(int j=0; j<matrix_size; j++){
      cout << matrix[i * matrix_size + j] << " ";
    }
    cout << endl;
  }
  return 0;
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