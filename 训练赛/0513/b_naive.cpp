#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[1010];
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
		int temp_m = m;
		for(int i = 1 ; i <= temp_m ; i ++)
		{
			while(num[i] > 1)
			{
				num[i] --;
				m ++;
				v[m] = v[i];
				w[m] = w[i];
			}
		}
		for(int i = 1 ; i <= m ; i ++)
			for(int j = n ; j >= v[i] ; j --)
				dp[j] = max(dp[j],dp[j - v[i]] + w[i]);
		printf("%d\n",dp[n]);
	}
	return 0;
}
