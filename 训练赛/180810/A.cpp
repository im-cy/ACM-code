#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int sz = 200010; 
int n;
int h[sz],L[sz],R[sz],st[sz];
void solve()
{
	int t = 0;
	for(int i = 0 ; i < n ; i ++)
	{
		while(t > 0 && h[st[t - 1]] >= h[i])
			t --;
		L[i] = t == 0 ? 0 :(st[t - 1] + 1);
		st[t ++]= i;
	}
	t = 0;
	for(int i = n - 1 ; i >= 0 ; i --)
	{
		while(t > 0 && h[st[t - 1]] >= h[i])
			t --;
		R[i] = t == 0 ? n : st[t - 1];
		st[t ++] = i;
	}
	long long res = 0;
	for(int i = 0 ; i < n ; i ++)
		res = max(res , (long long)h[i] * (R[i] - L[i]));
	printf("%lld\n",res);
}
void init()
{
	memset(h,0,sizeof(h));
	memset(L,0,sizeof(L));
	memset(R,0,sizeof(R));
	memset(st,0,sizeof(st));
	return ;
}
int main()
{
	while(scanf("%d",&n) && n)
	{
		init();
		for(int i = 0 ; i < n ; i ++)
			scanf("%d",&h[i]);
		solve();
	}
	
	return 0;
}
 
