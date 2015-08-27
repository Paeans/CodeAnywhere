#ifndef CAL_H
#def CAL_H

#include <iostream>
#include <stdexcept>

using namespace std;

double primary();
double term();
double expression();

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

#endif