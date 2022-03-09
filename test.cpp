#include <bits/stdc++.h>

using namespace std;

int function1(int x)
{
    int r = 1;
    r += x;
    if (x > 4 && x < 10)
    {
        r += 2 * x;
    }
    else if (x <= 4)
    {
        r += 3 * x;
    }
    else
    {
        r += 4 * x;
    }
    return r;
}
void function2(int x)
{
    for (int i = 1; i < x; i++)
    {
        for (int j = x; j >= i - 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}

int main()
{
    cout << function1(10) << endl;
    function2(10);
}