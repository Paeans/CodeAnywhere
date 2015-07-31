#include <iostream>
#include "pector.h"

using namespace std;

namespace My_code{
    int main();
    int funcname();
}

int My_code::main(){
    cout << "test namespace function" << endl;
}

int main(){
    
    cout << "test program" << endl;
    
    int a = 11.11;
    int b{111};
    
    //cout << read_and_sum(3) << endl;
        
    cout << a << " " << b << endl;
    
    My_code::main(); 
}

