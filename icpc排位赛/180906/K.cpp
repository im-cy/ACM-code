#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n;
ll dis[241][241];
int lis[241];
int main()
{
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%d",&lis[i]);
		lis[i] ++;
	}
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			scanf("%lld",&dis[i][j]);
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			if(dis[i][j] == -1)
				dis[i][j] = 2147483647111ll;
	for(int k = 1 ; k <= n ; k ++)
	{
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= n ; j ++)
			{
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	ll ans = 0;
	n ++;
	lis[n] = lis[1];
	for(int i = 2 ; i <= n ; i ++)
		ans += dis[lis[i-1]][lis[i]];
	if(ans >= 2147483647111ll)
		puts("-1");
	else
		printf("%lld\n",ans);
	return 0;
}
 
