#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll l,r;
ll ksm(ll x,ll p)
{
	if(p == 0)
		return 1;
	if(p == 1)
		return x;
	if(p == 2)
		return x * x;
	ll temp = ksm(x,p/2);
	if(p % 2)
		return temp * temp * x;
	if(!(p%2))
		return temp * temp;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		cin >> l >> r;
		if(l == r)
		{
			cout << l << endl;
			continue;
		}
		ll temp = l;
		int len_l = 0;
		while(temp)
		{
			len_l ++;
			temp >>= 1;
		}
		temp = r;
		int len_r = 0;
		while(temp)
		{
			len_r ++;
			temp >>= 1;
		}
		ll x = r;
		ll y = 0;
		ll k = 0;
		while(ksm(2,k) <= r)
			k ++;
		k --;
		if(len_l != len_r)
		{
			y = ksm(2,k) - 1;
		}
		else
		{
			int x = 0;
			for(x = len_l - 1 ; x >= 0 ; x --)
			{
				if(((r >> x) & 1) && !((l >> x) & 1))
					break;
			}
			y = ksm(2,k) + ksm(2,x) - 1;
			
		}
		cout << (x | y) << endl;
	}
	
	return 0;
}

