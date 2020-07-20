#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<ctime>
#include<cmath>
#include<set>
#include<map>
#define ull unsigned long long
#define ll long long
#define INF 10000
using namespace std;
const int sz = 200010;
struct node
{
	int w,h;
}num[sz],tmp[sz];
bool cmp(node a,node b)
{
	return a.h < b.h;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d%d",&num[i].w,&num[i].h);
	sort(num+1,num+n+1,cmp);
	ll ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1 ; i <= n ; i ++)
	{
		ll tmp = 0;
		for(int j = i + 1 ; j <= i + k ; j ++)
		{
			tmp += num[j].w * (num[j].h - num[i].h);
		}
		printf("tmp %lld\n",tmp);
		ans = min(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}

