#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int sz = 200010;
int f[sz*2];
int p[111];
bool T[101];
int n;
struct Node
{
	char a,b;
	int x,y;
}in[sz];
int find(int x)
{
	if(f[x] == x)
		return x;
	return f[x] = find(f[x]);
}
bool check(int p1,int p2,int p3)
{
	memset(T,0,sizeof(T));
	T[p1] = 1 , T[p2] = 1 , T[p3] = 1;
	for(int i = 1 ; i <= 2 * 26 ; i ++)
		f[i] = i;
	for(int i = 1 ; i <= n ; i ++)
	{
		int A_ = in[i].a - 'A' + 1;
		int B_ = in[i].b - 'A' + 1;
		int fx = find(A_) , fy = find(B_);
		if(in[i].y == 2)
		{
			if(T[A_] || T[B_])
				return false;
			if(p[A_] == in[i].x^1 || p[B_] == in[i].x^1)
				return false;
			if(find(fx) == find(fy))
				return false;
			p[A_] = in[i].x , p[B_] = in[i].x;
		}
		else if(in[i].y == 0)
		{
			if(p[A_] == in[i].x || p[B_] == in[i].x)
				return false;
			if(find(fx) == find(fy))
				return false;
			if(!T[A_])
				p[A_] = in[i].x^1;
			if(!T[B_])
				p[B_] = in[i].x^1;
				
		}
		else
		{
			if(T[A_] && T[B_])
				return false;
			else if(T[A_] && p[B_] != in[i].x^1)
				p[A_] = in[i].x;
			else if(T[B_] && p[A_] != in[i].x^1)
				p[B_] = in[i].x;
			else if(T[B_] && p[A_] == in[i].x^1)
				return false;
			else if(T[A_] && p[B_] == in[i].x^1)
				return false;
			if(!T[A_] && !T[B_])
			{
				if(p[A_] == in[i].x && p[B_] == in[i].x)
					return false;
				if(p[A_] == in[i].x^1 && p[B_] == in[i].x^1)
					return false;
				if(p[A_] == in[i].x)
					p[B_] = in[i].x^1;
				else if(p[B_] == in[i].x)
					p[A_] = in[i].x^1;
				else if(p[B_] == in[i].x^1)
					p[A_] = in[i].x;
				else if(p[A_] == in[i].x^1)
					p[B_] = in[i].x;
				else
				{
					f[fx] = find(fy+26);
					f[fy] = find(fx+26);
				}
			}
			
		}
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++)
	{
		in[i].a = getchar();
		while(in[i].a < 'A' || in[i].a > 'Z')
			in[i].a = getchar();
		in[i].b = getchar();
		while(in[i].b < 'A' || in[i].b > 'Z')
			in[i].b = getchar();
		scanf("%d%d",&in[i].x,&in[i].y);
		in[i].x --;
	}
	int ans = 0;
	for(int p1 = 1 ; p1 <= 26 ; p1 ++)
		for(int p2 = p1 + 1 ; p2 <= 26 ; p2 ++)
			for(int p3 = p2 + 1 ; p3 <= 26 ; p3 ++)
				if(check(p1,p2,p3))
					ans ++;
	printf("%d\n",ans);
	return 0;
}


