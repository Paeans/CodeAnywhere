#include <iostream>
#include <stdlib.h>

using namespace std;

#define CUDA true

__global__ void multiadd(int N, float a, float* x, float* y);

int main(int argc, char* argv[]){

	cout << "This is test CUDA in visual studio!" << endl;

	int N = 1 << 20;
	int size = sizeof(float) * N;
	float* x = (float*)malloc(size);
	float* y = (float*)malloc(size);
	float *dx, *dy;
	cudaMalloc(&dx, size);
	cudaMalloc(&dy, size);

	for (int i = 0; i < N; i++){
		x[i] = 1.0;
		y[i] = 2.0;
	}
	if (CUDA){
		cudaMemcpy(dx, x, size, cudaMemcpyHostToDevice);
		cudaMemcpy(dy, y, size, cudaMemcpyHostToDevice);

		multiadd <<< (N + 255) / 256, 256 >>>(N, 3, dx, dy);

		cudaMemcpy(y, dy, size, cudaMemcpyDeviceToHost);
	}
	else{
		for (int i = 0; i < N; i++){
			y[i] = 3 * x[i] + y[i];
		}
	}

	int counter = 0;
	for (int i = 0; i < N; i++){
		if (y[i] != 5.0) counter++;
	}
	cout << "Error number is: " << counter << endl;

	return 0;
}

__global__ void multiadd(int N, float a, float* x, float* y){

	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < N) y[i] = a * x[i] + y[i];
}

