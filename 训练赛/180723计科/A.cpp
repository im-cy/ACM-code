#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n,c;
ll num[200100];
bool check(ll k)
{
	int now = 1;
	ll dis = 0;
	for(int i = 2 ; i <= n ; i ++)
	{
		if(dis + num[i] - num[i-1] >= k)
		{
			now ++;
			dis = 0;
		}
		else
			dis += num[i] - num[i-1];
	}
	return now >= c;
}
int main()
{
	scanf("%d%d",&n,&c);
	ll l = 0 , r = 0; 
	for(int i = 1 ; i <= n ; i ++)
		scanf("%lld",&num[i]) , r += num[i];
	sort(num+1,num+n+1);
	while(r - l > 1)
	{
		ll mid = (l + r) / 2;
		if(check(mid))
			l = mid;
		else
			r = mid;
	}
	printf("%lld\n",l);
	return 0;
}
 
