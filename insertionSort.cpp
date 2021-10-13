#include<iostream>

using namespace std;


void arrayInput(int arr[], int n){
    for(int i=0;i<n;i++)cin>>arr[i];
}

void print(int arr[],int n){
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int k = arr[i];
       int  j = i-1;
        while(j>=0 and arr[j]>k){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]= k;
    }
}

int main(){
    cout<<"Enter Size of Array: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter Elements of the array: "<<endl;
    arrayInput(arr,n);
    insertionSort(arr,n);
    cout<<"Sorted Array"<<endl;
    print(arr,n);
    return 0;
}