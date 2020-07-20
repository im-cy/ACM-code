#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
struct edge
{
	int f,t,d,;
}l[20100];
bool cmp(edge a,edge b)
{
	return a.d < b.d;
}
int f[10010];
int find(int x)
{
	if(f[x] == x)
		return x;
	return f[x] = find(f[x]);
}
int maxn = 0 , minn = 214748364;
void init()
{
	maxn = 0 , minn = 214748364;
	memset(l,0,sizeof(l));
	memset(f,0,sizeof(f));
}
bool check(int k)
{
	maxn = 0 , minn = 214748364;
	for(int i = 1 ; i <= n ; i ++)
		f[i] = i;
	int tot = n - 1;
	for(int i = k ; i <= m ; i ++)
	{
		int ff = find(l[i].f);
		int tt = find(l[i].t);
		if(ff != tt)
		{
			f[ff] = tt;
			maxn = max(maxn,l[i].d);
			minn = min(minn,l[i].d);
			tot --;
		}
	}
	if(tot <= 0)
		return true;
	return false;
}
int main()
{
	while(scanf("%d %d",&n,&m))
	{
		if(!n && !m)
			break;
		for(int i = 1 ; i <= m ; i ++)
			scanf("%d%d%d",&l[i].f,&l[i].t,&l[i].d);
		sort(l+1,l+1+m,cmp);
		int ans = 214748364;
		for(int i = 1 ; i <= m ; i ++)
			if(check(i))
			{
				ans = min(ans,maxn - minn);
				
			}
		if(ans == 214748364)
			puts("-1");
		else
			printf("%d\n",ans);
	}
	return 0;
}

