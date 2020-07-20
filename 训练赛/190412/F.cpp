#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int t1,t2;
	t1 = k / n;
	t2 = k % n;
	double ans = 0;
	printf("%d %d\n",t1,t2);
	for(int i = 1 ; i <= t2 ; i ++)
	{
		double temp = 1.0;
		for(int j = 1 ; j <= t1 + 1 ; j ++)
		{
			temp *= 0.5;
			ans += temp;
		}
	}
	for(int i = t2 + 1 ; i <= n ; i ++)
	{
		double temp = 1.0;
		for(int j = 1 ; j <= t1 ; j ++)
		{
			temp *= 0.5;
			ans += temp;
		}
	}
	printf("%.9f\n",ans);
	return 0;
}

