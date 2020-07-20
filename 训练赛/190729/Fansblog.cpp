#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
/*
(p-1)! / ((q+1)(q+2)...(p-1))
*/
ll mul(ll a,ll b,ll mod){
	return (a*b-(ll)((long double)a/mod*b)*mod+mod)%mod;
}
ll p;
ll pow_mod(ll a,ll i,ll n)
{
	if(i == 0)
		return 1 % n;
	ll temp = pow_mod(a,i>>1,n);
	temp = mul(temp,temp,n);
	if(i & 1)
		temp = (ll)mul(temp,a,n);
	return temp;
}

bool test(ll n,ll a,ll d)
{
	if(n == 2)
		return true;
	if(n == a)
		return true;
	if((n&1) == 0)
		return false;
	while(!(d&1))
		d = d >> 1;
	ll t = pow_mod(a,d,n);
	while((d!=n-1)&&(t!=1)&&(t!=n-1))
	{
		t = (ll)mul(t,t,n);
		d = d << 1;
	}
	return (t == n-1 || (d&1) == 1);
}
bool isPrime(ll n)
{
	if(n < 2)
		return false;
	ll a[] = {2, 3, 5,23,41,163,179, 233,331};
	for(int i = 0 ; i <= 8 ; i ++)
		if(!test(n,a[i],n-1))
			return false;
	return true;
/*	for(int i = 2 ; i * i <= n ; i ++)
		if(!(n % i))
			return false;
	return true;*/
}
ll inverse(ll a)
{
	
	return pow_mod(a,p-2,p);
	// if(extgcd(a,M,x,y)==1) return (M+x%M)%M;
	// else return -1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		scanf("%lld",&p);
		ll q = p - 1;
		while(!isPrime(q))
			q --;
		ll ans = 1;
		for(ll i = q + 1 ; i <= p - 2 ; i ++)
		{
			ans = mul(ans,inverse(i),p);
			ans %= p;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
5
1000000000009
*/

