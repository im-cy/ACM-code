#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
#define INF 0x3f3f3f3f
int a[205],b[205];
int dp[205][205];
int main()
{
	int t , cas = 0 , n;
	scanf("%d",&t);
	while(t --)
	{
		long long ans = 0;
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i ++)
		{
			scanf("%d",&a[i]);
			ans += a[i];
		}
		for(int i = 1 ; i <= n ; i ++)
			scanf("%d",&b[i]);
		n ++;
		b[n] = 0;
		memset(dp,INF,sizeof(dp));
		for(int i = 0 ; i <= n ; i ++)
			dp[i][i+1] = 0 , dp[i][i] = 0;
		
		for(int len = 2 ; len <= n ; len ++)
		{
			for(int i = 0 ; i + len <= n ; i ++)
			{
				int j = i + len;
				for(int k = i ; k <= j ; k ++)
				{
					dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]+b[i] + b[j]);
				}
			}
		}
		printf("Case #%d: %lld\n",++ cas,ans + dp[0][n]);
	}
	return 0;
}

