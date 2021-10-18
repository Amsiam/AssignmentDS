#include <iostream>
using namespace std;

int stack()
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

int queue()
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

int main()
{
    int op;
    while (1)
    {
        cout << "1.Stack\n2.Queue\n0.Exit\nEnter Your Option: ";
        cin >> op;
        switch (op)
        {
        case 1:
            stack();
            break;
        case 2:
            queue();
            break;
        case 0:
            return 0;
        default:
            cout << "You Entered Wrong Option! Try again." << endl;
            break;
        }
    }
}