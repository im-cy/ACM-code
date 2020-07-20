#include<iostream>
#include<cstdio>
#include<cstring>
#define eps 1e-10
using namespace std;
double f(double x)
{
	double ans = 0;
	ans += 8.0 * x * x * x * x;
	ans += 7.0 * x * x * x;
	ans += 2.0 * x * x;
	ans += 3.0 * x;
	ans += 6.0;
	return ans;
}
double fabs(double x)
{
	if(x > 0)
		return x;
	return -x;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		double y;
		cin >> y;
		double l = 0 , r = 100;
		while(r - l > eps)
		{
			double x = (l + r) / 2.0;
			if(f(x) - y <= 0)
				l = x;
			else
				r = x;
		}
		if(fabs(f(l) - y) > 1e-2)
			puts("No solution!");
		else
			printf("%.4lf\n",l);
	}
	
	
	
	return 0;
}
 
