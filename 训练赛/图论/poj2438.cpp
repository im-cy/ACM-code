#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int sz = 510;
int n,m;
bool l[sz][sz];
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
int ans[sz];
bool vis[sz];
int s,e;
void dfs(int u)
{
	vis[u] = 1;
	e = u;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(l[u][i])
		{
			int v = i;
			if(vis[v])
				continue;
			ans[++ans[0]] = v;
			dfs(v);
			break;
		}
	}
}
void reverse(int l,int r)
{
	while(l < r)
	{
		swap(ans[l],ans[r]);
		l ++;
		r --;
	}
}
void solve()
{
	s = 1;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(l[s][i])
		{
			e = i;
			break;
		}
	}
	vis[s] = 1 , vis[e] = 1;
	ans[++ans[0]] = s;
	ans[++ans[0]] = e;
	while(12 < 450)
	{
		dfs(e);
		reverse(1,ans[0]);
		swap(s,e);
		dfs(e);
		int mid = 0;
		if(!l[s][e])
		{
			for(int i = 2 ; i < ans[0] ; i ++)//
			{
				if(l[ans[i]][e] && l[ans[i+1]][s])
				{
					mid = i + 1;
					break;
				}
			}
			reverse(mid,ans[0]);
			e = ans[ans[0]];
		}
		if(ans[0] == n)
			break;
		for(int i = 1 ; i <= n ; i ++)
		{
			if(!vis[i])
			{
				int j;
				for( j = 2 ; j < ans[0] ; j ++)
				{
					if(l[ans[j]][i])
					{
						mid = j;
						break;
					}
				}
				if(l[ans[mid]][i])
				{
					e = i;
					mid = j;
					break;
				}
			}
		}
		s = ans[mid-1];
		reverse(1,mid-1);
		reverse(mid,ans[0]);
		ans[++ans[0]] = e;
		vis[e] = 1;
	}
}

int main()
{
	while(scanf("%d%d",&n,&m) && (n || m))
	{
		n *= 2;
		memset(vis,0,sizeof(vis));
		memset(ans,0,sizeof(ans));
		//哈密顿回路 例题题意需要建补图(不用在意建图) 
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 1 ; j <= n ; j ++)
				if(i == j)
					l[i][j] = 0;
				else
					l[i][j] = 1;
		for(int i = 1 ; i <= m ; i ++)
		{
			int f = read() , t = read();
			l[f][t] = 0;
			l[t][f] = 0;
		}
		solve();
		for(int i = 1 ; i <= ans[0] ; i ++)
			printf("%d%c",ans[i],i == (ans[0]) ? '\n' : ' ');
		puts("");
	}
	return 0;
}

