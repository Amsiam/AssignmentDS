#include<iostream>

using namespace std;


void arrayInput(int arr[], int n){
    for(int i=0;i<n;i++)cin>>arr[i];
}

void print(int arr[],int n){
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}

void bubbleSort(int arr[],int n){
    int t;
    for(int i=0;i<n-1;i++){
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                t = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = t;
            }
        }
        
    }
}

int main(){
    cout<<"Enter Size of Array: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter Elements of the array: "<<endl;
    arrayInput(arr,n);
    bubbleSort(arr,n);
    cout<<"Sorted Array"<<endl;
    print(arr,n);
    return 0;
}