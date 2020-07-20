#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 20010;
int n;
struct node
{
	int x,id;
}num[sz];
bool cmp(node a,node b)
{
	return a.x >= b.x;
}
struct edge
{
	int l,r;
}ans[sz],ans2[sz];
int mp[111][111];
int main()
{
	while(scanf("%d",&n) != EOF)
	{
		memset(mp,0,sizeof(mp));
		int cnt1 = 0,cnt2 = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			scanf("%d",&num[i].x);
			num[i].id = i;
		}
		int k = 1;
		while(k <= n)
		{
			sort(num+k,num+n+1,cmp);
			if(num[k].x > n - k)
				break;
			int pos = 0;
			for(int i = 1 ; i <= num[k].x ; i ++)
			{
				if(num[k+i].x <= 0)
					break;
				pos = i;
				num[k+i].x --;
				mp[num[k].id][num[k+i].id] = 1 , mp[num[k+i].id][num[k].id] = 1;
			}
			if(pos < num[k].x)
				break;
			k ++;
		}
		if(k <= n)
			puts("IMPOSSIBLE");
		else
		{
			
			for(int i = 1 ; i <= n ; i ++)
			{
				for(int j = i + 1 ; j <= n ; j ++)
					if(mp[i][j])
					{
						ans[++cnt1].l = i;
						ans[cnt1].r = j;
					}
			}
			bool check = 0;
			
			for(int i = 1 ; i <= n ; i ++)
			{
				for(int j = i + 1 ; j <= n ; j ++)
				{
					if(!mp[i][j])
						continue;
					for(int i2 = 1 ; i2 <= n ; i2 ++)
					{
						if(mp[i][i2] || i2 == j || i2 == i)
							continue;
						for(int j2 = i2 + 1 ; j2 <= n ; j2 ++)
						{
							if(!mp[i2][j2] || j2 == j || j2 == i || mp[j][j2])
								continue;
							check = 1;
							mp[i][j] = 0;
							mp[i2][j2] = 0;
							mp[min(i,i2)][max(i,i2)] = 1;
							mp[min(j,j2)][max(j,j2)] = 1;
							break;
						}
						if(check)
							break;
					}
					if(check)
						break;
				}
				if(check)
					break;
			}
			if(check)
			{
				for(int i = 1 ; i <= n ; i ++)
				{
					for(int j = i + 1 ; j <= n ; j ++)
						if(mp[i][j])
						{
							ans2[++cnt2].l = i;
							ans2[cnt2].r = j;
						}
				}
				puts("MULTIPLE");
				printf("%d %d\n",n,cnt1);
				for(int i = 1 ; i <= cnt1 ; i ++)
					printf("%d ",ans[i].l);
				puts("");
				for(int i = 1 ; i <= cnt1 ; i ++)
					printf("%d ",ans[i].r);
				puts("");
				printf("%d %d\n",n,cnt2);
				for(int i = 1 ; i <= cnt2 ; i ++)
					printf("%d ",ans2[i].l);
				puts("");
				for(int i = 1 ; i <= cnt2 ; i ++)
					printf("%d ",ans2[i].r);
				puts("");
			}
			else
			{
				puts("UNIQUE");
				printf("%d %d\n",n,cnt1);
				for(int i = 1 ; i <= cnt1 ; i ++)
					printf("%d ",ans[i].l);
				puts("");
				for(int i = 1 ; i <= cnt1 ; i ++)
					printf("%d ",ans[i].r);
				puts("");
			}
		}
	}
	return 0;
}
/*
1
0
6
5 5 5 4 4 3
6
5 4 4 4 4 3
6
3 4 3 1 2 0
4
1 1 1 1
*/

