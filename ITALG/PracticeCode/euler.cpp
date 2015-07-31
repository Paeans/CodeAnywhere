#include <iostream>
using namespace std;
/**
get sum of a list of numbers, 
which is less than num and is multiples of f1 
*/
int findsumunder(int num, int f1){
    auto count = (num-1) / f1;
    return f1*count*(count+1)/2;
}
/**
get sum of a list of numbers
which is less than num and is multiples of f1 or f2
*/
int findsumunder(int num, int f1, int f2){
    return findsumunder(num, f1) 
        + findsumunder(num, f2) 
        - findsumunder(num, f1 * f2);
}

/**
sum of all the even fibonacci numbers
f0 = 0
f1 = 2
fn = 4*f(n-1) + f(n-2) [n >= 2]
*/
int sumevenfibo(int num){
    int sum{0}, f0{0}, f1{2};
    
    while(f1 < num){
        sum += f1;
        int tmp = 4*f1 + f0;
        f0 = f1;
        f1 = tmp;
    }
    return sum;
}

int bigestprimefactor(long num){
    int base = 2;
    while(num != 1){
        if(num % base ==0) num /= base;
        else base++;
    }
    return base;
}

bool isPalindromic(int num){
    int tmp = num;
    int res = 0;
    while(tmp !=0){
        res = res* 10 + tmp % 10;
        tmp /= 10;
    }
    return res == num;
}

int getmaxpalin(){
    auto result = 0;
    auto a=0;
    auto b=0;
    for(int i=999; i>=100; i--)
        for(int j = (a % 11 == 0) ? 999 : 990; 
            j >= i; j -= (a % 11 == 0) ? 1 : 11)
            if(i*j < result) break;
            else if(isPalindromic(i*j)) {
                a=i;b=j;
                result = i*j;
            }
    cout << a << " " << b << endl;
    return result;
}

int get3n1steps(long n){
    int count{1};
    while(n != 1){
        count++;
        n = n%2==0 ? n/2 : 3*n+1;        
    }
    return count;
}

int getmaxsteps(long a, long b){
    
        int step = 0;
        long start = a > b ? b : a;
        long stop = a > b ? a : b;
        for(long i=start; i<=stop; i++){
            int tmp = get3n1steps(i);
            if(tmp > step) step = tmp;
        }
        cout << a << " " << b << " " << step << endl;
}

int main(){   
   
    //cout << findsumunder(1000, 3, 5) << endl;
    //cout << sumevenfibo(4000000) << endl;
    //cout << bigestprimefactor(600851475143) << endl;
    //cout << getmaxpalin() << endl;    
}




