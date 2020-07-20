#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const double h = sqrt(3.0) / 2.0;
int grid(double r,double c)
{
	int rr = (int)r;
	int cc = (int)c;
	return rr * cc;
}
int skew(double r,double c)
{
	int turn = 1;
	double now_r;
	int ans = 0;
	if(c < 1 || r < 1)
		return 0;
	c -= 1;
	int temp_r = r;
	ans += r;
	while(c > h)
	{
		temp_r = r - (turn % 2) * 0.5;
		ans += temp_r;
		turn ++;
		c -= h;
	}
	return ans;
}
int main()
{
	double r,c;
	while(scanf("%lf%lf",&r,&c) != EOF)
	{
		int ans1 = max(grid(r,c),grid(c,r));
		int ans2 = max(skew(r,c),skew(c,r));
		if(ans1 >= ans2)
			printf("%d grid\n",ans1);
		else
			printf("%d skew\n",ans2);
	}
	return 0;
}
