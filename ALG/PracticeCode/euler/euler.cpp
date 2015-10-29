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
    if(number % 2 == 0) return false;
    for(int i=3; i<=sqrt(number); i+=2){
        if(number % i == 0) return false;
    }        
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

int pathagorean(int sum){
    for(int c=sum/3; c<=sum; c++)
        for(int a=1; a<c; a++)
            for(int b=a+1; b<c; b++)
                if((a+b+c) == sum && (a*a + b*b) == c*c){
                    cout << a << " " << b << " " << c << endl;
                    return a*b*c;
                }               
}

long sumofprime(long num){
    long result = 2;
    long tmp = 3;
    while(tmp < num){
        if(isPrime(tmp)) result += tmp;
        tmp += 2;
    }
    return result;
}

void p11(){
    int date[23][26]={0};
    long result = 0;
    for(int i=0; i<20 * 20; i++){
        cin >> date[i/20][i%20+3];
    }
    
    for(int i=0; i<20; i++){
        for(int j=3; j<23; j++){
            long tmp;
            result = (tmp = date[i][j] * date[i][j+1] * date[i][j+2] * date[i][j+3]) > result ? tmp : result;
            result = (tmp = date[i][j] * date[i+1][j] * date[i+2][j] * date[i+3][j]) > result ? tmp : result;
            result = (tmp = date[i][j] * date[i+1][j+1] * date[i+2][j+2] * date[i+3][j+3]) > result ? tmp : result;
            result = (tmp = date[i][j] * date[i+1][j-1] * date[i+2][j-2] * date[i+3][j-3]) > result ? tmp : result;
        } 
    }
    cout <<  result << endl;
}

int p12_factor(long num){
    int result = 1;
    int counter = 0;
    int i=2;
    while(num > 1)
        if(num % i == 0){
            counter++;
            num /= i;
        }else{
            result *= (counter+1);
            counter = 0;
            i++;
        }    
    return result * (counter + 1);
}

long p12(int count){
    long result = 0;
    long num = 1;    
    while(p12_factor(result += num++) < count);
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
    //cout << pathagorean(1000) << endl;    
    //p11();
    /**  p11 input
08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48
    */
    /**
    int count = 0;
    cin >> count;
    cout << p12(count) << endl;  
    */
}




