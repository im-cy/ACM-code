#include<iostream>
#include<cstdio>
#include<cstring>
#define eps 1e-7
using namespace std;
int pos[100010];
int v[100010];
int n;
bool check(double k)
{
	double l_min = pos[1] - k * v[1];
	double r_min = pos[1] + k * v[1];
	for(int i = 2 ; i <= n ; i ++)
	{
		double l = pos[i] - k * v[i];
		double r = pos[i] + k * v[i];
		if(l_min > r)
			return false;
		if(r_min < l)
			return false;
		l_min = max(l_min,l) , r_min = min(r_min,r);	
	}
	return true;
}

int main()
{
	//int t;
//	scanf("%d",&t);
//	while(t --)
	{
		
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i ++)
			scanf("%d",&pos[i]);
		for(int i = 1 ; i <= n ; i ++)
			scanf("%d",&v[i]);
		double l = 0, r = 1e10;
		while(r - l > eps)
		{
			double mid = (l + r) / 2;
			if(check(mid))
				r = mid;
			else
				l = mid;
		}
		printf("%.7lf\n",l);
	}
	
	return 0;
}

