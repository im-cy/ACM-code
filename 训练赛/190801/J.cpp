#include<bits/stdc++.h>
using namespace std;
const int sz = 400010;
vector<int>mp[sz];
int hed[sz],nxt[sz],l[sz];
int dep[sz],siz[sz],wt[sz];
int tot = 1;
int root=0;
int n,Q;
void build(int f,int t)
{
	l[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
void dfs1(int u,int fa)
{
	siz[u]=1;
	wt[u]=0;
	for(int i = hed[u] ; i ; i = nxt[i])
	{
		int v = l[i];
		if(v==fa)continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		wt[u]=max(wt[u],siz[v]);
	}
	wt[u]=max(wt[u],n-siz[u]);
	if(wt[root]>wt[u])root=u;
}
void dfs2(int u,int fa,int deep)
{
	dep[u] = deep;
	mp[deep].push_back(u);
	for(int i = hed[u] ; i ; i = nxt[i])
	{
		int v = l[i];
		if(v==fa)
			continue;
		dfs2(v,u,deep+1);
	}
}
bool check(int x,int y,int z)
{
	if(x == y && y == z)
		return mp[x].size() >= 3;
	if(x == y)
	{
		if(mp[x].size() < 2 || !mp[z].size())
			return false;
		return true;
	}
	if(x == z)
	{
		if(mp[x].size() < 2 || !mp[y].size())
			return false;
		return true;
	}
	if(y == z)
	{
		if(mp[y].size() < 2 || !mp[x].size())
			return false;
		return true;
	}
	if(!mp[x].size() || !mp[y].size() || !mp[z].size())
		return false;
	return true;
}
int pos,dist;

int main()
{
	wt[0]=1000000000;
	root=0;
	scanf("%d",&n);
	for(int i = 1 ; i < n ; i ++)
	{
		int f,t;
		scanf("%d%d",&f,&t);
		f ++; t ++;
		build(f,t);
		build(t,f);
	}
	dfs1(1,0);
	dfs2(root,0,0);
//	for(int i = 1 ; i <= n ; i ++)
//		printf("%d ",dep[i]);
	scanf("%d",&Q);
	for(int i = 1 ; i <= Q ; i ++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int dx = (a+b-c);
		int dy = (a-b+c);
		int dz = (c-a+b);
		if(dx%2 || dy%2 || dz%2 || dx < 0 || dy < 0 || dz < 0)
		{
			puts("-1");
			continue;
		}
		dx /= 2 , dy /= 2 , dz /= 2;
//		printf("dx %d dy %d dz %d\n",dx,dy,dz);
		if(check(dx,dy,dz))
		{
			int tx = mp[dx].back();
			printf("%d ",mp[dx].back()-1);
			mp[dx].pop_back();
			int ty = mp[dy].back();
			printf("%d ",mp[dy].back()-1);
			mp[dy].pop_back();
			printf("%d\n",mp[dz].back()-1);
			mp[dx].push_back(tx);
			mp[dy].push_back(ty);
		}/*
		else if(check(dx,dz,dy))
			printf("%d %d %d\n",mp[dx]-1,mp[dz]-1,mp[dy]-1);
		else if(check(dy,dx,dz))
			printf("%d %d %d\n",mp[dy]-1,mp[dx]-1,mp[dz]-1);
		else if(check(dy,dz,dx))
			printf("%d %d %d\n",mp[dy]-1,mp[dz]-1,mp[dx]-1);
		else if(check(dz,dx,dy))
			printf("%d %d %d\n",mp[dz]-1,mp[dx]-1,mp[dy]-1);
		else if(check(dz,dy,dx))
			printf("%d %d %d\n",mp[dz]-1,mp[dy]-1,mp[dx]-1);*/
		else
			puts("-1");
	}
	return 0;
}

