#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 200010;
ll num[sz];
ll sum[sz];
ll ans[sz];
int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i = 1 ; i <= n ; i ++)
			scanf("%I64d",&num[i]);
		memset(ans,0,sizeof(ans));
		for(int i = 1 ; i <= n ; i ++)
		{
			sum[i] = sum[i-1] + num[i];
		}
		int last = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			if((sum[i] - sum[ans[ans[0]]]) % 2)
			{
				ans[++ans[0]] = i;
			}
		}
		if(ans[0] < k || (ans[0] - k)%2)
			puts("NO");
		else
		{
			puts("YES");
			for(int i = 1 ; i < k ; i ++)
			{
				printf("%d ",ans[i]);
			}
			printf("%d\n",n);
		}
	}
	return 0;
}

