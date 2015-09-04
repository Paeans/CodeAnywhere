/**
    Simple calculator
    
    This program implements a basic expression calculator
    Input from cin, output to cout
    
    Grammar:
        //
            Calculation:
                Statement
                Print
                Quit
                Calculation Statement
                
            Statement:
                Declaration
                Expression
                
            Print:
                ;
                
            Quit:
                q
                
            Declaration:
                "let" Name "=" Expression
                
            Expression:
                Term
                Expression + Term
                Expression - Term
                
            Term:
                Primary
                Term * Primary
                Term / Primary
                Term % Primary
                
            Primary:
                Number
                ( Expression )
                -Primary
                +Primary
                
            Number:
                float-point-number
                
            Get input from Token_Stream ts
*/

#ifndef CAL_H
#define CAL_H

#include <vector>

using namespace std;

double statement();
double declaration(); 
double primary();
double term();
double expression();

const char number = '8';
const char name = 'a';
const char let = 'L';
const string declkey = "let";

class Token{
public:
    char kind;
    double value;  
    string name;
    
    Token(){}
    Token(char ch):kind(ch){}
    Token(char ch, double value): kind(ch), value(value){}
    Token(char ch, string name): kind(ch), name(name){}
};

class Token_Stream{
public:
    Token get();
    void putback(Token t);
    void ignore(char c);
   
private:
    bool full{false};
    Token buffer;
};

class Variable{
public:
    string name;
    double value;
};

class Var_Table{
public:
    double get_value(string key);
    void set_value(string key, double value);
    
    bool is_defined(string key);
    double define_name(string key, double value);
private:
    vector<Variable> var_table;
};

void calculator();

#endif
