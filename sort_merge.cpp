#include <iostream>
#include <fstream>

using namespace std;

int mergeList(long *data, long start, long end, long step){
    long length = end - start;
    long mid = start + step;
    long index01 = start;
    long index02 = mid;
    if(index02 >= end) return 0;
    
    long *tmp = new long[length];
    long i=0;
    while(index01 < mid && index02 < end)
        tmp[i++] = data[index01] > data[index02] ? data[index02++] : data[index01++];
    while(index01 < mid)
        tmp[i++] = data[index01++];
    while(index02 < end)
        tmp[i++] = data[index02++];
    
    while(length-- > 0) data[start + length] = tmp[length];
    delete[] tmp;
    return 0;
}

int main(){
	
	ifstream filereader;
	filereader.open("data.txt", ios::in);
    ofstream outstream;
	outstream.open("result.txt", ios::out);
	
    long number;
    filereader >> number;
    outstream << number << endl;
    while(number-- > 0){
        long num;
        filereader >> num;
        long *data = new long[num];
        long counter = 0;
        while(counter < num) filereader >> data[counter++];

        time_t begin = time(NULL);
        
        long n = 1;
        while(n < num){
            long start = 0;
            while(start < num){  
                long end = start + 2 * n;
                mergeList(data, start, end > num ? num : end, n);
                start = end;
            }            
            n = n*2;
        }
        time_t end = time(NULL);
        //cout << "End time is:    " << end << endl;	
        cout << "Time used to sort(merge) "<< num << " number is: " <<  end - begin << endl;
        
        outstream << num << endl;
        counter = 0;
        while(counter < num) outstream << data[counter++] << " ";
        outstream << endl;
        delete[] data;
    }
	filereader.close();
	outstream.close();
}



