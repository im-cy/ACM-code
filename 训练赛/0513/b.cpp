#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[1010][1010];
int v[1010];
int w[1010];
int num[1010];
int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		memset(dp,0,sizeof(dp));
		memset(v,0,sizeof(v));
		memset(w,0,sizeof(w));
		memset(num,0,sizeof(num));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i = 1 ; i <= m ; i ++)
			scanf("%d%d%d",&v[i],&w[i],&num[i]);
		for(int i = 1 ; i <= m ; i ++)
		{
			for(int k = 1 ; k <= num[i] ; k ++)
			{
				for(int j = k * v[i] ; j <= n ; j ++)
					dp[i][j] = max(dp[i][j],dp[i-1][j - k * v[i]] + k * w[i]);
			}
		}
		printf("%d\n",dp[m][n]);
	}
	return 0;
}

