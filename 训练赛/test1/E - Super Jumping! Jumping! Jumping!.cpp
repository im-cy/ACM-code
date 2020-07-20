#include<iostream>
#include<cstdio>
using namespace std;
int n;
int num[2010];
int f[2010];
int main()
{
	while(scanf("%d",&n) && n)
	{
		for(int i = 1 ; i <= n ; i ++)
			scanf("%d",&num[i]) , f[i] = num[i];
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j < i ; j ++)
			{
				if(num[j] < num[i])
				{
					f[i] = max(f[i],f[j]+num[i]);
					
				}
			}
		}
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++)
			ans = max(ans,f[i]);
		printf("%d\n",ans);
	}
	return 0;
}

