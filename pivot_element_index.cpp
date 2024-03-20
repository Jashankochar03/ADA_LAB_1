#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;
const int size = 100000;
void random_generator(int a[],int n){
 for(int i=0;i<n;i++){
    a[i]= rand();
 } 
}

 

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count1 = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count1++;
    }
    // Giving pivot element its correct position
    int pivotIndex = start + count1;
    swap(arr[pivotIndex], arr[start]);
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
       
    }
     return pivotIndex;
    
}
int find_index(int a[],int low,int high){
    int i=low;
    int j=high;
     int pivot = a[low];
    do{
        while(a[i]<=pivot)
        i++;
        while(a[j]>pivot)
        j--;
        if(i<j){
            swap(a[i],a[j]);
        }
    }while(i<=j);
    a[low]=a[j];
    a[j]=pivot;
    return j;
    }

void print(int a[],int n){
    cout<<"done4"<<endl;
    for(int i=0;i<n;i++){
            cout<<a[i]<<"\t";
        }
        cout<<endl;
    }

int main(){
 fstream file;
 file.open("pivot.txt",ios::out);
 for(int i=10; i<=size;){
    int a[i];
    int avg_time =0;
    int total_time = 0;
    random_generator(a,i);
    //print(a,i);
    for (int m=0;m<10;m++){
    auto start = high_resolution_clock::now();
    find_index(a,0,i);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    total_time +=duration.count();
    }
    //print(a,i);
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" nanoseconds"<<endl;
     file<<i<<","<<avg_time<<endl;
    if(i<1000)
     i *=10;
     else if(i>=1000 && i<5000)
     i=5000;
     else
     i +=5000;
 }
 file.close();
 return 0;
}
