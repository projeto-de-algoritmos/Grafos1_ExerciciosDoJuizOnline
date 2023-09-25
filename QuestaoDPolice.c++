#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
const ll mod = 1e9 + 7,inf = 1e18;

int main()
{
    setIO();
    int n,k,d;
    cin>>n>>k>>d;
    vvvi adj(n + 1);//because we need to store the indices of each edge
    vi dist(n + 1,1e9);
    vb vis(n + 1,false);
    vi colour(n,UNVISITED);
    queue<int>q;

   
    vi ans;
    for (int i = 1;i<=n - 1;i++)
        if (colour[i] == UNVISITED)ans.pb(i);
    cout<<ans.size()<<'\n';
    for (int edge:ans)cout<<edge<<" ";
    return 0;
}
