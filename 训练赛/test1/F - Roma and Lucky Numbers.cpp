#include<iostream>
#include<cstdio>
using namespace std;
int n,k,ans;
int num[201];
int main()
{
	scanf("%d%d",&n,&k);
	ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d",&num[i]);
	for(int i = 1 ; i <= n ; i ++)
	{
		int temp = num[i];
		int now_len = 0;
		while(temp)
		{
			if(temp % 10 == 4 || temp % 10 == 7)
				now_len ++;
			temp /= 10;
		}
		if(now_len <= k)
			ans ++;
	}
	printf("%d\n",ans);
	return 0;
}

