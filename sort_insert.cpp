#include <iostream>
#include <fstream>

using namespace std;

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
        
        for(long i=0; i<num; i++){
            long tmp = data[i];
            long j=i;
            while(j-- > 0 && data[j] > tmp) data[j+1] = data[j];
            data[j+1] = tmp;
        }
        time_t end = time(NULL);
        //cout << "End time is:    " << end << endl;	
        cout << "Time used to sort(insert) "<< num << " number is: " <<  end - begin << endl;
        
        outstream << num << endl;
        counter = 0;
        while(counter < num) outstream << data[counter++] << " ";
        outstream << endl;
        delete[] data;
    }
	filereader.close();
	outstream.close();
}

