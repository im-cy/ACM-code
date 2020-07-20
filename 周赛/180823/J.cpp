#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll f(ll x, ll y)
{
	ll c = 0;
	while(y > 0)
	{
		c ++;
		ll t = x % y;
		x = y;
		y = t;
	}
	return c * x * x;
}
ll n,m,p;
int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		ll ans = 0;
		cin >> n >> m >> p;
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= m ; j ++)
			{
				printf("# i %d j %d f(i,j) %lld\n",i,j,f(i,j)%p);
			}
		}
		
	}
	return 0;
}

