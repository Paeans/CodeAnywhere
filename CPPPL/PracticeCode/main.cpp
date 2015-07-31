#include <iostream>
using namespace std;

class Pector{
public:
    Pector(int num): elem{new double[num]}, sz{num} {}
    double& operator[](int i){
        return elem[i];
    }
    int size(){return sz;}
private:
    double* elem;
    int sz;
};

double read_and_sum(int n){
    Pector p(n);
    for(int i=0; i != n; i++)
        cin >> p[i];
    
    double sum = 0;
    for(int i=0; i != n; i++)
        sum += p[i];
    return sum;
}

int main(){
    
    cout << "test program" << endl;
    
    int a = 11.11;
    int b{111};
    
    cout << read_and_sum(3) << endl;
        
    cout << a << " " << b << endl;
}