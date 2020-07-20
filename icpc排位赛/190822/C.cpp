#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 21092013;
const ll inv = 10546007;
vector<int> v[10005];
int l[10005], r[10005];
ll dp[10005][55];
ll de[10005][55];
ll ans[55];

int gcd(int x, int y)
{
    if(y == 0) return x;
    return gcd(y, x % y);
}

void dfs(int x, int fa)
{
    for(int i = 0; i < v[x].size(); i ++)
    {
        if(fa == v[x][i]) continue;
        dfs(v[x][i], x);
        for(int j = l[x]; j <= r[x]; j ++)
            for(int k = 1; k <= 50; k ++)
                dp[x][gcd(k, j)] += dp[v[x][i]][k],
                dp[x][gcd(k, j)] %= mod;
        for(int j = 1; j <= 50; j ++)
            de[x][j] += dp[v[x][i]][j],
            de[x][j] %= mod;

    }
    for(int i = l[x]; i <= r[x]; i ++) dp[x][i] ++;
    for(int i = 1; i <= 50; i ++) ans[i] += dp[x][i] * 2, ans[i] %= mod;
    for(int i = 0; i < v[x].size(); i ++)
    {
        if(fa == v[x][i]) continue ;
        for(int j = 1; j <= 50; j ++)
            for(int k = 1; k <= 50; k ++)
                for(int p = l[x]; p <= r[x]; p ++)
                {
                    int gc = gcd(p, gcd(j, k));
                    ll tmp = de[x][j] - dp[v[x][i]][j];
                    tmp = tmp * dp[v[x][i]][k], tmp %= mod;
                    ans[gc] += tmp, ans[gc] %= mod;
                }
    }
}
int read()
{
	int x = 0;
	char in = getchar();
	while(in < '0' || in > '9')
	{
		in = getchar();
	}
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in - '0';
		in = getchar();
	}
	return x;
}
int main()
{
    int T = read();
    for(int cas = 1; cas <= T; cas ++)
    {
        int n, x, y;
        n = read();
        for(int i = 1; i < n; i ++)
            v[i].clear();
        for(int i = 1; i < n; i ++)
        {
        	x = read() , y = read();
            v[x].push_back(y), v[y].push_back(x);
        }
        for(int i = 1; i <= n; i ++)
            l[i] = read(), r[i] = read();
        memset(dp, 0, sizeof(dp));
        memset(de, 0, sizeof(de));
        memset(ans, 0, sizeof(ans));
        dfs(1, 0);
        printf("Case %d:\n",cas);
//        cout << "Case " << cas << ":" << endl;
        for(int i = 1; i <= 50; i ++)
            printf("%d: %lld\n",i,((ans[i]%mod)*inv)%mod);
//			cout << i << ": " << ans[i] * inv % mod << endl;
    }
    return 0;
}

/*
1
3
1 2
1 3
1 2
1 2
1 2

*/
