#include <bits/stdc++.h>
using namespace std;
 
const int N=2000001;
vector<int> visitados(N);
vector<int> s(N),e(N);

void dfs(vector<vector<int>>&adj, int no, int comprimento, bool check)
{
    visitados[no] = 1;
    
    if(check) s[no] = comprimento;
    else e[no] = comprimento;
 
    for(auto child : adj[no])
    {
        if(!visitados[child])
            dfs(adj, child, comprimento+1, check); 
    }
}

int solve(vector<vector<int>>&adj, int n, int x)
{ 
    dfs(adj,0,0,true);
    fill(visitados.begin(),visitados.end(),0);
    dfs(adj,x-1,0,false);
 
    int comp_max = s[x-1];
    for(int i=0; i<n; i++)
    {
        if(s[i] > e[i])
            comp_max = max(comp_max, s[i]);
    }
    return comp_max*2;
}

int main()
{
    ios_base::sync_with_stdio(false);
 
    int n, x;
    cin >> n >> x;
    vector<vector<int>> adj(n);

    for(int i=0; i<n-1; i++)
    {
        int a,b;
        cin >> a >> b;
 
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    cout << solve(adj,n,x) << '\n';
}
