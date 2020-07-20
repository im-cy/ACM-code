#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int sz = 200010;
int hed[sz],nxt[sz],dist[sz];
struct edge
{
    int t,d;
}l[sz];
int tot = 1;
bool use[sz];
queue < int > q;
int n,m;
void build(int f,int t,int d)
{
    l[tot].t = t;
    l[tot].d = d;
    nxt[tot] = hed[f];
    hed[f] = tot ++;
}
void spfa(int s)
{
    for(int i = 1 ; i <= n ; i ++)
        dist[i] = 214748364;
    dist[s] = 0;
    q.push(s);
    use[s] = 1;
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        use[f] = 0;
        for(int i = hed[f] ; i ; i = nxt[i])
        {
            int t = l[i].t;
            if(dist[t] > dist[f] + l[i].d)
            {
                dist[t] = dist[f] + l[i].d;
                if(!use[t])
                {
                    use[t] = 1;
                    q.push(t);
                }
            }
        }
    }
    return ;
}
int main()
{
    int s,e;
    scanf("%d%d%d%d",&n,&m,&s,&e);
    for(int i = 1 ; i <= m ; i ++)
    {
        int f,t,d;
        scanf("%d%d%d",&f,&t,&d);
        build(f,t,d);
        build(t,f,d);
    }
    spfa(s);
    printf("%d\n",dist[e]);
    return 0;
}
