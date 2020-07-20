#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 200100;
struct dc
{
	int f,t,d;
}l[sz];
int tot;
int n;
bool cmp(dc a,dc b)
{
	return a.d < b.d;
}
int f[sz];
int find(int x)
{
	if(f[x] == x)
		return x;
	return f[x] = find(f[x]);
}
void init()
{
	memset(l,0,sizeof(l));
	for(int i = 1 ; i <= n ; i ++)
		f[i] = i;
	tot = 0;
	return ;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		scanf("%d",&n);
		init();
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= n ; j ++)
			{
				int d;
				tot ++;
				scanf("%d",&d);
				l[tot].f = i;
				l[tot].t = j;
				l[tot].d = d;
			}
		}
		sort(l+1,l+1+tot,cmp);
		int is_connect = n - 1;
		int ans = 0;
		for(int i = 1 ; i <= tot ; i ++)
		{
			int ff = find(l[i].f);
			int tt = find(l[i].t);
			if(ff != tt)
			{
				f[ff] = tt;
				is_connect --;
				ans = l[i].d;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


