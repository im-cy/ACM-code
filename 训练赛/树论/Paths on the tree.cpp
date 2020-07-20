#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 200010;
int hed[sz],nxt[sz];//dist[i][j]��¼�˵� i ���ڵ������� 2^j ���ߵıߵ�Ȩֵ�� 
int par[sz][32],deep[sz];//par[i][j]��¼�˵� i ���ڵ������� 2^j �����Ե���Ľڵ㣬deep��¼����� 
int tot = 1;//�ߵ����� 
int l[sz];
int n,m;
bool vis[sz];
struct node
{
	int u,v,lcauv;
}ins[sz];
void init()
{
	memset(ins,0,sizeof(ins));
	memset(vis,0,sizeof(vis));
	memset(l,0,sizeof(l));
	memset(par,0,sizeof(par));
	memset(deep,0,sizeof(deep));
	memset(hed,0,sizeof(hed));
	memset(nxt,0,sizeof(nxt));
	tot = 1;
}
bool cmp(node a,node b)
{
	return deep[a.lcauv] > deep[b.lcauv];
}
void build(int f,int t) // ��һ�� f�㵽 t ��ȨֵΪ d ������� 
{
    l[tot] = t;
    nxt[tot] = hed[f];
    hed[f] = tot ++;
}
void dfs(int u,int fa,int dep)//Ԥ������ȡ�ÿ���ڵ�ĸ��׽ڵ㡢��Ȩ 
{
    par[u][0] = fa;
    deep[u] = dep;
    for(int i = hed[u] ; i ; i = nxt[i])
    {
        int v = l[i];
        if(v != fa)
            dfs(v,u,dep+1);
    }
}
int lca(int u,int v)//������ u v ����ľ��� 
{
    if(deep[u] < deep[v])
        swap(u,v);
    for(int i = 31 ; i >= 0 ; i --)
        if(deep[par[u][i]] >= deep[v])
            u = par[u][i];
    for(int i = 31 ; i >= 0 ; i --)
        if(par[u][i] != par[v][i])
            u = par[u][i] , v = par[v][i];
    if(u != v)
        u = par[u][0] , v = par[v][0];
    return u; // ��ʱ,�� u v ������ͨ(��������ɭ��) u == v ���Ҵ�ʱ�� u v Ϊѯ��ʱ u v ������������� 
}
void dfs1(int u)
{
	vis[u] = 1;
	for(int i = hed[u] ; i ; i = nxt[i])
	{
		int v = l[i];
		if(vis[v] || deep[v] < deep[u])
			continue;
		dfs1(v);
	}
}
//n�������������m��·����ѡ�������ܶ��·����·���䲻�����ص� 
int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
    	init();
    	for(int i = 1 ; i < n ; i ++)//���Ŵ� 1 ��ʼ
	    {
	        int f,t;
	        scanf("%d%d",&f,&t);
	        build(f,t);
	        build(t,f);//���� 
	    }
	    dfs(1,0,1);//Ԥ���� 
	    for(int i = 1 ; i <= 31 ; i ++)
	        for(int j = 1 ; j <= n ; j ++)
	            par[j][i] = par[par[j][i-1]][i-1];//����˼��
	    for(int i = 1 ; i <= m ; i ++)
	    {
	    	scanf("%d%d",&ins[i].u,&ins[i].v);
	    	ins[i].lcauv = lca(ins[i].u,ins[i].v);
	    }
	    sort(ins+1,ins+m+1,cmp);
	    int ans = 0;
	    for(int i = 1 ; i <= m ; i ++)
	    {
	    	if(vis[ins[i].u] || vis[ins[i].v])
	    		continue;
	    	ans ++;
	    	dfs1(ins[i].lcauv);
	    }
	    printf("%d\n",ans);
    }
    return 0;
}
