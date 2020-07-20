#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int sz = 2550;
int dis[sz][sz];
int n,m,s,e;
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&e);
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            dis[i][j] = 214748364;
    for(int i = 1 ; i <= n ; i ++)
        dis[i][i] = 0;
    for(int i = 1 ; i <= m ; i ++)
    {
        int f,t,d;
        scanf("%d%d%d",&f,&t,&d);
        dis[f][t] = min(dis[f][t],d);
        dis[t][f] = min(dis[f][t],dis[t][f]);
    }
    for(int k = 1 ; k <= n ; k ++)
        for(int i = 1 ; i <= n ; i ++)
            for(int j = 1 ; j <= n ; j ++)
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    printf("%d\n",dis[s][e]);
    return 0;
}
