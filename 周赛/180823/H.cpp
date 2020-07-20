#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
const int sz = 201;
int num[sz];
map < int , int > ans;
int n,m;
int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		ans.clear();
		memset(num,0,sizeof(num));
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i ++)
			scanf("%d",&num[i]);
		for(int i = 1 ; i <= n ; i ++)
		{
			int temp = 0;
			for(int j = 1 ; j <= n ; j ++)
			{
				if(i + j - 1 > n)
					break;
				temp ^= num[i+j-1];
				if(!ans[temp] || ans[temp] < j)
					ans[temp] = j;
			}
		}
		scanf("%d",&m);
		for(int i = 1 ; i <= m ; i ++)
		{
			int x;
			scanf("%d",&x);
			int l,r;
			l = x , r = x;
			while(!ans[l] && !ans[r])
			{
				l --;
				r ++;
			}
			printf("%d\n",max(ans[l],ans[r]));
		}
		puts("");
	}
	
	
	return 0;
}
 
