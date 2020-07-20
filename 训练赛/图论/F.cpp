#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define ll int
using namespace std;
const int sz_n = 100010;
const int sz_m = 1000100;
int hed[sz_n],nxt[sz_m],fa[sz_n],dist[sz_n];
queue < int > q;
struct dc
{
	int t,d;
}l[sz_m];
int tot = 1;
bool is_circle,use[sz_n];
int n,m;
int find(int x)
{
	int r = x;
    while(r != fa[r])
        r = fa[r];
    int i = x , j;
    while(i != r)
    {
        j = fa[i];
        fa[i] = r;
        i = j;
    }
    return r;
}
void build(int f,int t,int d)
{
	l[tot].t = t;
	l[tot].d = d;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
void init()
{
	for(int i = 1 ; i <= n ; i ++)
		fa[i] = i;
	memset(dist,0,sizeof(dist));
	memset(use,0,sizeof(use));
	memset(hed,-1,sizeof(hed));
	memset(nxt,0,sizeof(nxt));
	memset(l,0,sizeof(l));
	tot = 1;
	is_circle = 0;
	return ;
}
void bfs(int u)
{
	q.push(u);
	use[u] = 1;
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		for(int i = hed[f] ; i != -1 ; i = nxt[i])
		
		{
			int t = l[i].t;
			if(!use[t])
			{
				dist[t] = dist[f] + l[i].d;
				use[t] = 1;
				q.push(t);
			}
		}
	}
}
int main()
{
	while(scanf("%d%d",&n,&m) != EOF)
	{
		init();
		for(int i = 1 ; i <= m ; i ++)
		{
			int f,t,d;
			scanf("%d%d%d",&f,&t,&d);
			build(f,t,d);
			build(t,f,d);
			if(find(f) == find(t))
				is_circle = 1;
			else
				fa[find(f)] = find(t);
		}
		if(is_circle)
			puts("YES");
		else
		{
			int final_ans = -1;
			for(int i = 1 ; i <= n ; i ++)
			{
				if(!use[i])
				{
					int ans = 0 , p = 0;
					bfs(i);
					for(int j = 1 ; j <= n ; j ++)
						if(dist[j] > ans)
							ans = dist[j] , p = j;
					dist[p] = 0;
					bfs(p);
					for(int i = 1 ; i <= n ; i ++)
						ans = max(ans,dist[i]);
					final_ans = max(ans,final_ans);
				}
				
			}
			printf("%d\n",final_ans);
		}
	}
	
	return 0;
}

