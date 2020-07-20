#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int sz = 200100;
int f[sz],r[sz];
int find(int x)
{
	
	
}
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; i ++)
		f[i] = i , r[i] = 0;
	int ans = 0;
	for(int i = 1 ; i <= k ; i ++)
	{
		int ins,a,b;
		scanf("%d%d%d",&ins,&a,&b);
		if(a > n || b > n)
		{
			ans ++;
			continue;
		}
		if(a == b)
		{
			if(ins == 2)
				ans ++;
			continue;
		}
		int fa = find(a) , fb = find(b);
		if(fa == fb)
		{
			if(ins == 1)
			{
				if(r[a] != r[b])
					ans ++
			}
			else
			{
				
			}
		}
	}
	return 0;
}
