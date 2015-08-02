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

bool isPrime(long number){
    for(int i=2; i<=sqrt(number); i++)
        if(number % i == 0) return false;
    return true && number >= 2;
}
void primeprinter(){
    int counter = 0;
    cin >> counter;
    while(counter-- > 0){
        long s = 0;
        long e = 0;
        cin >> s >> e;
        while(s<=e){
            if(isPrime(s)) cout << s << endl;
            s++;
        }
    }
}

char getop(char opchar, char inchar){
    if(inchar == '(') return 'i';
    if(opchar == '(' || opchar == ')') return inchar == ')' ? 'x' : 'i';
    if(inchar == ')' || opchar == '^') return 'o';
    if(opchar == '/') return inchar == '^' ? 'i' : 'o';
    if(opchar == '*') return inchar == '/' || inchar == '^' ? 'i' : 'o';
    if(opchar == '-') return inchar == '+' || inchar == '-' ? 'o' : 'i';
    if(opchar == '+') return inchar == '+' ? 'o' : 'i';
}
/**
from ((a+t)*((b+(a+c))^(c+d)))
get at+bac++cd+^*
*/
void rpntransfer(string expression){
    
    string result = "";
    string oplist = ")";
    for(int i=0; i<expression.size(); i++){
        if(expression[i] != '+' && expression[i] != '-' && 
          expression[i] != '*' && expression[i] != '/' && 
          expression[i] != '^' && expression[i] != '(' && 
           expression[i] != ')' ) {
            result += expression[i];
            continue;
        }
        char op = getop(oplist[oplist.size() - 1], expression[i]);
        
        if(op == 'i') {
            oplist += expression[i];
        }else if(op == 'o') {
            result += oplist[oplist.size()-1];
            oplist = oplist.substr(0, oplist.size() - 1);
            i--;
        }else if(op == 'x') {
            oplist = oplist.substr(0, oplist.size() - 1);
        }
        
    }
    for(int j=oplist.size() - 1; j>0; j--)
        result += oplist[j];
    cout << result << endl;
}

int main(){
    
    cout << "test program" << endl;
    
    int a = 11.11;
    int b{111};
    
    //cout << read_and_sum(3) << endl;
        
    cout << a << " " << b << endl;
    
    My_code::main(); 
    
    rpntransfer("((a+t)*((b+(a+c))^(c+d)))");
}

