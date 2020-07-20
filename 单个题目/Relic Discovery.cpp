#include<bits/stdc++.h>
using namespace std;
const int sz = 200100;
int read()
{
	int x = 0;
	char in = getchar();
	while(in < '0' || in > '9')
		in = getchar();
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in - '0';
		in = getchar();
	}
	return x;
}
int main()
{
	int T = read();
	while(T --)
	{
		int n = read();
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			int a = read() , b = read();
			ans += a * b;
		}
		printf("%d\n",ans);
	}
	return 0;
}
///



