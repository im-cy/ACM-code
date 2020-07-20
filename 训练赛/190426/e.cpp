#include<iostream>
#include<cstdio>
using namespace std;
int x[11];
int main()
{
	freopen("explicit.in","r",stdin);
	freopen("explicit.out","w",stdout);
	for(int i = 1 ; i <= 10 ; i ++)
		scanf("%d",&x[i]);
	int ans = 0;
	for(int i = 1 ; i <= 10 ; i ++)
	{
		for(int j = i + 1 ; j <= 10 ; j ++)
		{
			if(i != j)
			{
				ans ^= x[i] | x[j];
				
			}
		}
		
	}
	for(int i = 1 ; i <= 10 ; i ++)
	{
		for(int j = i + 1 ; j <= 10 ; j ++)
		{
			for(int k = j + 1 ; k <= 10 ; k ++)
				if(i != j && j != k && i != k)
				{
					ans ^= x[i] | x[j] | x[k];
				}
		}
	}
	int tot = 0;
	while(ans)
	{
		if(ans & 1)
			tot ++;
		ans >>= 1;
	}
	printf("%d\n",tot%2);
	return 0;
}

