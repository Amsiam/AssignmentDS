#include <iostream>

using namespace std;

int main()
{

    cout << "Enter Size of Queue: ";
    int n;
    cin >> n;
    int arr[n];
    int front = -1, rare = -1;

    int op;
    cout << "1. Enqueue\n2. Dequeuq\n3. Front\n0. Exit\n";
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
            if (rare == n - 1)
            {
                cout << "Queue is Full." << endl;
                break;
            }
            int val;
            cout << "Enter Value: ";
            cin >> val;
            arr[++rare] = val;
            if (front == -1)
                front++;
        }
        break;
        case 2:
        {
            if (front == -1 or front > rare)
            {
                cout << "Queue is Empty." << endl;
                break;
            }
            front++;
        }
        break;
        case 3:
        {
            if (front == -1 or front > rare)
            {
                cout << "Queue is Empty." << endl;
                break;
            }
            cout << "Front: " << arr[front] << endl;
        }
        break;
            break;
        default:
            cout << "You Entered Wrong Option! Try again." << endl;
            break;
        }
    }
}