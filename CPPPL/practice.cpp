#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "practice.h"

using namespace std;

template<class R, class T> R narrow_cast(const T& a){
    R r = R(a);
    if(a != T(r)) throw runtime_error("narrow cast");
    return r;
}

int practice()
try{
    cout << "Code in Practice Cpp." << endl;
    
    vector<int> v{1, 2, 3};
    v.push_back(10);
    //cout << v.size() << endl;
    
    //throw out_of_range("out of range");
    
    //narrow_cast compare two type value, throw runtime_error
    //cout << narrow_cast<int>(2.0) << endl; //OK no error 
    //cout << narrow_cast<int>(3.1) << endl; //ERROR have info loss    
        
    vector<vector<int>> mv{
        {1}, 
        {2, 3},
        {4, 5, 6}}; 
    mv.push_back({7, 8, 9, 0});
    //cout << mv.size() << endl;
    //cout << mv[3][2] << endl;
    
    vector<string> words;
    cout << "Input words: ";    
    for(string temp; cin >> temp; )
        words.push_back(temp);
    
    sort(words.begin(), words.end());
    
    for(int i=0; i < words.size(); ++i)
        if(i==0 || words[i - 1] != words[i]) 
            cout << words[i] << " ";
    cout << endl;
    
    return 0;
}
catch(out_of_range& ex){
    cerr << "error: " << ex.what() << endl;
    return 1;
}
catch(runtime_error& re){
    cerr << "runtime error: " << re.what() << endl;
    return 2;
}
catch(...){
    cerr << "Have unknown errors" << endl;
    return -1;
}

Pector::Pector(int num) : elem{new double[num]}, sz{num} {}

double& Pector::operator[](int i){
        return elem[i];
}

double read_and_sum(int n){
    Pector p(n);
    for(int i=0; i != n; i++)
        cin >> p[i];
    
    double sum = 0;
    for(int i=0; i != n; i++)
        sum += p[i];
    return sum;
}


