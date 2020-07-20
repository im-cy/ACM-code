#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
int cmp(double x)
{
	if(fabs(x) < eps)
		return 0;
	if(x > 0)
		return 1;
	return -1;
}
inline double sqr(double x)//数的平方 
{
	return x * x;
}
struct point
{
	double x,y;
	point(){}
	point(double a,double b) : x(a) , y(b){}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
	friend point operator + (const point &a,const point &b)
	{
		return point(a.x + b.x , a.y + b.y);
	}
	friend point operator - (const point &a,const point &b)
	{
		return point(a.x - b.x , a.y - b.y);
	}
	friend bool operator ==(const point &a,const point &b)
	{
		return cmp(a.x - b.x) == 0 && cmp(a.y - b.y) == 0;
	}
	friend point operator * (const point &a,const double &b)
	{
		return point(a.x * b,a.y * b);
	}
	friend point operator * (const double &a,const point &b)
	{
		return point(a * b.x,a * b.y);
	}
	friend point operator / (const point &a,const double &b)
	{
		return point(a.x/b,a.y/b);
	}
	double norm()
	{
		return sqrt(sqr(x) + sqr(y));
	}
};
double det(const point &a,const point &b)//计算两向量叉积 
{
	return a.x * b.y - a.y * b.x;
}
double dot(const point &a,const point &b)//计算两向量点积 
{
	return a.x * b.x + a.y * b.y;
}
double dist(const point &a,const point &b)//计算两点距离 
{
	return (a-b).norm();
}
point rotate_point(const point &p,double A)//向量op绕原点逆时针旋转A(弧度) 
{
	double tx = p.x , ty = p.y;
	return point(tx * cos(A) - ty * sin(A),tx * sin(A) + ty * cos(A)); 
}
//------------------------------------------------------------------------------------------------------------------------------ 
struct line
{
	point a,b;//线段的两个端点 
	line(){}
	line(point x,point y): a(x),b(y){}
}l[201];
line point_make_line(const point a,const point b)//用两个点a,b生成的一个线段或者直线 
{
	return line(a,b);
}
double dis_point_segment(const point p,const point s,const point t)//求p点到线段st的距离 
{
	if(cmp(dot(p-s,t-s)) < 0)
		return (p-s).norm();
	if(cmp(dot(p-t,s-t)) < 0)
		return (p-t).norm();
	return fabs(det(s-p,t-p)/dist(s,t));
}
void PointPrpjLine(const point p,const point s,const point t,point &cp)//求p点到线段st的垂足，保存在cp中 
{
	double r = dot((t-s),(p-s)) / dot(t-s,t-s);
	cp = s + r*(t-s);
}
bool PointOnSegment(point p,point s,point t)//判断点p是否在线段st上 
{
	return cmp(det(p-s,t-s)) == 0 && cmp(dot(p-s,p-t)) <= 0;
}
bool parallel(line a,line b)//判断线段a,b是否平行 
{
	return !cmp(det(a.a-a.b,b.a-b.b));
}
bool line_make_point(line a,line b,point &res)//判断线段a,b是否相交，如果相交则返回true且交点保存在res中 
{
	if(parallel(a,b))
	{
		if(PointOnSegment(a.a,b.a,b.b) || PointOnSegment(a.b,b.a,b.b))
			return true;
		if(PointOnSegment(b.a,a.a,a.b) || PointOnSegment(b.b,a.a,a.b))
			return true;
		return false;
	}
	double s1 = det(a.a-b.a,b.b-b.a);
	double s2 = det(a.b-b.a,b.b-b.a);
	res = (s1*a.b-s2*a.a) / (s1-s2);
	if(PointOnSegment(res,a.a,a.b) && PointOnSegment(res,b.a,b.b))
		return true;
	return false;
}
line move_d(line a,const double &len)//将直线a沿法向量方向平移距离len得到的直线 
{
	point d = a.b - a.a;
	d = d / d.norm();
	d = rotate_point(d,pi/2);
	return line(a.a+d*len,a.b+d*len);
}
int n;
int f[201];
int find(int x)
{
	if(f[x] == x)
		return x;
	return f[x] = find(f[x]);
}
int main()
{
	while(scanf("%d",&n) && n)
	{
		memset(l,0,sizeof(l));
		for(int i = 1 ; i <= n ; i ++)
			f[i] = i;
		for(int i = 1 ; i <= n ; i ++)
		{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			l[i] = point_make_line(point(x1,y1),point(x2,y2));
		}
		point temp;
		for(int i = 1 ; i <= n ; i ++)
			for(int j = i + 1 ; j <= n ; j ++)
				if(line_make_point(l[i],l[j],temp))
					f[find(i)] = find(j);
		int ins_x,ins_y;
		while(scanf("%d%d",&ins_x,&ins_y) && ins_x && ins_y)
		{
			if(find(ins_x) == find(ins_y))
				puts("CONNECTED");
			else
				puts("NOT CONNECTED");
		}
	}
	return 0;
}
