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
    //cout << v.size() << endl;
        
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
    string pre = "";
    for(string temp : words)
        if(pre != temp){
            cout << temp << " ";
            pre = temp;
        }
    cout << endl;
    return 0;
}
//test git pull
