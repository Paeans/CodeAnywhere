#include <iostream>
#include "pector.h"
using namespace std;

Pector::Pector(int num) : elem{new double[num]}, sz{num} {}

double& Pector::operator[](int i){
        return elem[i];
}

double read_and_sum(int n){
    Pector p(n);
    for(int i=0; i != n; i++)
        cin >> p[i];
    
    double sum = 0;
    for(int i=0; i != n; i++)
        sum += p[i];
    return sum;
}