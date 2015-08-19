#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cout << "Code in Practice Cpp." << endl;
    
    vector<int> v{1, 2, 3};
    v.push_back(10);
    cout << v.size() << endl;
    
    vector<vector<int>> mv{
        {1, 2, 3}, 
        {4, 5, 6},
        {7, 8, 9}};
    cout << mv.size() << endl;
    cout << mv[1][1] << endl;
    
    return 0;
}