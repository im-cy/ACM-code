#include<bits/stdc++.h>
using namespace std;
const int sz = 200100;
int n,r;

struct node
{
	int a,b;
	bool vis;
}num[sz];
bool cmp(node a,node b)
{
	if(a.a == b.a)
		return a.b < b.b;
	return a.a < b.a;
}
bool cmp1(node a,node b)
{
	return a.a + a.b > b.a + b.b;
}
int check()
{
	int ans = 0;
	int now = r;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(num[i].b >= 0)
		{
			if(num[i].a <= now)
				now += num[i].b , num[i].vis = 1;
		}
	}
	
	sort(num+1,num+n+1,cmp1);
	for(int i = 1 ; i <= n ; i ++)
	{
		if(num[i].b < 0)
		{
			if(num[i].a <= now && now >= (-num[i].b))
				now += num[i].b , num[i].vis = 1;
		}
	}
	for(int i = 1 ; i <= n ; i ++)
		if(num[i].vis)
			ans ++;
	return ans;
}
int main()
{
	scanf("%d%d",&n,&r);
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%d%d",&num[i].a,&num[i].b);
	}
	sort(num+1,num+n+1,cmp);
	int ans = check();
	printf("%d\n",ans);
	return 0;
}

