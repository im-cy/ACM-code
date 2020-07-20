#include<bits/stdc++.h>
using namespace std;
const int sz = 400010;
const int INF = 214748364;
vector <int> l[sz];
int n,q;
void build(int f,int t)
{
	l[f].push_back(t);
	l[t].push_back(f);
}
int read()
{
	int x = 0;
	char in = getchar();
	while(in < '0' || in > '9')
		in = getchar();
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in - '0';
		in = getchar();
	}
	return x;
}
int root,maxx[sz],size[sz],sum;
void calcsiz(int u,int fa)
{
	size[u] = 1;
	maxx[u] = 0;
	for(int i = 0 ; i < l[u].size() ; i ++)
	{
		int v = l[u][i];
		if(v == fa)
			continue;
		calcsiz(v,u);
		maxx[u] = max(maxx[u],size[v]);
		size[u] += size[v];
	}
	maxx[u] = max(maxx[u],sum-size[u]);
	if(maxx[u] < maxx[root])
		root = u;
}
void findroot()
{
	root = 0;
	maxx[root] = INF;
	sum = n;
	calcsiz(1,-1);
	calcsiz(root,-1);
}
int par[sz][32],deep[sz];
void dfs(int u,int fa,int dep)
{
	par[u][0] = fa;
	deep[u] = dep;
	for(int i = 0 ; i < l[u].size() ; i ++)
	{
		int v = l[u][i];
		if(v != fa)
			dfs(v,u,dep+1);
	}
}
int lca(int u,int v)
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
		u = par[u][0],v = par[v][0];
	return u;
}
void lca_init()
{
	dfs(root,0,1);
	for(int i = 1 ; i <= 31 ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			par[j][i] = par[par[j][i-1]][i-1];
}
vector <int> lab,lcd;
bool check0(int a,int b,int c)
{
	if(deep[a] < deep[b])
		swap(a,b);
	if(lca(a,c) != c)
		return false;
	if(lca(c,b) != b)
		return false;
	return true;
}
bool check(int a,int b,int c)
{
	int d=lca(a,b);
	return check0(a,d,c)||check0(b,d,c);
}
int point[101];
int solve(int a,int b,int c,int d)
{
	lab.clear() , lcd.clear();
	lab.push_back(a) , lab.push_back(b) ;
	lcd.push_back(c) , lcd.push_back(d);
	point[0] = 0;
	point[++point[0]] = lca(a,b);
	point[++point[0]] = lca(a,c);
	point[++point[0]] = lca(a,d);
	point[++point[0]] = lca(b,c);
	point[++point[0]] = lca(b,d);
	point[++point[0]] = lca(c,d);
	for(int j = 1 ; j <= point[0] ; j ++)
		for(int i = 0 ; i < lab.size()-1; i ++)
			if(point[j] != lab[i] && point[j] != lab[i+1] && check(lab[i],lab[i+1],point[j]))
			{
				lab.insert(lab.begin()+i+1,point[j]);
				break;
			}
	for(int j = 1 ; j <= point[0] ; j ++)
		for(int i = 0 ; i < lcd.size()-1; i ++)
			if(point[j] != lcd[i] && point[j] != lcd[i+1] && check(lcd[i],lcd[i+1],point[j]))
			{
				lcd.insert(lcd.begin()+i+1,point[j]);
				break;
			}
	int ans = 0;
	for(int i = 0 ; i < lab.size() ; i ++)
	{
		int temp = 0;
		for(int j = 0 ; j < lcd.size() ; j ++)
		{
			if(lab[i] == lcd[j])
			{
				temp = 1;
				for(int k = 1 ; ; k ++)
				{
					if(i + k >= lab.size() || j + k >= lcd.size() || lab[i+k] != lcd[j+k])
						break;
					temp += abs(deep[lab[i+k]]-deep[lab[i+k-1]]);
				}
			}
			ans = max(ans,temp);
		}
	}
	reverse(lcd.begin(),lcd.end());
	for(int i = 0 ; i < lab.size() ; i ++)
	{
		int temp = 0;
		for(int j = 0 ; j < lcd.size() ; j ++)
		{
			if(lab[i] == lcd[j])
			{
				temp = 1;
				for(int k = 1 ; ; k ++)
				{
					if(i + k >= lab.size() || j + k >= lcd.size() || lab[i+k] != lcd[j+k])
						break;
					temp += abs(deep[lab[i+k]]-deep[lab[i+k-1]]);
				}
			}
			ans = max(ans,temp);
		}
	}
	return ans;
}
int main()
{
	n = read() , q = read();
	for(int i = 1 ; i < n ; i ++)
	{
		int f = read() , t = read();
		build(f,t);
	}
	findroot();
	lca_init();
	for(int i = 1 ; i <= q ; i ++)
	{
		int a = read() , b = read() , c = read() , d = read();
		int ans = solve(a,b,c,d);
		printf("%d\n",ans);
	}
	return 0;
}


