#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

const int size = 100000;
void random_generator(int a[],int n){
 for(int i=0;i<n;i++){
    a[i]= rand()%size;
 } 
}

float power(int base, int n , int res, int k = 1){
    if(n==0){
       return 1;
    }
    else if(k==n){
        return res;
    }
    else if((k*2<n) || ((k*2>n) && (k*2-n)<(n-k))){
        return power(base,n,res*res,k*2);
    }
    else if(k<n){
        return power(base,n,base*res,k+1);
    }
    else{
        return power(base,n,res/base,k-1);
    }
    
}

int main(){
 fstream file;
 file.open("power_rec.txt",ios::out);
 for(int i=1; i<=size;){
    int avg_time =0;
    int total_time = 0;
    for (int m=0;m<10;m++){
    auto start = high_resolution_clock::now();
    float result=power(2,i,2);
    auto stop = high_resolution_clock::now();
    cout<<"result is "<<result<<endl;
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    }
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<i<<"   "<<avg_time<<endl;
      if(i<1000)
     i *=10;
     else if(i>=1000 && i<5000)
     i=5000;
     else
     i +=5000;
   
 }
}