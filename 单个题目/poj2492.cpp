#include<iostream>
#include<cstdio>
using namespace std;
const int sz = 200010;
int f[sz],r[sz];
int find(int x)
{
	int temp = f[x];
	if(f[x] != x)
	{
		f[x] = find(f[x]);
		r[x] = (r[x] + r[temp]) % 2;
	}
	return f[x];
}
int main()
{
	int t;
	int k = 0;
	scanf("%d",&t);
	while(t --)
	{
		int n,m;
		k ++;
		scanf("%d%d",&n,&m);
		for(int i = 1 ; i <= n ; i ++)
			f[i] = i , r[i] = 0;
		bool is_wa = 0;
		for(int i = 1 ; i <= m ; i ++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			int fa = find(a) , fb = find(b);
			if(fa == fb)
			{
				if((r[a] + r[b]) % 2 == 0)
				{
					is_wa = 1;
				}
			}
			else
			{
				f[fa] = fb;
				r[fa] = (r[a] - r[b] + 1) % 2;
			}
		}
		if(t > 0)
		{
			if(is_wa)
			{
				printf("Scenario #%d:\n",k);
				puts("Suspicious bugs found!");
			}
			else
			{
				printf("Scenario #%d:\n",k);
				puts("No suspicious bugs found!");
			}
			puts("");
		}
		else
		{
			if(is_wa)
			{
				printf("Scenario #%d:\n",k);
				printf("Suspicious bugs found!");
			}
			else
			{
				printf("Scenario #%d:\n",k);
				printf("No suspicious bugs found!");
			}
		}
	}
	
	return 0;
}

