#include <bits/stdc++.h>

using namespace std;

const int N = 41;
int n, m, k, ex, ey;
string a[N];
bool vis[N][N], flag = false;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool check(int x, int y)
{
    return a[x][y] != '#' && !vis[x][y] &&x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int step)
{
    if (step * 2 > k || flag) return;
    if (a[x][y] == '@') 
	{
        flag = true;
        return;
    }

    vis[x][y] = true;
    int xx, yy;
    for(int i=0;i<4;i++) 
	{
        xx = x + dx[i];
        yy = y + dy[i];
        if (check(xx, yy)) 
		{
            if (a[xx][yy] == 's') dfs(xx, yy, step + 1);
            else dfs(xx, yy, step);
        }
        if (flag) return;
    }

    vis[x][y] = false;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) 
	{
        cin >> a[i];
        for(int j=0; j<m; j++) 
		{
            if (a[i][j] == 'x') 
			{
                ex = i;
                ey = j;
            }
        }
    }

    dfs(ex, ey, 0);
    puts(flag ? "SUCCESS" : "IMPOSSIBLE");

    return 0;
}
