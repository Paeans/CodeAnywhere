#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cuda_runtime.h>

using namespace std;

__global__ void d_matrixm(double* matrix_1, double* matrix_2, double* result);

int main(int argc, char* argv[]){

	int matrix_size = atoi(argv[1]);
	int mem_size = sizeof(double) * matrix_size * matrix_size;
	double* matrix = (double*)malloc(mem_size);
	double* result = (double*)malloc(mem_size);

	ifstream infile;
	infile.open("matrix.txt");
	double d = 0;
	for (int i = 0; i < matrix_size * matrix_size; i++){
		infile >> d;
		matrix[i] = result[i] = d;
		cout << d << " ";	
	}
	cout << endl;
	infile.close();

	double *d_matrix_1, *d_matrix_2, *d_result;
	cudaMalloc(&d_matrix_1, mem_size);
	cudaMalloc(&d_matrix_2, mem_size);
	cudaMalloc(&d_result, mem_size);

	int multime = 2;
	for (int i = 0; i<multime; i++){
		cudaMemcpy(d_matrix_1, result, mem_size, cudaMemcpyHostToDevice);
		cudaMemcpy(d_matrix_2, matrix, mem_size, cudaMemcpyHostToDevice);
		d_matrixm << < matrix_size, matrix_size >> >(d_matrix_1, d_matrix_2, d_result);
		cudaMemcpy(result, d_result, mem_size, cudaMemcpyDeviceToHost);
	}

	for (int i = 0; i < matrix_size * matrix_size; i++){
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}

__global__ void d_matrixm(double* matrix_1, double* matrix_2, double* result){

	int size = blockDim.x;
	result[blockIdx.x * size + threadIdx.x] = 0;
	for (int i = 0; i < size; i++){
		result[blockIdx.x * size + threadIdx.x] +=
			matrix_1[blockIdx.x * size + i] * matrix_2[threadIdx.x + i * size];
	}	
}
