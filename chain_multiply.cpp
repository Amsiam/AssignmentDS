#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int arr[1000];

#define int long long

int min(int a, int b)
{
    return a < b ? a : b;
}

int split[1000][1000];

int mcm(int i, int j)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = 1e9;

    for (int k = i; k < j; k++)
    {

        int a = min(dp[i][j], mcm(i, k) + mcm(k + 1, j) + arr[i - 1] * arr[k] * arr[j]);

        if (a < dp[i][j])
        {
            split[i][j] = k;
            dp[i][j] = a;
        }
    }
    return dp[i][j];
}

signed main()
{

    int N;
    cin >> N;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < N; i++)
    {

        cin >> arr[i];
    }

    cout << mcm(1, N - 1) << endl;

    for (int i = 1; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            cout << split[i][j] << " ";
        }
        cout << endl;
    }
}

// input:
// 5
// 20
// 30
// 50
// 10
// 5
