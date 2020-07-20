#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll x = 0 , f = 1;
	char in = getchar();
	while(in < '0'  || in > '9')
	{
		if(in == '-')
			f = -1;
		in = getchar();
	}
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in - '0';
		in = getchar();
	}
	return x * f;
}
const int sz = 200010;
ll num[sz];
int main()
{

	int n = read();
	for(int i = 1 ; i <= n ; i ++)
	{
		num[i] = read();
	}
	sort(num+1,num+n+1);
	int m = n / 2;
	if(n%2)
		m ++;
	ll a = 0 , b = 0;
	for(int i = 1 ; i <= m ; i ++)
	{
		a += num[n-i+1];
	}
	for(int i = 1 ; i <= n - m ; i ++)
		b += num[i];
	printf("%I64d\n",a*a+b*b);
	return 0;
}
