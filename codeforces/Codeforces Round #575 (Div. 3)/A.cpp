#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll num[4];
int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		for(int i = 1 ; i <= 3 ; i ++)
			scanf("%I64d",&num[i]);
		sort(num+1,num+4);
		ll a = num[1] , b = num[2] ,c = num[3];
		if(c >= b - a)
		{
			ll tmp = b - a;
			a += tmp;
			c -= tmp;
			a += c/2;
			printf("%I64d\n",a);
		}
		else
		{
			printf("%I64d\n",a+c);
		}
	}
	return 0;
}

