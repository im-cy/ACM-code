#include<bits/stdc++.h>
using namespace std;
const int sz = 200100;
struct P
{
	bool is;
	int l,r;
}g,y,r;
int tim;
char ins[21];
void updateg()
{
	if(!g.is)
		g.r = tim + 1 , g.is = 1;
	else if(g.r <= tim + 1)
		g.r = tim + 1;
}
void updatey()
{
	if(!y.is)
	{
		y.l = tim;
		y.r = tim + 1;
		y.is = 1;
	}
	else if(y.l >= tim)
		y.l = tim;
	else if(y.r <= tim + 1)
		y.r = tim + 1;
}
void updater()
{
	if(!r.is)
	{
		r.l = tim;
		r.is = 1;
	}
	else if(r.l >= tim)
		r.l = tim;
}
bool check()
{
	if(ins[0] == 'G')
	{
		if(!y.is && !r.is)
		{
			updateg();
			return true;
		}
		if(y.is)
		{
			if(tim >= y.l && tim < y.r)
				return false;
		}
		if(r.is)
		{
			if(tim >= r.l && tim < r.r)
				return false;
		}
		updateg();
		return true;
	}
	else if(ins[0] == 'Y')
	{
		if(!r.is && !g.is)
		{
			updatey();
			return true;
		}
		if(r.is)
		{
			if(tim >= r.l && tim < r.r)
				return false;
		}
		if(g.is)
		{
			if(tim >= g.l && tim < g.r)
				return false;
		}
		updatey();
		return true;
	}
	else//R
	{
		if(!g.is && !y.is)
		{
			updater();
			return true;
		}
		if(g.is)
		{
			if(tim >= g.l && tim < g.r)
				return false;
		}
		if(y.is)
		{
			if(tim >= y.l && tim < y.r)
				return false;
		}
		updater();
		return true;
	}
	
}


int main()
{
	int n,T;
	scanf("%d%d",&n,&T);
	g.l = 0 , g.r = -1;
	y.l = -1, y.r = -1;
	r.l = -1, r.r = T;
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%d%s",&tim,ins);
		tim %= T;
		if(!check())
		{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("Correct!");
	
	return 0;
}
/*
3 3
0 G
1 Y
1 R

*/
