#include <iostream>
#include <cmath>
#include <cstring>
#include "pector.h"
#include "calculator.h"

using namespace std;

namespace My_code{
    int main();
    int funcname();
}

int My_code::main(){
    cout << "test namespace function" << endl;
}

int main(){
    
    //My_code::main(); 
    calculator();
    
    return 0;    
}

