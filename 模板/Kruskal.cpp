#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 200010;
int f[sz];//并查集 
int n,m;
int find(int x)
{
    if(f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
struct gtnd
{
    int f,t,d;
}l[sz];//图的边存到 l[] 中 
bool cmp(gtnd swc,gtnd dc)
{
    return swc.d > dc.d; 
}
int Kruskal()
{
    int ans = 0;// ans 为最小生成树权值的总和 
    for(int i = 1 ; i <= n ; i ++)
        f[i] = i;
    sort(l+1,l+m+1,cmp);
    for(int i = 1 ; i <= m ; i ++)
    {
        int u = l[i].f , v = l[i].t;
        int fu = find(u) , fv = find(v);
        if(fu != fv)
        {
            f[fu] = fv;
            ans += l[i].d;
        }
    }
    return ans;
}
int main()
{


    return 0;
}
