#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int sz = 200010;
const ll mod = 998244353;
ll a[sz],b[sz];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%I64d",&a[i]);
		a[i] = (ll)(n-i+1)*i*a[i];
		
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%I64d",&b[i]);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1,cmp);
	ll ans = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		ans += (a[i]%mod) * (b[i]%mod);
		ans %= mod;
	}
	printf("%I64d\n",ans);
	return 0;
}
//(n-i+1)*i
 
