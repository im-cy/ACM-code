#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 200010;
ll gcd(ll a,ll b)
{
	if(b == 0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int n;
	scanf("%d",&n);
	ll ans;
	scanf("%I64d",&ans);
	for(int i = 2 ; i <= n ; i ++)
	{
		ll tmp;
		scanf("%I64d",&tmp);
		ans = gcd(ans,tmp);
	}
	ll num = 0;
	for(ll i = 1 ; i * i <= ans ; i ++)
	{
		if(ans % i == 0)
		{
			if(i * i != ans)
				num += 2;
			else
				num ++;
		}
		
	}
	printf("%I64d\n",num);
	return 0;
}

