#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int sz = 505;
int n,m,cnt,Num[105][7],fa[sz],pre[sz];
int Mark[sz],mat[sz],vis[sz];
queue < int > q;
const int M = 300010;
int hed[M],nxt[M],l[M];
int tot = 1;
void build(int f,int t)
{
	l[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
int find(int x)
{
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
int getint()
{
	int x = 0;
    char ch = getchar();
    while(ch < '0' || '9' < ch)
		ch = getchar();
    while('0' <= ch && ch <= '9')
    {
    	x = x * 10 + ch - '0';
		ch = getchar();
    }
    return x;
}
void Build()
{
    n = getint();
	m = getint();
    while(m --)
    {
        int x = getint() , y = getint();
        build(x,y);
		build(y,x);
    }
}
void Augment(int p)
{
    while(p != -1)
    {
        int tmp = mat[pre[p]];
		mat[p] = pre[p];
        mat[pre[p]] = p;
		p = tmp;
    }
}
void Rebuild(int x,int y,int lca)
{
    while(find(x) != lca)
    {
        pre[x] = y;
        if(fa[x] == x)
			fa[x] = lca;
        if(fa[mat[x]] == mat[x])
			fa[mat[x]] = lca;
        if(Mark[mat[x]] == 1)
		{
			q.push(mat[x]);
			Mark[mat[x]] = 0;
		}
        y = mat[x];
		x = pre[y];
    }
}
void Link(int x,int y)
{
    cnt ++;
	int p = find(x);
    for(;;)
    {
        vis[p] = cnt;
		p = mat[p];
        if(p == -1)
			break;
		p = find(pre[p]);
    }
    int lca;
	p = find(y);
    for(;; p = find(pre[mat[p]]))
        if(vis[p] == cnt)
		{
			lca = p;
			break;
		}
    Rebuild(x,y,lca);
	Rebuild(y,x,lca);
}
int BFS(int s)
{
    for(int i = 1; i <= n ; i ++)
        fa[i] = i , Mark[i] = pre[i] = -1;
    while(!q.empty())
		q.pop();
	Mark[s] = 0;
	q.push(s);
    while(!q.empty())
    {
        int f = q.front();
		q.pop();
        for(int i = hed[f] ; i ; i = nxt[i])
        {
            int t = l[i];
            if(find(t) == find(f))
				continue;
            if(Mark[t] == -1)
            {
                Mark[t] = 1;
				pre[t] = f;
                if(mat[t] == -1)
                {
                    Augment(t);
					return 1;
                }
                Mark[mat[t]] = 0;
				q.push(mat[t]);
            }
            else if(Mark[t] == 0)
				Link(t,f);
        }
    }
    return 0;
}
int main()
{
    int ans = 0;
	Build();
    for(int i = 1 ; i <= n ; i ++)
		mat[i] = -1;
    for(int i = 1 ; i <= n ; i ++)
        if(mat[i] == -1)
			ans += BFS(i);
    cout << ans << endl;
    for(int i = 1; i <= n; i++)
        printf("%d%c",mat[i] == -1 ? 0 : mat[i],i == n ? '\n' : ' ');
    return 0;
}
