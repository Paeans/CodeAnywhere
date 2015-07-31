#include <iostream>
#include "pector.h"

using namespace std;

int main(){
    
    cout << "test program" << endl;
    
    int a = 11.11;
    int b{111};
    
    cout << read_and_sum(3) << endl;
        
    cout << a << " " << b << endl;
}