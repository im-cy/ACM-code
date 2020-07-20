#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int num[200010];
int ans;
bool flag;
int main()
{
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d",&num[i]);
	for(int i = 1 ; i <= n ; i ++)
	{
		if(num[i] != num[i+1])
		{
			if(num[i] < num[i+1])
				flag = 1;
			else
				flag = 0;
			int len = 1;
			for(int j = i ; j < n ; j ++)
			{
				if(flag == 1 && num[j] < num[j+1])
				{
					len ++;
					flag ^= 1;
				}
				else if(flag == 0 && num[j] > num[j+1])
				{
					len ++;
					flag ^= 1;
				}
				else
					break;
			}
			ans = max(ans,len);
		}
	}
	printf("%d\n",ans);
	return 0;
}
 
