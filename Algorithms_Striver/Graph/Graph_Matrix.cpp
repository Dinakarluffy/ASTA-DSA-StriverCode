#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    n = 5, m = 4;
    int adj[n + 1][n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v]=1;
        adj[v][u]=1; 
        /*
        FOR WEIGHTED assign
        int wt;
        cin>>wt;
        adj[u][v]=wt;
        adj[v][u]=wt; 

        If Directed Graph
        int u, v;
        cin >> u >> v;
        adj[u][v]=1;
        
        */
    }
}