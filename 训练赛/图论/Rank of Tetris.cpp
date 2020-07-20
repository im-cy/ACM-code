#include<bits/stdc++.h>
using namespace std;
const int sz = 200010;
int hed[sz],nxt[sz],l[sz];
int rd[sz];
int fa[sz];
int tot = 1;
struct edge
{
	int f,t;
	char d;
}in[sz];
queue < int > q;
void build(int f,int t)
{
	l[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
int find(int x)
{
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
bool vis[sz];
int n,m;
bool cir = 0;
bool ans = 1;
void top_sort()
{
	for(int i = 1 ; i <= n ; i ++)
	{
		if(find(i) == i)
		{
			if(!rd[i])
			{
				q.push(i);
			}
		}
	}
	while(!q.empty())
	{
		if(q.size() > 1)
			ans = 0;
		int f = q.front();
		q.pop();
		vis[f] = 1;
		for(int i = hed[f] ; i ; i = nxt[i])
		{
			int t = find(l[i]);
			rd[t] --;
			if(!rd[t])
			{
				q.push(t);
			}
		}
	}
}
void init()
{
	for(int i = 0 ; i <= n + 5 ; i ++)
		fa[i] = i , hed[i] = -1 ,rd[i] = 0 , vis[i] = 0;
	while(!q.empty())
		q.pop();
	cir = 0;
	ans = 1;
	tot = 1;
} 
int main()
{
	while(scanf("%d%d",&n,&m) != EOF)
	{
		init();
		for(int i = 1 ; i <= m ; i ++)
		{
			char ins;
			scanf("%d",&in[i].f);
			ins = getchar();
			while(ins != '>' && ins != '=' && ins != '<')
				ins = getchar();
			in[i].d = ins;
			scanf("%d",&in[i].t);
			in[i].f ++;
			in[i].t ++;
			int ff = find(in[i].f) , tt = find(in[i].t);
			if(ins == '=')
				fa[ff] = tt;
		}
		for(int i = 1 ; i <= m ; i ++)
		{
			int ff = find(in[i].f) , tt = find(in[i].t);
			if(in[i].d == '<')
				build(ff,tt),rd[tt] ++;
			else if(in[i].d == '>')
				build(tt,ff),rd[ff] ++;
		}
		top_sort();
		for(int i = 1 ; i <= n ; i ++)
        {
            if(!vis[i] && find(i) == i)
                cir = 1;
        }
		if(cir)
			puts("CONFLICT");
		else if(!ans)
			puts("UNCERTAIN");
		else
			puts("OK");
	}
	//
	return 0;
}
