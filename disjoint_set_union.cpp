#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int a, b;
};

/// we assume the integers are from 1 to n

void make_set(int p[], int x)
{
    p[x] = x;
}

int find_set(int p[], int x)
{
    if (x != p[x])
        /// return p[x] = find_set(p, p[x]);
        return find_set(p, p[x]);
    return p[x];
}

void _union(int p[], int x, int y)
{
    int a = find_set(p, x);
    int b = find_set(p, y);
    p[a] = b;
}

void connected_component(int p[], int V, vector<Edge> edges)
{
    for (int i = 0; i < V; i++)
    {
        make_set(p, i);
    }
    for (Edge e : edges)
    {

        int f_a = find_set(p, e.a);
        int f_b = find_set(p, e.b);
        if (f_a != f_b)
        {
            _union(p, e.a, e.b);
        }
    }
}

bool same_component(int p[], int u, int v)
{
    if (find_set(p, u) != find_set(p, v))
        return false;
    return true;
}

int count_components(int p[], int V)
{
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (p[i] == i)
            count++;
    }

    cout << count << endl;
    return count;
}

int main()
{

    int V, E;
    vector<Edge> edges;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b}); // creating a structure then pushing
    }

    int p[V];
    connected_component(p, V, edges);
    count_components(p, V);
    // cout<<"here"<<endl;

    while (1)
    {
        // cout<<"here"<<endl;
        int a, b;
        cin >> a >> b;
        bool is_same = same_component(p, a, b);

        if (is_same)
            cout << a << " and " << b << " are in the same component" << endl;
        else
            cout << a << " and " << b << " are not in the same component" << endl;
    }
}
