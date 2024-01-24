#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

//link for graph -https://www.desmos.com/calculator/00qt28qrqe

const int size = 10;
void TT(char a[],int n , int k=0){
    if(k==n){
        for(int i=0;i<n;i++){
            cout<<a[i];
        }
        cout<<endl;
        return ;
    }
    else{
        a[k]='T';
        TT(a,n,k+1);
        a[k]='F';
        TT(a,n,k+1);
    }
}

int main(){
 //cout<<"done1"<<endl;
 char a[size];
 fstream file;
 int avg_time =0;
 int total_time = 0;
 file.open("truth_table_result.txt",ios::out);
 for(int i=1;i<size;i++){
    avg_time =0;
    total_time = 0;
    cout<<endl;
    for (int m=0;m<10;m++){
    auto start = high_resolution_clock::now();
    TT(a,i);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    }
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<"("<<i<<","<<avg_time<<")"<<endl;
 }
 return 0;
}
