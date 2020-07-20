#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 2001;
int f[sz];
int find(int x)
{
	if(f[x] == x)
		return x;
	return f[x] = find(f[x]);
}
struct dc
{
	int f,t,d;
}edge[sz];
bool cmp(dc a,dc b)
{
	return a.d < b.d;
}
int n,m;
int main()
{
	while(scanf("%d%d",&m,&n) && m)
	{
		for(int i = 1 ; i <= n ; i ++)
			f[i] = i;
		for(int i = 1 ; i <= m ; i ++)
			scanf("%d%d%d",&edge[i].f,&edge[i].t,&edge[i].d);
		sort(edge+1,edge+m+1,cmp);
		int now = n - 1;
		int ans = 0;
		for(int i = 1 ; i <= m ; i ++)
		{
			int ff = find(edge[i].f);
			int tt = find(edge[i].t);
			if(ff != tt)
			{
				ans += edge[i].d;
				now --;
				f[ff] = tt;
			}
		}
		if(now)
			puts("?");
		else
			printf("%d\n",ans);
	}
	
	return 0;
}

