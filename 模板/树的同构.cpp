#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<ctime>
#include<cmath>
#include<set>
#include<map>
#define ull unsigned long long
#define ll long long
#define INF 10000
using namespace std;
int n,m;
const int N = 2010;
int max_g,g[17];
vector <int> edge[N];
int size[N];
ull Hash[N],RD[N];
void build(int f,int t)
{
	edge[f].push_back(t);
}
void dfs(int u,int fa)
{
	size[u] = 1;
	int tmp = 0;
	for(int i = 0 ; i < edge[u].size() ; i ++)
	{
		int v = edge[u][i];
		if(v == fa) continue;
		dfs(v,u);
		tmp = max(tmp,size[v]+1);
		size[u] += size[v];
	}
	tmp = max(tmp,n-size[u]+1);
	if(tmp == max_g){
		g[++g[0]] = u;
	}
	else if(tmp < max_g)
	{
		g[0] = 1;
		g[g[0]] = u;
		max_g = tmp;
	}
	return ;
}
void dfs_hash(int u,int fa)
{
	Hash[u] = 1;
	size[u] = 1;
	for(int i = 0 ; i < edge[u].size() ; i ++)
	{
		int v = edge[u][i];
		if(v == fa) continue;
		dfs_hash(v,u);
		Hash[u] += Hash[v] ^ RD[size[v]];
		size[u] += size[v];
	}
	Hash[u] *= RD[n-size[u]+1];
}
map < ull,int > MP;
int main()
{
	srand(time(0));
	for(int i = 0 ; i < N ; i ++)
		RD[i] = (ull)rand()*rand();
	while(scanf("%d",&m) != EOF)
	{
		MP.clear();
		for(int i = 1 ; i <= m ; i ++)
		{
			scanf("%d",&n);
			for(int j = 0 ; j <= n ; j ++)
				edge[j].clear();
			int root = 0;//注意要任意找一个点作为根节点 
			for(int j = 1 ; j <= n ; j ++)
			{
				int x;
				scanf("%d",&x);
				if(!x)
				{
					root = j;
					continue;
				}
				build(x,j);
				build(j,x);
			}
			max_g = INF;
			g[0] = 0;
			dfs(root,0);
			ull hs = 1;
			for(int j = 1 ; j <= g[0] ; j ++)
			{
				dfs_hash(g[j],0);
				hs *= Hash[g[j]];
			}
			if(!MP[hs])
				MP[hs] = i;
			printf("%d\n",MP[hs]);//hs为这颗树的hash值 
		}
	}
	return 0;
}
