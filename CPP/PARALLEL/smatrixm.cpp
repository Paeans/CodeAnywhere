/**
  smatrixm matrix_size
  
  using serial method to caculate the mutiple of matrix
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
  
using namespace std;

void * multim(double* fm, double* sm, int size);

int main(int argc, char* argv[]){
  
  int matrix_size = atoi(argv[1]);
  
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
  
  //clock_t t = clock(); 
  int multi_num = 2;
  for(int i=0; i < multi_num; i++)
    multim(matrix, rev_ma, matrix_size);
  //t = clock() - t;
  //cout << t << " ";
  
  delete matrix;
  delete rev_ma;
  return 0;
}

void * multim(double* fm, double* sm, int size){

  double rlist[size][size];
  for(int r = 0; r < size; r++){
    for(int c = 0; c < size; c++){
      for(int i = 0; i < size; i++){
        rlist[r][c] += fm[r*size + i] * sm[c*size + i];
      }
    }
  }
  
  for(int m=0; m < size; m++){
    for(int n=0; n < size; n++)
      fm[m*size + n] = rlist[m][n];
  }
  
  return NULL;
}

