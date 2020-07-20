#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,k;
double len[20100];
bool check(double mid)
{
	int now = 0;
	for(int i = 1 ; i <= n ; i ++)
		now += (int)(len[i]/mid);
	if(now >= k)
		return true;
	return false;
}
int main()
{
	while(scanf("%d%d",&n,&k) != EOF)
	{
		double l = 0 , r = 0;
		for(int i = 1 ; i <= n ; i ++)
			scanf("%lf",&len[i]);
		r = 100010;
		for(int i = 1 ; i <= 100 ; i ++)
		{
			double mid = (l + r) / 2.0;
			if(check(mid))
				l = mid;
			else
				r = mid;
		}
		printf("%.2lf\n",floor(l*100)/100);
	}
	return 0;
}
 
