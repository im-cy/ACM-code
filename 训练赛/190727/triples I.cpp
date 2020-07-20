#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool T[101];
ll gety(ll p,ll x)
{
	ll y = 0;
	ll tp = p,tx = x;
	ll pos = 0;
	ll now = 1;
	while(now < tp)
	{
		if((tp & now) == (tx & now))
		{
			if((tx & now) >= 1)
				T[pos] = 1;
		}
		else
		{
			if((tp & now) >= 1)
				y |= now;
			else
				T[pos] = 1;
		}
		pos ++;
		now <<= 1ll;
	}
	if(y % 3 == 0)
		return y;
	if(y % 3 == 2)
	{
		for(ll i = 0 ; i <= 60 ; i ++)
			if(T[i] && ((i%2) == 0))
			{
				y |= (1ll << i);
				return y;
			}
		for(ll i = 0 ; i <= 60 ; i ++)
		{
			if((i%2) == 1)
			{
				for(ll j = 0 ; j <= 60 ; j ++)
				{
					if((j%2) == 1 && i != j)
					{
						if(T[i] && T[j])
						{
							y |= (1ll << i);
							y |= (1ll << j);
							return y;
						}
						
					}
				}
			}
		}
	}
	if(y % 3 == 1)
	{
		for(ll i = 0 ; i <= 60 ; i ++)
			if(T[i] && ((i%2) == 1))
			{
				y |= (1ll << i);
				return y;
			}
		for(ll i = 0 ; i <= 60 ; i ++)
		{
			if((i%2) == 0)
			{
				for(ll j = 0 ; j <= 60 ; j ++)
				{
					if((j%2) == 0 && i != j)
					{
						if(T[i] && T[j])
						{
							y |= (1ll << i);
							y |= (1ll << j);
							return y;
						}
						
					}
				}
				
			}
		}
	}
	return y;
}
int main()
{
	ll p,x;
	cin >> p >> x;
	cout << gety(p,x) << endl;
	return 0;
}

