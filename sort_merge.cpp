#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

long * submerge(long *flist, long flength, long *slist, long slength){
    if(flength < 0 || slist < 0) return NULL;
    
    long *result = new long[flength + slength];
    long i, index01, index02;
    i = index01 = index02 = 0;
    
    while(index01 < flength && index02 < slength)
        result[i++] = flist[index01] > slist[index02] ? slist[index02++] : flist[index01++];
    while(index01 < flength)
        result[i++] = flist[index01++];
    while(index02 < slength)
        result[i++] = slist[index02++];
    
    return result;
}

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

        clock_t begin = clock();
        
        long n = 1;
        while(n < num){
            long start = 0;
            while(start < num){

                if(start + n > num) break;

                long slength = start + 2 * n > num ? num - start - n: n;
                long * result = submerge(&data[start], n, &data[start + n], slength );
                //mergeList(data, start, end > num ? num : end, n);
                memcpy(&data[start], result, sizeof(long) * (n + slength));
                delete[] result;
                start += 2 * n;
            }            
            n = n*2;
        }
        clock_t end = clock();
        //cout << "End time is:    " << end << endl;	
        cout << "Time used to sort(merge) " << num << " number is: " << endl 
            << "        "<< end - begin << " clicks" << endl
            << "        "<< ((float)(end - begin))/CLOCKS_PER_SEC << " seconds" << endl;
        
        outstream << num << endl;
        counter = 0;
        while(counter < num) outstream << data[counter++] << " ";
        outstream << endl;
        delete[] data;
    }
	filereader.close();
	outstream.close();
}



