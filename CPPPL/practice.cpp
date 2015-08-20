#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
try{
    cout << "Code in Practice Cpp." << endl;
    
    vector<int> v{1, 2, 3};
    v.push_back(10);
    //cout << v.size() << endl;
    
    //throw out_of_range("out of range");
        
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
catch(...){
    cerr << "Have unknown errors" << endl;
    return 2;
}
