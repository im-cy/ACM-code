#include<bits/stdc++.h>
#define INF 214748364
using namespace std;
const int sz = 200010;
int in[sz],pre[sz],vis[sz],id[sz];
struct edge
{
	int f,t,d;
}l[sz];
int directed_mst(int root,int n,int m)
{
	int ans = 0;
	memset(pre,0,sizeof(pre));
	while(12 < 450)
	{
		for(int i = 0 ; i < n ; i ++)
			in[i] = INF;
		for(int i = 1 ; i <= m ; i ++)
		{
			int u = l[i].f;
			int v = l[i].t;
			if(in[v] > l[i].d && u != v)
			{
				in[v] = l[i].d;
				pre[v] = u;
			}
		}
		for(int i = 0 ; i < n ; i ++)
		{
			if(root == i)
				continue;
			if(in[i] == INF)
				return -1;
		}
		int cnt = 0;
		memset(id,-1,sizeof(id));
		memset(vis,-1,sizeof(vis));
		in[root] = 0;
		for(int i = 0 ; i < n ; i ++)
		{
			ans += in[i];
			int v = i;
			while(vis[v] != i && id[v] == -1 && v != root)
			{
				vis[v] = i;
				v = pre[v];
			}
			if(v != root && id[v] == -1)
			{
				for(int u = pre[v] ; u != v ; u = pre[u])
					id[u] = cnt;
				id[v] = cnt ++;
			}
		}
		if(cnt == 0)
			break;
		for(int i = 0 ; i < n ; i ++)
			if(id[i] == -1)
				id[i] = cnt ++;
		for(int i = 1 ; i <= m ; i ++)
		{
			int u = l[i].f;
			int v = l[i].t;
			l[i].f = id[u];
			l[i].t = id[v];
			if(id[u] != id[v])
				l[i].d -= in[v];
			
		}
		n = cnt;
		root = id[root];
	}
	return ans;
}
int main()
{
	int T,n,m;
	scanf("%d",&T);
	for(int K = 1 ; K <= T ; K ++)
	{
		scanf("%d%d",&n,&m);
		for(int i = 1 ; i <= m ; i ++)
		{
			scanf("%d%d%d",&l[i].f,&l[i].t,&l[i].d);
		}
		int ans = directed_mst(0,n,m);
		printf("Case #%d: ",K);
		if(ans == -1)
			puts("Possums!");
		else
			printf("%d\n",ans);
	}
	return 0;
}

