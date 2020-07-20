#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int sz = 200010;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int read()
{
	int x = 0;
	int f = 1;
	char in = getchar();
	while(in < '0' || in > '9')
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
ll num[sz];
ll n,m,k;
int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		scanf("%I64d%I64d%I64d",&n,&m,&k);
		ll ans = 0;
		for(int i = 1 ; i <= n ; i ++)
			scanf("%I64d",&num[i]);
		bool flag = 1;
		for(int i = 2 ; i <= n ; i ++)
		{
			ll x = max(num[i] - k,0ll);
			ans -= num[i-1] - x;
			if(ans > m)
			{
				flag = 0;
				break;
			}
		}
		if(!flag)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}

