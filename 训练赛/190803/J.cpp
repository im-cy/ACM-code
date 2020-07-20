#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 1050;
ll c[sz][sz];
ll g[sz][sz];
ll d[sz];
ll sum[sz],sumg[sz];
int n,m;
void init()
{
	memset(c,0,sizeof(c));
	memset(g,0,sizeof(g));
	memset(d,0,sizeof(d));
	memset(sum,0,sizeof(sum));
	memset(sumg,0,sizeof(sumg));
}
int main()
{
	int T;
	scanf("%d",&T);
	int cas = 0;
	while(T --)
	{
		init();
		scanf("%lld%lld",&n,&m);
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 1 ; j <= m ; j ++)
				scanf("%lld",&c[i][j]);
		for(int i = 1 ; i <= m ; i ++)
			scanf("%lld",&d[i]);
		for(int i = 1 ; i <= n ; i ++)
		{
			ll now = 0;
			for(int j = m ; j >= 1 ; j --)
			{
				if(now + c[i][j] <= 0)
				{
					now += c[i][j];
					g[i][j] = -now;
				}
				else if(now < 0)
					now = 0 , g[i][j] = -now;
				else
					now = 0 , g[i][j] = -1;
			}
		}
		for(int i = 1 ; i <= m ; i ++)
		{
			for(int j = 1 ; j <= n ; j ++)
			{
				sum[i] += c[j][i];
				if(g[j][i] > 0)
					sumg[i] += g[j][i];
			}
		}
		ll ans = 0;
		ll tot = 0;
		for(int i = 0 ; i <= m ; i ++)
		{
			tot += d[i] - sum[i];
			ans = max(ans,tot+sumg[i+1]);
		}
		
		
		printf("Case #%d: %lld\n",++cas,ans);
	}
	
	return 0;
}
/*
999
3 3
1 3 9
1 1 -5
1 3 9
3 4 5

*/
