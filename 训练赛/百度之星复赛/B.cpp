#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
const int sz = 2e5+9;
ll n;
ll read()
{
	ll x = 0 , f = 1;
	char in = getchar();
	while(in < '0' || in > '9')
	{
		if(in == '-')
			f = -1;
		in = getchar();
	}
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in  - '0';
		in = getchar();
	}
	return x * f;
}
ll a,b,c,d;
ll ans[sz];
bool check()
{
	bool swaped = false;
    if(c > d)
	{
        if(a < b)
            return false;
        swap(a, b);
        swap(c, d);
        swaped = true;
    }
	else if (c < d && a > b)
	{
        return false;
    }
	while(c != a || b != d)
	{
		if((c + d) % 2)
			return false;
		if(a == b || c == d)
			return false;
		ll mid = (c + d) >> 1;
		if(mid >= b)
		{
			d = mid;
			if(swaped)
				ans[++ans[0]] = 0;
			else
				ans[++ans[0]] = 1;
		}
		else if(mid <= a)
		{
			c = mid;
			if(swaped)
				ans[++ans[0]] = 1;
			else
				ans[++ans[0]] = 0;
		}
		else
			return false;
	}
	return true;
}
int main()
{
	int T = read();
	while(T --)
	{
		a = read() , b = read() , c = read() , d = read();
		ans[0] = 0;
		bool temp = check();
		if(temp)
		{
			puts("Yes");
			for(int i = ans[0] ; i >= 1 ; i --)
			{
				if(ans[i])
					printf("A");
				else
					printf("B");
			}
			puts("");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}
