#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double dp[201];
double num[201];
int main()
{
	int t;
	int k = 0;
	scanf("%d",&t);
	while(t --)
	{
		k ++;
		memset(num,0,sizeof(num));
		memset(dp,0,sizeof(dp));
		int n;
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i ++)
		{
			scanf("%lf",&num[i]);
		}
		dp[n] = num[n];
		for(int i = n - 1 ; i >= 1 ; i --)
		{
			int l = min (n - i,6);
			for(int j = i + 1 ; j <= i + l ; j ++)
			{
				dp[i] += dp[j]/((double)l);
			}
			dp[i] += num[i];
		}
		printf("Case %d: %lf\n",k,dp[1]);
	}
	return 0;
}
/*
3
1
101
2
10 3
3
3 6 9
*/
