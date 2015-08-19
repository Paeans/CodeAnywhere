#include <iostream>
#include <cmath>
#include <cstring>
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
    
    My_code::main(); 
    
    return 0;    
}

