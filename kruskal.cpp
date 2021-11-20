#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int u;
    int v;
    int w;
    Node(int f, int s, int wt)
    {
        u = f;
        v = s;
        w = wt;
    }
};

bool comp(Node a, Node b)
{
    return a.w < b.w;
}

int findPair(int u, vector<int> &parent)
{
    if (parent[u] == u)
        return u;
    return parent[u] = findPair(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int x = findPair(u, parent);
    int y = findPair(v, parent);
    if (x == y)
    {
        parent[y] = x;
        rank[x]++;
    }
    if (rank[x] > rank[y])
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
    }
}

int main()
{

    int N, M;
    cin >> N >> M;

    vector<Node> g;
    int a, b, w;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> w;
        g.push_back(Node(a, b, w));
    }

    sort(g.begin(), g.end(), comp);

    vector<int> parent(N);
    vector<int> rank(N, 0);

    for (int i = 0; i < N; i++)
        parent[i] = i;

    vector<pair<int, int>> mst;

    for (auto it : g)
    {
        if (findPair(it.u, parent) != findPair(it.v, parent))
        {
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }

    for (auto it : mst)
    {
        cout << it.first << " " << it.second << endl;
    }
}