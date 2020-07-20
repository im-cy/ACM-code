#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 2001000;
ll num[sz];

int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		int n;
		scanf("%d",&n);
		ll cnt = 0;
		ll a = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			scanf("%lld",&num[i]);
			num[i] %= 4;
			cnt += num[i];
			if(i % 2)
				a += num[i];
		}
		if(a % 4 == 1 || a % 4 == 3)
		{
			puts("Bob");
			
		}
		else
		{
			if(cnt % 4)
				puts("Bob");
			else
				puts("Mike");
		}
		
	}
	return 0;
}

