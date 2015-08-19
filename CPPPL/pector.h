
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