#include<bits/stdc++.h>
using namespace std;
bool dp[2010];
int n;
int main()
{
	for(int i = 1 ; i <= 1000 ; i ++)
	{
		for(int j = 1 ; i - j >= 0 ; j <<= 1)
		{
			if(!dp[i-j])
				dp[i] = 1;
		}
	}
	while(scanf("%d",&n) != EOF)
	{
		if(dp[n])
			puts("Kiki");
		else
			puts("Cici");
	}
	return 0;
}
 
