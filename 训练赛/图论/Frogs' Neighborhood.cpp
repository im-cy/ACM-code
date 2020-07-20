#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 200010;
int n;
struct node
{
	int x,id;
}num[sz];
bool cmp(node a,node b)
{
	return a.x >= b.x;
}
int mp[21][21];
int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		memset(mp,0,sizeof(mp));
		
		scanf("%d",&n);
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
			puts("NO");
		else
		{
			puts("YES");
			for(int i = 1 ; i <= n ; i ++)
			{
				for(int j = 1 ; j <= n ; j ++)
				{
					if(j != 1)
						printf(" ");
					printf("%d",mp[i][j]);
				}
				puts("");
			}
			
		}
		if(T)
			puts("");
	}
	
	return 0;
}

