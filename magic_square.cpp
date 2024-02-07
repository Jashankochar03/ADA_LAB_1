#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;


const int size = 100;
void generator(int a[size][size],int n){
 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    a[i][j]= 0;
 } 
}

int magic_sq(int a[size][size],int n){
   int i = n/2;
   int j = n-1;
   for(int k=1;k<=n*n;){
        if(a[i][j]==0){
        a[i][j]=k;
        k++;
        i--;
        j++;
        }
        if(i<0 && j<n)
        i=n-1;
        else if(i>=0 && j==n)
        j = 0;
        else if(i<0 || j==n){
            i = 0;
            j = n-2;
        }
        if(a[i][j] !=0){
            i++;
            j = j-2;
        }
   }

}

void print(int a[size][size],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main(){
 //cout<<"done1"<<endl;
 fstream file;
 int avg_time =0;
 int total_time = 0;

 file.open("magic_square_result.txt",ios::out);
 for(int i=3;i<=size;i=i+2){
    int a[size][size];
    avg_time =0;
    total_time = 0;
    int k = 0;
    int x =1;
    cout<<endl;
    for (int m=0;m<10;m++){
        generator(a,i);
        cout<<"done1"<<endl;
    auto start = high_resolution_clock::now();
    magic_sq(a,i);
    auto stop = high_resolution_clock::now();
    cout<<"done2"<<endl;
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    }
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<"("<<i<<","<<avg_time<<")"<<endl;
    print(a,i);
 }
 cout<<"done"<<endl;

 return 0;
}
