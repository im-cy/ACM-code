#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int sz = 201;
int sg[sz][sz];
int vis[sz];
int GetSG(int n,int m)
{
    if(sg[n][m]!=-1)
        return sg[n][m];
    memset(vis,0,sizeof(vis));
    for(int i = 2 ; i <= n - i ; i ++)
        vis[GetSG(i,m) ^ GetSG(n-i,m)] = 1;
    for(int i = 2 ; i <= m - i ; i ++)
        vis[GetSG(n,i) ^ GetSG(n,m-i)] = 1;
    for(int i = 0 ; ; i ++)
        if(!vis[i])
            return sg[n][m]=i;
}
int main()
{
    int n,m; 
    memset(sg,-1,sizeof(sg));
    while(~scanf("%d%d",&n,&m))
    {
        if(GetSG(n,m))
            printf("WIN\n");
        else
            printf("LOSE\n");
    }
    return 0;
}
