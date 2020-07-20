#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int read()
{
	int x = 0 , f = 1;
	char in = getchar();
	while(in < '0' || in > '9')
	{
		if(in == '-')
			f = -1;
		in = getchar();
	
	}
	while(in >= '0' && in <= '9')
	{
		x = x * 10 + in - '0';
		in = getchar();
	}
	return x * f;
}


int main()
{
	int n,S;
	scanf("%d%d",&n,&S);
	int ans = 0;
	bool is_z = 0;
	for(int i = n ; i >= 1 ; i --)
	{
		if(S >= i)
		{
			ans += S / i;
			S %= i;
		}
	}
	printf("%d\n",ans);
	return 0;
}
