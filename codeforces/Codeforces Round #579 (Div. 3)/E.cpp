#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 200010;
int num[sz];
bool vis[sz];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%d",&num[i]);
	}
	sort(num+1,num+n+1);
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(!vis[num[i]-1] && num[i]-1 > 0)
		{
			vis[num[i]-1] = 1;
			ans ++;
		}
		else if(!vis[num[i]])
		{
			vis[num[i]] = 1;
			ans ++;
		}
		else if(!vis[num[i]+1])
		{
			vis[num[i]+1] = 1;
			ans ++;
		}
	}
//	puts("");
	printf("%d\n",ans);
	return 0;
}

