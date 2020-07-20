#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[201];
bool check(int n)
{
	for(int i = 0 ; i <= 50 ; i ++)
		if(f[i] == n)
			return true;
	return false;
}
int main()
{
	f[1] = 1;
	for(int i = 2 ; i <= 50 ; i ++)
		f[i] = f[i-1] + f[i-2];
	ll n;
	while(scanf("%lld",&n) && n)
	{
		if(check(n))
			puts("Second win");
		else
			puts("First win");
	}
	return 0;
}

