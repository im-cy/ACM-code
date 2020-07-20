#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll a,b;
int main()
{
	scanf("%lld%lld",&a,&b);
	ll n = min(a,b);
	ll ans = 1;
	for(int i = 1 ; i <= n ; i ++)
		ans *= i;
	printf("%lld\n",ans);
	return 0;
}
