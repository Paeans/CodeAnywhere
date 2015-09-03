
#ifndef PRAC_H
#define PRAC_H

template<class R, class T> 
    R narrow_cast(const T& a);
    
int practice();

class Pector{
public:
    Pector(int num);
    double& operator[](int i);
    int size(){return sz;}
private:
    double* elem;
    int sz;
};

double read_and_sum(int n);


#endif