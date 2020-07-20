#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
const double zero = 1e-8;
struct Vector
{
	double x,y;
};
inline Vector operator -(Vector a,Vector b)
{
	Vector c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}
inline double Sqr(double a)
{
	return a * a;
}
inline int Sign(double a)
{
	if(fabs(a) <= zero)
		return 0;
	return a < 0 ? -1 : 1;
}
inline bool operator < (Vector a,Vector b)
{
	return Sign(b.y - a.y) > 0 || Sign(b.y - a.y) == 0 && Sign(b.x - a.x) > 0 ;
}
inline double Max(double a,double b)
{
	return a > b ? a : b;
}
inline double Length(Vector a)
{
	return sqrt(Sqr(a.x) + Sqr(a.y));
}
inline double Cross(Vector a,Vector b)
{
	return a.x * b.y - a.y * b.x;
}
Vector dot[maxn], List[maxn];
double opt[maxn][maxn];
int seq[maxn];
int n,len;
double ans;
bool Compare(Vector a,Vector b)
{
	int temp = Sign(Cross(a,b));
	if(temp != 0)
		return temp > 0;
	temp = Sign(Length(b) - Length(a));
	return temp > 0;
}
void Solve(int vv)
{
	int t,i,j,_len;
	for(i = len = 0 ; i < n ; i ++)
		if(dot[vv] < dot[i])
			List[len++] = dot[i] - dot[vv];
	for(i = 0 ; i < len ; i ++)
		for(j = 0 ; j < len ; j ++)
			opt[i][j] = 0;
	sort(List,List+len,Compare);
	double v;
	for(t = 1 ; t < len ; t ++)
	{
		_len = 0;
		for(i = t-1 ; i >= 0 && Sign(Cross(List[t],List[i])) == 0 ; i --);
		while(i >= 0)
		{
			v = Cross(List[i],List[t]) / 2;
			seq[_len++] = i;
			for(j = i-1 ; j >= 0 && Sign(Cross(List[i]-List[t],List[j]-List[t])) > 0 ; j --);
			if(j >= 0)
				v += opt[i][j];
			ans = Max(ans,v);
			opt[t][i] = v;
			i = j;
		}
		for(i = _len - 2 ; i >= 0 ; i --)
			opt[t][seq[i]] = Max(opt[t][seq[i]],opt[t][seq[i+1]]);
	}
}
int i;
double Empty()
{
	ans = 0;
	for(i = 0 ; i < n ; i ++)
		Solve(i);
	return ans;
}




int main()
{
	
	
	return 0;
}

