#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 200010;
int n,k;
int num[sz];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d",&num[i]);
	sort(num+1,num+n+1);
	int now = 1;
	int sub = 0;
	for(int i = 1 ; i <= k ; i ++)
	{
		while(num[now] - sub <= 0 && now <= n)
			now ++;
		if(now > n)
			puts("0");
		else
		{
			num[now] -= sub;
			printf("%d\n",max(num[now],0));
			sub += num[now];
			num[now] = 0;
			if(num[now] < 0)
				num[now] = 0;
		}
	}
	return 0;
}
