#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int sz = 200010;
int hed[sz],nxt[sz];
int n,m;
struct dc
{
	int t,d;
}l[sz];
int tot = 1;
void build(int f,int t,int d)
{
	l[tot].t = t;
	l[tot].d = d;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
void init()
{
	memset(hed,0,sizeof(hed));
	memset(nxt,0,sizeof(nxt));
	memset(l,0,sizeof(l));
	tot = 1;
}
void ask(int x)
{
	int ans1 = 0;
	int ans2 = 0;
	for(int i = hed[x] ; i ; i = nxt[i])
		ans1 ^= l[i].d;
	if(!ans1)
		puts("Boys win!");
	else
		puts("Girls win!");
	return ;
}
void read_in()
{
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i < n ; i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		build(x,y,z);
		build(y,x,z);
	}
	for(int i = 1 ; i <= m ; i ++)
	{
		int ins;
		scanf("%d",&ins);
		if(ins == 1)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			for(int j = hed[x] ; j ; j = nxt[j])
				if(l[j].t == y)
					l[j].d = z;
			for(int j = hed[y] ; j ; j = nxt[j])
				if(l[j].t == x)
					l[j].d = z;
		}
		else
		{
			int x;
			scanf("%d",&x);
			ask(x);
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		init();
		read_in();
	}
	return 0;
}
/*
2
2 3
1 2 0
0 1
1 2 1 1
0 2
*/
