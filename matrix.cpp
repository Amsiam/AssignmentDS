#include <iostream>

using namespace std;

class Matrix
{
public:
    int arr[100][100];
    int r, c;
    Matrix(int row, int col)
    {
        r = row;
        c = col;
    }
    void input()
    {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> arr[i][j];
    }
    void print()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    Matrix operator*(Matrix &b)
    {
        Matrix w(r, b.c);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < b.c; j++)
            {
                w.arr[i][j] = 0;
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < b.c; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    w.arr[i][j] += arr[i][k] * b.arr[k][j];
                }
            }
        }
        return w;
    }
    Matrix operator+(Matrix &b)
    {
        Matrix w(r, c);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                w.arr[i][j] = arr[i][j] + b.arr[i][j];
            }
        }
        return w;
    }
    Matrix t()
    {
        Matrix w(c, r);
        for (int i = 0; i < c; i++)
        {
            for (int j = 0; j < r; j++)
            {
                w.arr[i][j] = arr[j][i];
            }
        }
        return w;
    }
};

int main()
{
    cout << "1. Sum\n2. Multiply\n 3.Transpose\n0. Exit\n";
    int op;
    while (1)
    {
        cout << "Enter option: ";
        cin >> op;
        switch (op)
        {
        case 1:
        {
            cout << "Enter Size of Matrix A:";
            int x, y;
            cin >> x >> y;
            Matrix A(x, y);
            cout << "Enter Size of Matrix B:";
            cin >> x >> y;
            Matrix B(x, y);
            if (A.r == B.r && A.c == B.c)
            {
                cout << "Enter  Matrix A:" << endl;
                A.input();
                cout << "Enter  Matrix B:" << endl;
                B.input();

                Matrix C = A + B;
                C.print();
            }
            else
            {
                cout << "Summation Not posible." << endl;
            }
        }
        break;

        case 2:
        {
            cout << "Enter Size of Matrix A:";
            int x, y;
            cin >> x >> y;
            Matrix A(x, y);
            cout << "Enter Size of Matrix B:";
            cin >> x >> y;
            Matrix B(x, y);
            if (A.c == B.r)
            {
                cout << "Enter  Matrix A:" << endl;
                A.input();
                cout << "Enter  Matrix B:" << endl;
                B.input();

                Matrix C = A * B;
                C.print();
            }
            else
            {
                cout << "Multiplication Not posible." << endl;
            }
        }
        break;
        case 3:
        {
            cout << "Enter Size of Matrix A:";
            int x, y;
            cin >> x >> y;
            Matrix A(x, y);
            cout << "Enter  Matrix A:" << endl;
            A.input();
            Matrix C = A.t();
            C.print();
        }
        break;
        default:
            return 0;
        }
    }
}