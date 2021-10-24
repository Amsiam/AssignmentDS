#include <bits/stdc++.h>

using namespace std;

void arrayInput(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int binarySearch(int arr[], int l, int h, int key)
{
    if (l > h)
        return 0;

    int mid = (l + h) / 2;

    if (arr[mid] == key)
        return mid + 1;

    if (arr[mid] < key)
        return binarySearch(arr, mid + 1, h, key);
    else
        return binarySearch(arr, l, mid - 1, key);
}

int main()
{
    cout << "Enter Size of Array: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter Elements of the array: " << endl;
    arrayInput(arr, n);
    sort(arr, arr + n);
    int key;
    cout << "Enter Key: ";
    cin >> key;
    int pos = binarySearch(arr, 0, n - 1, key);

    if (pos)
        cout << "Your key found." << endl;
    else
        cout << "Your key is not found." << endl;

    return 0;
}