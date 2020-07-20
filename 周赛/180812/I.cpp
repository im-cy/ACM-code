#include<iostream>
#include<cstdio>
using namespace std;
const int sz = 2000100;
int f[sz],r[sz];
int find(int x)
{
	if(f[x] != x)
	{
		int temp = find(f[x]);
		r[x] += r[f[x]];
		return f[x] = temp;
	}
	return f[x];
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF)
	{
		for(int i = 1 ; i <= n ; i ++)
			f[i] = i , r[i] = 0;
		int ans = 0;
		for(int i = 1 ; i <= m ; i ++)
		{
			int a,b,s;
			scanf("%d%d%d",&a,&b,&s);
			a --;
			int fa = find(a) , fb = find(b);
			if(fa == fb)
			{
				if(r[b] - r[a] != s)
					ans ++;
			}
			else
			{
				f[fb] = fa;
				r[fb] = (r[a] - r[b] + s);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

