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

int binarySearch(int arr[],int l, int h,int key){
    if(l>h)return 0;

    int mid = (l+h)/2;

    if(arr[mid]==key)return mid+1;

    if(arr[mid]<key)return binarySearch(arr,mid+1,h,key);
    else return binarySearch(arr,l,mid-1,key);
}

int main(){
    cout<<"Enter Size of Array: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter Elements of the array: "<<endl;
    arrayInput(arr,n);
    bubbleSort(arr,n);
    int key;
    cout<<"Enter Key: ";
    cin>>key;
    int pos = binarySearch(arr,0,n-1,key);

    if(pos)cout<<"Your key found."<<endl;
    else cout<<"Your key is not found."<<endl;

    return 0;
}