#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 2001000;
int dp[sz];
int w[10] = {6,2,5,5,4,5,6,3,7,6};
int main()
{
	freopen("auxiliary.in","r",stdin);
	freopen("auxiliary.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i = 0 ; i <= 9 ; i ++)
		for(int j = w[i] ; j <= n ; j ++)
			if(j == w[i] || dp[j-w[i]])
				dp[j] = max(dp[j-w[i]] + i,dp[j]);
	cout << dp[n] << endl;
	return 0;
}

 
