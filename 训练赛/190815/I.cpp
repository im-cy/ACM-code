#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;


int main()
{
	for(ll n = 1 ; n <= 20 ; n += 2)
	{
		for(ll m = 1 ; m <= 20 ; m += 2)
		{
			ll ans = 0;
			for(int i = 1 ; i <= n ; i ++)
			{
				ans += ((i*m)&m) % mod;
			}
			printf("%lld ",ans);
		}
		puts("");
	}
	
	return 0;
}

