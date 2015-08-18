#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cout << "Code in Practice Cpp." << endl;
    vector<int> v{1, 2, 3};
    cout << v.size() << endl;
    v.push_back(10);
    v.push_back(11);
    cout << v.size() << endl;
    return 0;
}