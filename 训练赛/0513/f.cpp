#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;
int num[10010];
int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		int n;
		scanf("%d",&n);
		memset(num,0,sizeof(num));
		for(int i = 1 ; i <= n ; i ++)
			scanf("%d",&num[i]);	
		if(n % 2)
			num[++n] = 0;
		sort(num+1,num+n+1);
		int ans = 0;
		for(int i = 1 ; i < n ; i += 2)
			ans ^=(num[i+1] - num[i] - 1);
		if(ans)
			puts("Georgia will win");
		else
			puts("Bob will win");
	}
	return 0;
}


