#include<bits/stdc++.h>
using namespace std;
const int sz = 200010;
int hed[2][sz],nxt[2][sz],l[2][sz],d[2][sz];
int link[2][sz],cir[2][sz];
bool vis[2][sz];
int tot[2] = {1,1};
int n1,m1,n2,m2;
int l1,c1,l2,c2;
void build(int x,int f,int t)
{
	l[x][tot[x]] = t;
	nxt[x][tot[x]] = hed[x][f];
	hed[x][f] = tot[x] ++;
}
void dfs(int x,int u,int fa,int &cnt)
{
	cnt ++;
	vis[x][u] = 1;
	for(int i = hed[x][u] ; i ; i = nxt[x][i])
	{
		int t = l[x][i];
		if(t != fa && !vis[x][t])
			dfs(x,t,u,cnt);
	}
}
bool check()
{
//	printf("%d %d %d %d\n",l1,l2,c1,c2);
	if(l1 != l2 || c1 != c2)
		return false;
	sort(link[0]+1,link[0]+l1+1);
	sort(link[1]+1,link[1]+l2+1);
	sort(cir[0]+1,cir[0]+c1+1);
	sort(cir[1]+1,cir[1]+c2+1);
	for(int i = 1 ; i <= l1 ; i ++)
		if(link[0][i] != link[1][i])
			return false;
	for(int i = 1 ; i <= c1 ; i ++)
		if(cir[0][i] != cir[1][i])
			return false;
	return true;
}
void init()
{
	l1 = l2 = c1 = c2 = 0;
	memset(hed,0,sizeof(hed));
	memset(nxt,0,sizeof(nxt));
	memset(l,0,sizeof(l));
	memset(d,0,sizeof(d));
	memset(vis,0,sizeof(vis));
	memset(link,0,sizeof(link));
	memset(cir,0,sizeof(cir));
	tot[0] = 1;
	tot[1] = 1; 
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int K = 1 ; K <= T ; K ++)
	{
		init();
		scanf("%d%d",&n1,&m1);
		for(int i = 1 ; i <= m1 ; i ++)
		{
			int f,t;
			scanf("%d%d",&f,&t);
			build(0,f,t);
			build(0,t,f);
			d[0][f] ++;
			d[0][t] ++;
		}
		scanf("%d%d",&n2,&m2);
		for(int i = 1 ; i <= m2 ; i ++)
		{
			int f,t;
			scanf("%d%d",&f,&t);
			build(1,f,t);
			build(1,t,f);
			d[1][f] ++;
			d[1][t] ++;
		}
		int cnt = 0;
		for(int i = 1 ; i <= n1 ; i ++)
		{
	//		printf("111 %d\n",d[0][i]);
			if(vis[0][i])
				continue;
			if(d[0][i] == 0)
				link[0][++l1] = 1 ,vis[0][i] = 1;
			else if(d[0][i] == 1)
			{
				cnt = 0;
				dfs(0,i,0,cnt);
				link[0][++l1] = cnt;
			}
		}
		for(int i = 1 ; i <= n1 ; i ++)
		{
			if(vis[0][i])
				continue;
			cnt = 0;
			dfs(0,i,-1,cnt);
			cir[0][++c1] = cnt;
		}
		for(int i = 1 ; i <= n2 ; i ++)
		{
	//		printf("222 %d\n",d[1][i]);
			if(vis[1][i])
				continue;
			if(d[1][i] == 0)
				link[1][++l2] = 1 , vis[1][i] = 1;
			else if(d[1][i] == 1)
			{
				cnt = 0;
				dfs(1,i,0,cnt);
				link[1][++l2] = cnt;
			}
		}
		for(int i = 1 ; i <= n2 ; i ++)
		{
			if(vis[1][i])
				continue;
			cnt = 0;
			dfs(1,i,0,cnt);
			cir[1][++c2] = cnt;
		}
		bool ans = check();
		printf("Case #%d: ",K);
		if(ans)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

