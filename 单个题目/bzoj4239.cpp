#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;
const int sz = 500010;
priority_queue< P , vector< P >,greater< P> >Q;
P ans[sz];
int tot;
int f[sz],g[sz];
int n,m,q;
struct edge
{
	int f,t,x,y;
}l[sz];
bool cmp(edge a,edge b)
{
	return a.x < b.x;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; i ++)
		scanf("%d%d%d%d",&l[i].f,&l[i].t,&l[i].x,&l[i].y);
	sort(l+1,l+1+m,cmp);
	for(int i = 2 ; i <= n ; i ++)
		f[i] = -1;
	f[1] = 86400000;
	for(int i = 1 ; i <= m ; i ++)
	{
		while(!Q.empty() && Q.top().first <= l[i].x)
		{
			pair < int , int > tp = Q.top();
			Q.pop();
			f[l[tp.second].t] = max(f[l[tp.second].t],g[tp.second]);
		}
		g[i] = min(f[l[i].f],l[i].x);
		Q.push(make_pair(l[i].y,i));
		if(l[i].t == n)
		{
			ans[++tot] = make_pair(l[i].y,g[i]);
		}
	}
	sort(ans+1,ans+tot+1);
	for(int i = 2 ; i <= tot ; i ++)
		ans[i].second = max(ans[i-1].second,ans[i].second);
	scanf("%d",&q);
	for(int i = 1 ; i <= q ; i ++)
	{
		int x;
		scanf("%d",&x);
		int l = 0 , r = tot + 1;
		while(r - l > 1)
		{
			int mid = l + r >> 1;
			if(ans[mid].first <= x)
				l = mid;
			else
				r = mid;
		}
		if(l != 0)
			printf("%d\n",ans[l].second);
		else
			puts("-1");
	}
	return 0;
}

