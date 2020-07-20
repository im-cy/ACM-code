#include <cstdio>  
#include <queue>  
#include <cstring>  
#include <iostream>  
#define sz 31  
#define N 65540  
using namespace std;  
int tot,nxt[N*4],point[N*4],v[N*4],tot1,nxt1[N*4],point1[N*4],v1[N*4],tot2,nxt2[N*4],point2[N*4],v2[N*4],n,in[N],ran[N],h[N];  
int f[N][sz],ans[N];  
void addline(int x,int y){++tot; nxt[tot]=point[x]; point[x]=tot; v[tot]=y;}  
void addline1(int x,int y){++tot1; nxt1[tot1]=point1[x]; point1[x]=tot1; v1[tot1]=y;}  
void addline2(int x,int y){++tot2; nxt2[tot2]=point2[x]; point2[x]=tot2; v2[tot2]=y;}  
void topsort()  
{  
    queue<int>q;  
    for (int i=1;i<=n;i++)  
      if (!in[i]) q.push(i);  
    int num=0;  
    while (!q.empty())  
    {  
        int now=q.front(); q.pop();  
        ran[++num]=now;  
        for (int i=point[now];i;i=nxt[i])  
        {  
            in[v[i]]--;  
            if (!in[v[i]]) q.push(v[i]);  
        }  
    }   
}  
int lca(int x,int y)  
{  
    if (h[x]<h[y]) swap(x,y);  
    int k=h[x]-h[y];  
    for (int i=0;i<sz;i++)  
      if ((k>>i)&1) x=f[x][i];  
    if (x==y) return x;  
    for (int i=sz-1;i>=0;i--)  
      if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];  
    return f[x][0];  
}  
void dfs(int now)  
{  
    for(int i=point2[now];i;i=nxt2[i])
      {
          dfs(v2[i]);
          ans[now]+=ans[v2[i]];
      }
    ans[now]++;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        while (x) {in[i]++;addline1(i,x);addline(x,i);scanf("%d",&x);}
    }
    topsort();  
    for(i=1;i<=n;i++)
    {
        int x=v1[point1[ran[i]]];
        for (j=point1[ran[i]];j;j=nxt1[j])
          x=lca(x,v1[j]);
        addline2(x,ran[i]);
        h[ran[i]]=h[x]+1;
        f[ran[i]][0]=x;
        for (j=1;j<sz;j++) f[ran[i]][j]=f[f[ran[i]][j-1]][j-1];
    }
    dfs(0);
    for (i=1;i<=n;i++) printf("%d\n",ans[i]-1);
}
