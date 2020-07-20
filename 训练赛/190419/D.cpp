#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
const int sz = 2000010;
int n,m;
int a[sz],b[sz];
void read(int &x)
{
	x = 0;
	char in = getchar();
	while(in < '0' || in > '9')
	{
		in = getchar();
	}
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in - '0';
		in = getchar();
	}
	return ;
}

int main()
{
	freopen("deposits.in","r",stdin);
	freopen("deposits.out","w",stdout);
	read(n);
	for(int i = 1 ; i <= n ; i ++)
		read(a[i]);
	read(m);
	for(int i = 1 ; i <= m ; i ++)
	{
		int temp;
		read(temp);
		b[temp] ++;
	}
	ll ans = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j * j <= a[i] ; j ++)
		{
			if(!(a[i]%j))
			{
				if(j != a[i]/j)
					ans += b[j] + b[a[i]/j];
				else
					ans += b[j];
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}

