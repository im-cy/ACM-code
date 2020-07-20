#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k;
int num[200100];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; i ++)
	{
		char ins = getchar();
		while(ins != 'a' && ins != 'b')
			ins = getchar();
		if(ins == 'a')
			num[i] = 0;
		else
			num[i] = 1;
	}
	int ans = 1;
	int now = 0;
	int l = 1;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(num[i] != 1)
			now ++;
		while(now > k)
		{
			if(num[l] != 1)
				now --;
			l ++;
		}
		ans = max(ans,i - l + 1);
	}
	now = 0;
	l = 1;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(num[i] == 1)
			now ++;
		while(now > k)
		{
			if(num[l] == 1)
				now --;
			l ++;
		}
		ans = max(ans,i - l + 1);
	}
	printf("%d\n",ans);
	return 0;
}



