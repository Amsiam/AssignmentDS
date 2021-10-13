#include<iostream>

using namespace std;


void arrayInput(int arr[], int n){
    for(int i=0;i<n;i++)cin>>arr[i];
}

void print(int arr[],int n){
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}

void selectionSort(int arr[],int size){
    int t;
    for(int i=0;i<size-1;i++){
        int j =i+1;
        int k=i;
        while(j<size){
            if(arr[k]>arr[j]){
                k = j;
            }
            j++;
        }
         t = arr[k];
         arr[k] = arr[i];
         arr[i] = t;
    }
}

int main(){
    cout<<"Enter Size of Array: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter Elements of the array: "<<endl;
    arrayInput(arr,n);
    selectionSort(arr,n);
    cout<<"Sorted Array"<<endl;
    print(arr,n);
    return 0;
}