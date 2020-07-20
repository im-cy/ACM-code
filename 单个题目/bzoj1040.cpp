#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int sz = 200010;
int hed[sz],nxt[sz],w[sz],l[sz];
int tot = 1;
int n;
void build(int f,int t)
{
	l[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot;
}


int main()
{
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++)
	{
		int t;
		scanf("%d%d",&w[i],&t);
		build(t,i);
		build(i,t);
	}
	
	return 0;
}

