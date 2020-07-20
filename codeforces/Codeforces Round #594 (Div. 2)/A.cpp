#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll x = 0 , f = 1;
	char in = getchar();
	while(in < '0'  || in > '9')
	{
		if(in == '-')
			f = -1;
		in = getchar();
	}
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in - '0';
		in = getchar();
	}
	return x * f;
}
const int sz = 200010;
ll p[sz],q[sz];
int main()
{
	int T = read();
	while(T --)
	{
		int n = read();
		ll x = 0 , y = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			p[i] = read();
			if((p[i] % 2) == 0)
				x ++;
			else
				y ++;
		}
		int m = read();
		ll ans = 0;
		for(int i = 1 ; i <= m ; i ++)
		{
			q[i] = read();
			if((q[i] % 2) == 0)
				ans += x;
			else
				ans += y;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
