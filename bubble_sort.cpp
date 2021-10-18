#include <iostream>

using namespace std;

void bubbleSort(string &arr, int n)
{
    char t;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                t = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = t;
            }
        }
    }
}

int main()
{
    cout << "Enter Size of Array: ";
    int n;
    cin >> n;
    string arr;
    cout << "Enter String: " << endl;
    cin >> arr;
    bubbleSort(arr, n);
    cout << "Sorted Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}