#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int sz = 2e5+9;
vector < int > l[sz];
void build(int f,int t)
{
	l[f].push_back(t);
	l[t].push_back(f);
}
struct node
{
	int l,r;
}num[sz];
long long dp[sz][2];
int n;
int read()
{
	int x = 0;
	char in = getchar();
	while(in < '0' || in > '9')
		in = getchar();
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in  - '0';
		in = getchar();
	}
	return x;
}
void dfs(int u,int f)
{
	dp[u][0] = 0;
	dp[u][1] = 0;
	for(int i = 0 ; i < l[u].size() ; i ++)
	{
		int v = l[u][i];
		if(v == f)
			continue;
		dfs(v,u);
		dp[u][0] += max(dp[v][0]+abs(num[u].l-num[v].l),dp[v][1]+abs(num[u].l-num[v].r));
		dp[u][1] += max(dp[v][0]+abs(num[u].r-num[v].l),dp[v][1]+abs(num[u].r-num[v].r));
	}
	return ;
}
int main()
{
	int T = read();
	while(T --)
	{
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i ++)
			l[i].clear();
		for(int i = 1 ; i < n ; i ++)
		{
			int f = read() , t = read();
			build(f,t);
		}
		for(int i = 1 ; i <= n ; i ++)
			num[i].l = read() , num[i].r = read();
		dfs(1,0);
		printf("%lld\n",max(dp[1][0],dp[1][1]));
	}
	return 0;
}
