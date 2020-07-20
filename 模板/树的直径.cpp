#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
const int size = 200010;
int head[size],next[size],l[size];
int tot = 1;
void build(int f,int t)
{
    l[tot] = t;
    next[tot] = head[f];
    head[f] = tot ++;
}
int pos,dist;
void dfs(int u,int p,int dis)
{
    if(dis > dist)
        dist = dis , pos = u;
    for(int i = head[u] ; i ; i = next[i])
    {
        int v = l[i];
        if(v != p)
            dfs(v,u,dis+1);
    }
}
int get_length()
{
	pos = 0 , dist = 0;
	dfs(1,-1,0);
    dist = 0;
    dfs(pos,-1,0);
	return dist;
}
int main()
{
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++)
    {
        int ll,rr;
        scanf("%d%d",&ll,&rr);
        if(ll)
            build(ll,i) , build(i,ll);
        if(rr)
            build(rr,i) , build(i,rr);
    }
    int ans = get_length();
    return 0;
} 
