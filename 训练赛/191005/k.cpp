#include<bits/stdc++.h>
using namespace std;
const int sz = 2000010;

struct circle
{
	double x,y,r;
}cir[sz];

double getdist(circle p,circle q)
{
    double x2 = (p.x - q.x); x2 = x2 * x2;
    double y2 = (p.y - q.y); y2 = y2 * y2;
    return sqrt(x2 + y2);
}
bool check(circle a,circle b)
{
	double dis = getdist(a,b);
	if(dis >= abs(a.r-b.r) && dis <= abs(a.r+b.r))
		return true;
	return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n <= 10000)
	{
		for(int i = 1 ; i <= n ; i ++)
			scanf("%lf%lf%lf",&cir[i].x,&cir[i].y,&cir[i].r);
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++)
			for(int j = i + 1 ; j <= n ; j ++)
				if(check(cir[i],cir[j]))
					ans += 2;
		if(ans > 2 * n)
			puts("greater");
		else
			printf("%d\n",ans);
	}
	else{
		n=10000;
		for(int i = 1 ; i <= n ; i ++)
			scanf("%lf%lf%lf",&cir[i].x,&cir[i].y,&cir[i].r);
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++)
			for(int j = i + 1 ; j <= n ; j ++)
				if(check(cir[i],cir[j]))
					ans += 2;
		if(ans)
			puts("greater");
		else
			printf("%d\n",ans);		
	}
	return 0;
}


