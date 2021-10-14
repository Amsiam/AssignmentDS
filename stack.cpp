#include <iostream>
using namespace std;

int main()
{
    cout << "Enter Size of Stack: ";
    int n;
    cin >> n;
    int arr[n];
    int top = -1;

    int op;
    cout << "1. Push\n2. Pop\n3. Top\n0. Exit\n";
    while (1)
    {
        cout << "Enter Option: ";
        cin >> op;
        switch (op)
        {
        case 0:
            return 0;
        case 1:
        {
            if (top == n - 1)
            {
                cout << "Stack is Full." << endl;
                break;
            }
            int val;
            cout << "Enter Value: ";
            cin >> val;
            arr[++top] = val;
        }
        break;
        case 2:
        {
            if (top == -1)
            {
                cout << "Stack is Empty." << endl;
                break;
            }
            --top;
        }
        break;
        case 3:
        {
            if (top == -1)
            {
                cout << "Stack is Empty." << endl;
                break;
            }
            cout << "Top: " << arr[top] << endl;
        }
        break;
            break;
        default:
            cout << "You Entered Wrong Option! Try again." << endl;
            break;
        }
    }
}