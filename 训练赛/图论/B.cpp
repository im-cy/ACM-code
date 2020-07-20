#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int sz = 20010;
int f[sz];
int find(int x)
{
	if(f[x] == x)
		return x;
	return f[x] = find(f[x]);
}
struct dc
{
	int f,t;
	double d;
}edge[sz];
bool cmp(dc a,dc b)
{
	return a.d < b.d;
}
struct point
{
	int x,y;
}pos[sz];
double calc(point a,point b)
{
	double x = a.x - b.x;
	double y = a.y - b.y;
	return sqrt(x * x + y * y);
}
int n,m;
int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		m = 0;
		memset(edge,0,sizeof(edge));
		memset(pos,0,sizeof(pos));
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i ++)
			scanf("%d%d",&pos[i].x,&pos[i].y);
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = i + 1 ; j <= n ; j ++)
			{
				double len = calc(pos[i],pos[j]);
				if(len >= 10 && len <= 1000)
				{
					m ++;
					edge[m].f = i , edge[m].t = j , edge[m].d = len;
				}
			}
		}
		for(int i = 1 ; i <= n ; i ++)
			f[i] = i;
		sort(edge+1,edge+m+1,cmp);
		int now = n - 1;
		double ans = 0;
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
			puts("oh!");
		else
			printf("%.1lf\n",ans*100);
	}
	return 0;
}

