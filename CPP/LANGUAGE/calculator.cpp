
#include <iostream>
#include <string>
#include <stdexcept>
#include "calculator.h"

using namespace std;

Token_Stream ts;
Var_Table var_table;

void calculator(){
    while(cin)
    try{
        Token t = ts.get();       
        while(t.kind == ';') t = ts.get();        
        if(t.kind == 'q') return; 
        ts.putback(t);
        cout << "-> " << statement() << endl;
    }
    catch(runtime_error& ex){
        ts.ignore(';');
        cout << ex.what() << endl;
    }
    catch(...){
        ts.ignore(';');
        cout << "UNKNOWN ERROR in calculator" <<endl;
    }
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
            return Token{number, value};
        }
        
        default:
            if(isalpha(ch)){
                cin.putback(ch);
                string s;
                cin >> s;
                if(s == declkey) return Token(let);
                return Token(name, s);
            }
            throw runtime_error("Bad Token");
    }
}

void Token_Stream::putback(Token t){
    if(full) 
        throw runtime_error("putback to full buffer");
    buffer = t;
    full = true;
}

void Token_Stream::ignore(char c){
    if(!full) cin >> buffer.kind;
    else full = false;
    while(buffer.kind != c && cin >> buffer.kind);
    return;
}

double Var_Table::get_value(string key){
    for(const Variable& v : var_table)
        if(v.name == key) return v.value;
    throw runtime_error("get: undefined variable: " + key);
}

void Var_Table::set_value(string key, double value){
    for(Variable& v : var_table)
        if(v.name == key){
            v.value = value;
            return;
        }
    throw runtime_error("set: undefined variable: " + key);
}

bool Var_Table::is_defined(string key){
    for(const Variable& v : var_table)
        if(v.name == key) return true;
    return false;
}

double Var_Table::define_name(string key, double val){
    if(is_defined(key)) 
        throw runtime_error(key + " defined twice");
    var_table.push_back(Variable{key, val});
    return val;
}

double statement(){
    Token t = ts.get();
    switch(t.kind){
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

double declaration(){
    Token t = ts.get();
    if(t.kind != name) 
        throw runtime_error("name expected");
    if(ts.get().kind != '=')
        throw runtime_error("= is missing");
    return var_table.define_name(t.name, expression());
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
        
        case number:
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
