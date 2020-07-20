#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int sz = 200010;
int n,m;
ll a[sz],b[sz];
int c[sz];
bool d[sz];
bool check()
{
	int i = 1 , j = 1;
	int tot = 0;
	for( ; i <= m ; i ++)
	{
		for( ; j <= n ; j ++)
		{
			if(b[i] <= a[j])
			{
				c[i] = j;
				j ++;
				tot ++;
				break;
			}
		}
	}
	if(tot == m)
		return true;
	return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	int k = 1;
	while(T --)
	{
		memset(c,0,sizeof(c));
		scanf("%d%d",&n,&m);
		for(int i = 1 ; i <= n ; i ++)
			scanf("%lld",&a[i]);
		for(int i = 1 ; i <= m ; i ++)
			scanf("%lld",&b[i]);
		for(int i = 1 ; i <= m ; i ++)
			scanf("%d",&d[i]);
		
		sort(a+1,a+n+1);
		sort(b+1,b+m+1);
		printf("Case %d: ",k ++);
		if(check())
		{
			ll ans = 0;
			for(int i = 1 ; i <= n ; i ++)
				ans += a[i];
			for(int i = 1 ; i <= m ; i ++)
				if(!d[i])
					ans -= b[i];
			for(int i = 1 ; i <= m ; i ++)
				if(d[i])
				{
					ans -= a[c[i]];
				}
			printf("%lld\n",ans);
		}
		else
		{
			ll ans = 0;
			int bb = 1 , aa = n;
			for( ; bb <= m ; bb ++)
			{
				if(!d[bb])
					for( ; aa >= 1 ; aa --)
					{
						if(b[bb] <= a[aa])
						{
							ans += a[aa] - b[bb];
							aa --;
							break;
						}
					}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
 
