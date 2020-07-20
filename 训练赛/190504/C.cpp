#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
map < int , int > mp;
const ll mod =  998244353;
int n,m;
int num[1010];
ll ksm(ll x,ll p)
{
	if(p == 0)
		return 1;
	if(p == 1)
		return x % mod;
	if(p == 2)
		return ((x % mod) * (x % mod))%mod;
	ll temp = ksm(x,p/2) % mod;
	if(p % 2)
		return (((temp * temp) % mod) * (x % mod)) % mod;
	return (temp * temp) % mod;
}
ll ny(ll x)
{
	return ksm(x,mod-2) % mod;
}

int main()
{
	scanf("%d%d",&n,&m);
	int x = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%d",&num[i]);
		if(mp[num[i]] == 0)
			x ++;
		mp[num[i]] ++;
	}
	
	return 0;
}

