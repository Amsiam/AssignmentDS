#include<iostream>

using namespace std;


void arrayInput(int arr[], int n){
    for(int i=0;i<n;i++)cin>>arr[i];
}

int search(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(key==arr[i])return i+1;
    }
    return 0;
}

void insert(int arr[],int n,int pos, int val){
    int i = n-1;

    while(pos<=i){
        arr[i+1] = arr[i];
        i--;
    }
    arr[pos] = val;
}

void del(int arr[],int n,int pos){
    int i = pos;

    while(i<n-1){
        arr[i] = arr[i+1];
        i++;
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}


int main(){

    int arr[1000];
    cout<<"Enter Size of Array: ";
    int n;
    cin>>n;
    cout<<"Enter Elements of the array: "<<endl;
    arrayInput(arr,n);

    int op;
    while (1)
    {
        cout<<"1. Insert\n2. Delete\n3. Search\n4. Travers\n0. Exit\nEnter Option: ";
        cin>>op;
        switch (op)
        {
        case 0:
        return 0;
        case 1:
        {
            cout<<"Enter position: ";
            int pos,val;
            cin>>pos;
            cout<<"Enter Value: ";
            cin>>val;

            pos--;
            insert(arr,n,pos,val);
            n++;
        }
        break;
        case 2:
        {
            cout<<"Enter position: ";
            int pos;
            cin>>pos;
            pos--;
            del(arr,n,pos);
            n--;
        }
        break;
        case 3:
        {
            cout<<"Enter Key: ";
            int key;
            cin>>key;
            int pos = search(arr,n,key);
            if(pos)cout<<"Your key found at position "<<pos<<endl;
            else cout<<"Your key is not found."<<endl;
        }
        break;
        case 4:
        print(arr,n);
        break;
        default:
        cout<<"You Entered Wrong Option! Try again."<<endl;
            break;
        }
    }



}