#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define pi 3.1415926
#define eps 1e-8
#define g 9.8
using namespace std;
double h,v;
double Calc(double t)
{
	double t1,t2;
    t1 = sin(t)*v/g;
    t2 = sqrt((h+v*sin(t)*t1-0.5*g*t1*t1)*2/g);
    return (t1+t2)*v*cos(t);
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		 
		cin >> h >> v;
		if(h == 0)
		{
			printf("%.2lf\n",Calc(pi/4.0));
		}
		else
		{
			double l = 0 , r = pi / 2;
			while(r - l > eps)
			{
				double mid = (l + r) / 2;
				double mmid = (mid + r) / 2;
				double c_m = Calc(mid);
				double c_mm = Calc(mmid);
				if(c_m > c_mm)
					r = mmid;
				else
					l = mid;
			}
			printf("%.2lf\n",Calc(l));
		} 
	} 
	
	return 0;
}
 
