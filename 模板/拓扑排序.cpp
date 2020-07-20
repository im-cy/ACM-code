#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int sz = 200010;
int head[sz],nxt[sz],l[sz];
int ru[sz];//点 i 的入度 
int tot = 1;
int n,m;
queue < int > q;
void build(int f,int t)
{
    l[tot] = t;
    nxt[tot] = head[f];
    head[f] = tot ++;
}
void top_sort()
{
    for(int i = 1 ; i <= n ; i ++)
        if(!ru[i])
        {
            q.push(i);
            printf("%d ",i);
        }
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int i = head[f] ; i ; i = nxt[i])
        {
            ru[l[i]] --;
            if(!ru[l[i]])
            {
                printf("%d ",l[i]);
                q.push(l[i]);
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= m ; i ++)
    {
        int f,t;
        scanf("%d%d",&f,&t);
        ru[t] ++;
        build(f,t);
    }
    top_sort();
    return 0;
}
