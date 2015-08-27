#include <iostream>
#include <stdexcept>

using namespace std;

double expression();
double primary();
double term();

class Token{
public:
    char kind;
    double value;
};

class Token_Stream{
public:
    Token get();
    void putback(Token t);
   
private:
    bool full{false};
    Token buffer;
};

int main()
try{
    
    //Token t{'a', 0.1};
    //cout << t.kind << " " << t.value << endl;
    Token_Stream ts;
    Token t;
    do{
        t = ts.get();
        cout << t.kind << " " << t.value << endl;
    }while(t.kind != 'q');
    
    return 0;
}catch(...){
    cout << "ERROR in calculator" <<endl;
    return -1;
}

Token Token_Stream::get(){
    if(full){
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;
    switch(ch){
        case ';': case 'q':
        case '(': case ')': case '+': case '-': 
        case '*': case '/': return Token{ch};
        
        case '.': case '0': case '1': case '2':
        case '3': case '4': case '5': case '6':
        case '7': case '8': case '9': {
            cin.putback(ch);
            double value;
            cin >> value;
            return Token{'8', value};
        }
        
        default:
            throw runtime_error("Bad Token");
    }
}

void Token_Stream::putback(Token t){
    if(full) 
        throw runtime_error("putback to full buffer");
    buffer = t;
    full = true;
}