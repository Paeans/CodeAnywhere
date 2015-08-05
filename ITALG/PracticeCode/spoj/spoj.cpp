#include <iostream>
#include <cstring>

using namespace std;

void nextpalindrome(string number){
    long length = number.size();
    int diff = 0;
    for(long i=length/2-1; i>=0 && diff == 0; i--)
        diff = number[i] - number[length - 1 - i];
    string result = number.substr(0, length/2 + length%2);
    
    if(diff == 0 || diff < 0){
        int tag = 1;
        long s = result.size();
        while(tag != 0 && --s >= 0){
            char tmp = result[s] + 1;
            result[s] = tmp > '9' ? '0' : tmp;
            tag = tmp > '9' ? 1 : 0;
        }
        if(tag == 1) result = '1' + result;
    }
    
    long index = length/2 -1; //length - length/2 - length%2 -1;
    if(index < 0 && result.size() == 2) cout << result[0] << result[0];
    else {
        cout << result;
        while(index >= 0) cout << result[index--];
    }
    cout << endl;    
}

void testnextpd(){
    int counter{0};
    cin >> counter;
    while(counter-- > 0){
        string number = "";
        cin >> number;
        nextpalindrome(number);
    }
}

void printexp(string num1, string num2, string result, char op){
    int s1 = num1.size();
    int s2 = num2.size();
    int rs = (rs = (s1 > (s2 + 1) ? s1 : s2 + 1)) > result.size() ? rs : result.size();
    bool tag = false;
    for(int i=rs-1; i>=0; i--)
        cout << (i >= s1 ? ' ' : num1[i]);
    cout << endl;
    for(int i=rs-1; i>=0; i--)
        cout << (i == s2 ? op : (i > s2 ? ' ' : num2[i])) ;
    cout << endl;
    for(int i=rs-1; i>=0; i--)
        cout << '_';
    cout << endl;
    for(int i=rs-1; i>=0; i--)
        cout << (i >= result.size() ? ' ' : ((tag || (tag = result[i] != '0')) ? result[i] : ' '));
    cout << endl << endl;
}

string plusop(string num1, string num2){
    string result = "";
    int tag = 0;
    int s1 = num1.size();
    int s2 = num2.size();
    int rs = s1 > s2 ? s1 : s2;
    for(int i=0; i<rs; i++){
        int tmp = tag + (i>=s1 ? 0 : num1[i] - '0' ) + (i>=s2 ? 0:num2[i] - '0');
        tag = tmp /10;
        tmp = tmp %10;
        result += ('0' + tmp);
    }
    if(tag ==1) result+='1';
    return result;
}

void plus2num(string num1, string num2){
    string result = plusop(num1, num2);
    printexp(num1, num2, result, '+');
}

string minusop(string num1, string num2){
    string result = "";
    int tag = 0;
    int s1 = num1.size();
    int s2 = num2.size();
    int rs = s1 > s2 ? s1 : s2;
    for(int i=0; i<rs; i++){
        int tmp = (i>=s1 ? 0 : num1[i] - '0' ) - (i>=s2 ? 0:num2[i] - '0') - tag;
        tag = tmp < 0 ? 1 : 0;
        tmp = tmp < 0 ? tmp + 10 : tmp;
        result += ('0' + tmp);
    }
    return result;
}
void minus2num(string num1, string num2){
    string result = minusop(num1, num2);
    printexp(num1, num2, result, '-');    
}

void mutil2num(string num1, string num2){
    string tmp[num2.size()];
    for(int i=num2.size() - 1; i>=0; i--){
        
    }
}

void parsearith(string arith){
    char op;
    string exp1 = "";
    string exp2 = "";
    bool tag = false;
    for(int i=arith.size()-1; i>=0; i--)
        if(arith[i] == '+' || arith[i] == '-' || arith[i] == '*'){
            op = arith[i];
            tag = true;
        }else{
            if(tag) exp1 += arith[i];
            else exp2 += arith[i];
        }
    switch(op){
        case '+': 
            plus2num(exp1, exp2);
            break;
        case '-': 
            minus2num(exp1, exp2);
            break;
        case '*': break;
    }        
}



int main(){
    
    //testnextpd();
    parsearith("12345+67890");
    parsearith("324-111");
}