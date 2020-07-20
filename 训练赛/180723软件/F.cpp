#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll n,k;
ll coin[500010];
bool check_min(ll mid)
{
	ll now = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(coin[i] < mid)
			now += mid - coin[i];
		if(now > k)
			return false;
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		if(coin[i] > mid)
			now -= coin[i] - mid;
	}
	if(now > 0)
		return false;
	return true;
}
bool check_max(ll mid)
{
	ll now = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(coin[i] > mid)
			now += coin[i] - mid;
		if(now > k)
			return false;
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		if(coin[i] < mid)
			now -= mid - coin[i];
	}
	if(now > 0)
		return false;
	return true;
}
int main()
{
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		scanf("%I64d",&coin[i]);
	ll l = -1 , r = 1e9 + 1;
	while(r - l > 1)
	{
		ll mid = l + r >> 1;
		if(check_min(mid))
			l = mid;
		else
			r = mid;
	}
	ll minn = l;
	l = -1 , r = 1e9 + 1;
	while(r - l > 1)
	{
		ll mid = l + r >> 1;
		if(check_max(mid))
			r = mid;
		else
			l = mid;
	}
	ll maxn = l;
	if(!check_max(maxn))
		maxn ++;
	if(!check_min(minn))
		minn ++;
	printf("%I64d\n",maxn-minn);
	return 0;
}

