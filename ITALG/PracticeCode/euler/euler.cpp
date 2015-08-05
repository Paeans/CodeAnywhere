#include <iostream>
#include <cmath>
#include <cstring>
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

long maxcommon(long a, long b){
    
    while(a != 0 && b !=0){
        long tmp = b;
        b = a % b;
        a = tmp;
    }
    return a + b;
}

/**
every new num, only need to multiply the remains of the common 
of the num and the previous result
**********************************
AND CAN BE CHANGE TO MORE EASY WAY
every number can be a multiple of a list of prime numbers
p^n == num --> a = floor(log(num) / log(p)) //the max prime
then N = N * p ^ a
** when p > sqrt(num), a will be 1 
*/
long smallmulti(int num){
    long result = 1;
    for(int i=1; i<=num; i++)
        result *= i/maxcommon(i, result);
    return result;
}

long sumofsquere(long n){
    long result{0};
    do{
        result += n * n;
    }while(--n != 0);
    return result;
}
long squereofsum(long n){
    return n*n*(n+1)*(n+1)/4;
}

bool isPrime(long number){
    for(int i=2; i<=sqrt(number); i++)
        if(number % i == 0) return false;
    return true && number >= 2;
}
long findnthprime(long nth){
    long result{3};
    long counter{2};
    while(counter < nth){
        result +=2;
        if(isPrime(result)) counter++;
    }
    return nth == 1 ? 2 : result;
}

long gstproduct(string numlist, long number){    
    if(numlist.size() < number) return 0;
    long result{1};
    for(long i{0}; i<number; i++)
        result *= (numlist[i] - '0');
    long tmp{result};
    long index{number};
    while(index < numlist.size()){
        tmp = tmp * (numlist[index] - '0') / (numlist[index - number] - '0');
        result = tmp > result ? tmp : result;
        index++;
    }
    return result;
}
long splitandcaul(string numlist, long number){
    long result{0};
    string tmp = "";
    for(int i=0; i<numlist.size(); i++){
        if(numlist[i] == '0') {
            long tmpproduct = gstproduct(tmp, number);
            result = tmpproduct > result ? tmpproduct : result;            
            tmp = "";
        }else tmp += numlist[i];
    }    
    return result;
}

int main(){   
   
    //cout << findsumunder(1000, 3, 5) << endl;
    //cout << sumevenfibo(4000000) << endl;
    //cout << bigestprimefactor(600851475143) << endl;
    //cout << getmaxpalin() << endl;    
    //cout << smallmulti(20) << endl;
    //cout << squereofsum(100) - sumofsquere(100) << endl;
    //cout << findnthprime(10001) << endl;
    /**
    string numlist = 
"73167176531330624919225119674426574742355349194934\
96983520312774506326239578318016984801869478851843\
85861560789112949495459501737958331952853208805511\
12540698747158523863050715693290963295227443043557\
66896648950445244523161731856403098711121722383113\
62229893423380308135336276614282806444486645238749\
30358907296290491560440772390713810515859307960866\
70172427121883998797908792274921901699720888093776\
65727333001053367881220235421809751254540594752243\
52584907711670556013604839586446706324415722155397\
53697817977846174064955149290862569321978468622482\
83972241375657056057490261407972968652414535100474\
82166370484403199890008895243450658541227588666881\
16427171479924442928230863465674813919123162824586\
17866458359124566529476545682848912883142607690042\
24219022671055626321111109370544217506941658960408\
07198403850962455444362981230987879927244284909188\
84580156166097919133875499200524063689912560717606\
05886116467109405077541002256983155200055935729725\
71636269561882670428252483600823257530420752963450";
    
    cout << splitandcaul(numlist, 4) << endl;
    cout << splitandcaul(numlist, 13) << endl;
    */
    
}




