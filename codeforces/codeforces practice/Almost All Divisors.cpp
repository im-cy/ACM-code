#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#define ll long long
using namespace std;
const int sz = 200100;
ll num[sz];
unordered_map < ll,bool > T;
int n;
bool check(ll x)
{
	int tot = 0;
	for(ll i = 2 ; i * i <= x ; i ++)
	{
		if(x % i == 0 && (!T[i] || !T[x/i]))
			return false;
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		if(x % num[i])
			return false;
	}
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		T.clear();
		for(int i = 1 ; i <= n ; i ++)
			scanf("%lld",&num[i]) , T[num[i]] = 1;
		sort(num+1,num+n+1);
		ll ans = num[1] * num[n];
		if(check(ans))
			printf("%lld\n",ans);
		else
			puts("-1");
	}
	return 0;
}
 
