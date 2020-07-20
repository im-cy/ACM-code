#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 200100;
int n,k;
int v[sz],w[sz];
int ans[sz];
struct dc
{
	int p;
	double v;
}num[sz];
bool cmp(dc a,dc b)
{
	return a.v > b.v;
}
bool check(double mid)
{
	for(int i = 1 ; i <= n ; i ++)
		num[i].p = i;
	for(int i = 1 ; i <= n ; i ++)
		num[i].v = v[i] - mid * w[i];
	sort(num+1,num+n+1,cmp);
	double sum = 0;
	for(int i = 1 ; i <= k ; i ++)
		sum += num[i].v , ans[i] = num[i].p;
	if(sum < 0)
		return true;
	return false;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d%d",&v[i],&w[i]);
	double l = 0 , r = 1e7;	
	while(r - l > 1e-6)
	{
		double mid = (l + r) / 2;
		if(check(mid))
			r = mid;
		else
			l = mid;
	}
	for(int i = 1 ; i <= k ; i ++)
		printf("%d ",ans[i]);
	return 0;
}
