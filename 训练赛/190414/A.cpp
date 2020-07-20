#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 200010;
int l[sz];
int tot = 1;
int hed[sz],nxt[sz];
int tree1[sz],tree2[sz];
bool vis[sz];
struct input
{
	int f,t;
}in[sz];
void build(int f,int t)
{
	l[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
void dfs1(int u)
{
	vis[u] = 1;
	for(int i = hed[u] ; i ; i = nxt[i])
	{
		int t = l[i];
		if(!vis[t])
			dfs1(t);
	}
}
void dfs2(int u)
{
	vis[u] ++;
	for(int i = hed[u] ; i ; i = nxt[i])
	{
		int t = l[i];
		if(!vis[t])
			dfs2(t);
	}
}
int A,B;
int n,m;
void init()
{
	memset(l,0,sizeof(l));
	memset(hed,0,sizeof(hed));
	memset(nxt,0,sizeof(nxt));
	tot = 1;
}
int main()
{
	scanf("%d%d%d%d",&A,&B,&n,&m);
	for(int i = 1 ; i <= m ; i ++)
	{
		scanf("%d%d",&in[i].f,&in[i].t);
		build(in[i].f+1,in[i].t+1);
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		dfs1(i);
		for(int j = 1 ; j <= n ; j ++)
		{
			if(vis[j])
				tree1[i] ++;
			vis[j] = 0;
		}
	}
	init();
	for(int i = 1 ; i <= m ; i ++)
	{
		build(in[i].t+1,in[i].f+1);
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		dfs2(i);
		for(int j = 1 ; j <= n ; j ++)
		{
			if(vis[j])
				tree2[i] ++;
			vis[j] = 0;
		}
	}
	int ans1 = 0 , ans2 = 0 , ans3 = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(tree1[i] > n - A)
			ans1 ++;
		if(tree1[i] > n - B)
			ans2 ++;
		if(tree2[i] > B)
			ans3 ++;
	}
	printf("%d\n%d\n%d\n",ans1,ans2,ans3);
	return 0;
}

