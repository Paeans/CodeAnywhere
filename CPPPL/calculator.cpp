#include "calculator.h"

Token_Stream ts;

int main()
try{
    
    //Token t{'a', 0.1};
    //cout << t.kind << " " << t.value << endl;
    //Token_Stream ts;
    //Token t;
    //do{
    //    t = ts.get();
    //    cout << t.kind << " " << t.value << endl;
    //}while(t.kind != 'q');
    
    double result = 0;
    while(cin){
        Token t = ts.get();
        if(t.kind == 'q') break;
        if(t.kind == ';') 
            cout << "=" << result << endl;
        else
            ts.putback(t);
        result = expression();
    }
    
    return 0;
}
catch(runtime_error& ex){
    cout << ex.what() << endl;
    return 1;
}
catch(...){
    cout << "UNKNOWN ERROR in calculator" <<endl;
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

double primary(){
    Token t = ts.get();
    switch(t.kind){
        case '(':{
            double e = expression();
            t=ts.get();
            if(t.kind != ')') 
                throw runtime_error("the char ) expected");
            return e;
        }
        
        case '8':
            return t.value;
        
        case ';':
        case 'q':
            ts.putback(t);
            return 0;
        
        default:
            throw runtime_error("primary expected");
    }
}

double term(){
    double left = primary();
    Token t = ts.get();
    
    while(true){
        switch(t.kind){
            case '*':
                left *= primary();
                t = ts.get();
                break;
            
            case '/':{
                double p = primary();
                if(p == 0) throw runtime_error("divide by zero");
                left /= p;
                t = ts.get();
                break;
            }
                
            default:
                ts.putback(t);
                return left;            
        }
    }
}

double expression(){
    double left = term();
    Token t = ts.get();
    while(true){
        switch(t.kind){
            case '+':
                left += term();
                t = ts.get();
                break;
            
            case '-':
                left -= term();
                t = ts.get();
                break;
            
            default:
                ts.putback(t);
                return left;
        }
    }
}