#include<cctype>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define add(x,y,z) (e[++p]=(edg){x,y,z})
#define build(x,y,z) (ed[++k]=(edge){h[x],y,z},h[x]=k)
#define N 400005
#define M 400005
#define ll long long
using namespace std;
struct edg
{
	int x,y,z;
}e[M];
struct edge
{
	int next,to,dis;
}ed[N<<1];
int n,m,k,p,h[N],dep[N],ffa[N],fa[N][20],mx1[N][20],mx2[N][20];
bool f[M];
ll ans,ret=0x7fffffff;
char readc()
{
    static char buf[100000],*l=buf,*r=buf;
    if (l==r)
		r=(l=buf)+fread(buf,1,100000,stdin);
    if (l==r)
		return EOF; return *l++;
}
int read()
{
    int x = 0;
	char ch = readc();
    while(!isdigit(ch))
		ch=readc();
    while(isdigit(ch))
		x=(x<<3)+(x<<1)+(ch^48),ch=readc();
    return x;
}
int findfa(int x)
{
	if(ffa[x] == x)
		return x;
	return ffa[x]=findfa(ffa[x]);
}
bool cmp(edg a,edg b)
{
	return a.z<b.z;
}
void dfs(int x)
{
    for(int i = h[x]; i ; i = ed[i].next)
    {
    	int v = ed[i].to;
    	if(v != fa[x][0])
		{
            fa[v][0] = x , mx1[v][0] = ed[i].dis;
            dep[v] = dep[x] + 1 , dfs(v);
        }
    }
}
void Make()
{
    for(int j = 1 ; j <= 16 ; j ++)
        for(int i = 1 ; i <= n ; i ++)
		{
            fa[i][j] = fa[fa[i][j-1]][j-1];
            mx1[i][j] = max(mx1[i][j-1] , mx1[fa[i][j-1]][j-1]);
            if(mx1[i][j-1] == mx1[fa[i][j-1]][j-1])
                mx2[i][j] = max(mx2[i][j-1],mx2[fa[i][j-1]][j-1]);
            else
			{
                mx2[i][j] = min(mx1[i][j-1],mx1[fa[i][j-1]][j-1]);
                mx2[i][j] = max(mx2[i][j],mx2[fa[i][j-1]][j-1]);
                mx2[i][j] = max(mx2[i][j],mx2[i][j-1]);
            }
        }
}
void calc(int &x,int &m1,int &m2,int j)
{
    if(mx1[x][j]>m1)
		m2 = m1 , m1 = mx1[x][j];
    else if(mx1[x][j] < m1)
		m2 = max(m2,mx1[x][j]);
    m2 = max(m2,mx2[x][j]) , x = fa[x][j];
}
void LCA(int x,int y,int z)
{
    int m1 = 0 , m2 = 0;
    if(dep[x] < dep[y])
		swap(x,y);
    for(int j = 16 ; ~j ; j --)
        if(dep[fa[x][j]] >= dep[y])
			calc(x,m1,m2,j);
    if(x == y)
	{
		ret = min(ret,1ll*(z==m1?z-m2:z-m1));
		return;
	}
    for(int j = 16 ; ~j ; j --)
        if(fa[x][j] != fa[y][j])
            calc(x,m1,m2,j) , calc(y,m1,m2,j);
    calc(x,m1,m2,0) , calc(y,m1,m2,0);
    ret = min(ret,1ll*(z==m1?z-m2:z-m1));
}
int main()
{
    n = read(), m = read();
    for(int i = 1 ; i <= n ; i ++)
    	ffa[i] = i;
    for(int i = 1 ; i <= m ; i ++)
    {
    	int f,t,d;
    	f = read() , t = read() , d = read();
		add(f,t,d);
    }
    sort(e+1,e+m+1,cmp);
    int cnt = 0;
    for(int i = 1 ; i <= m ; i ++)
    {
    	int x = e[i].x , y = e[i].y , z = e[i].z;
    	int fx = findfa(x) , fy = findfa(y);
        if(fx != fy)
		{
            ffa[fx] = fy;
			ans += z;
			cnt ++;
            build(x,y,z) , build(y,x,z);
            f[i] = true;
			if(cnt == n-1)
				break;
        }
    }
    dep[1] = 1;
	dfs(1);
	Make();
    for(int i = 1 ; i <= m ; i ++)
        if(!f[i])
			LCA(e[i].x,e[i].y,e[i].z);
    printf("%lld\n",ret+ans);
	return 0;
}

