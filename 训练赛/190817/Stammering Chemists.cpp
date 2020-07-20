#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<ctime>
#include<cmath>
#include<set>
#include<map>
#define ull unsigned long long
#define ll long long
#define INF 10000
using namespace std;
int n = 6,m;
const int N = 2010;
int max_g,g[17];
vector <int> edge[N];
int size[N];
ull Hash[N],RD[N];
void build(int f,int t)
{
	edge[f].push_back(t);
}
void dfs(int u,int fa)
{
	size[u] = 1;
	int tmp = 0;
	for(int i = 0 ; i < edge[u].size() ; i ++)
	{
		int v = edge[u][i];
		if(v == fa) continue;
		dfs(v,u);
		tmp = max(tmp,size[v]+1);
		size[u] += size[v];
	}
	tmp = max(tmp,n-size[u]+1);
	if(tmp == max_g){
		g[++g[0]] = u;
	}
	else if(tmp < max_g)
	{
		g[0] = 1;
		g[g[0]] = u;
		max_g = tmp;
	}
	return ;
}
void dfs_hash(int u,int fa)
{
	Hash[u] = 1;
	size[u] = 1;
	for(int i = 0 ; i < edge[u].size() ; i ++)
	{
		int v = edge[u][i];
		if(v == fa) continue;
		dfs_hash(v,u);
		Hash[u] += Hash[v] ^ RD[size[v]];
		size[u] += size[v];
	}
	Hash[u] *= RD[n-size[u]+1];
}
map < ull,string > MP;
int f[7][7];
string nam[5] = {"n-hexane","2-methylpentane","3-methylindole","2,3-dimethylbutane","2,2-dimethylbutane"};
void init()
{
	MP.clear();
	for(int i = 1 ; i <= 5 ; i ++)
	{
		for(int j = 0 ; j <= 6 ; j ++)
			edge[j].clear();
		memset(f,0,sizeof(f));
		if(i == 1)
			f[1][2] = f[2][3] = f[3][4] = f[4][5] = f[5][6] = 1;
		else if(i == 2)
			f[1][2] = f[2][3] = f[3][4] = f[4][5] = f[2][6] = 1;
		else if(i == 3)
			f[1][2] = f[2][3] = f[3][4] = f[4][5] = f[3][6] = 1;
		else if(i == 4)
			f[1][2] = f[2][3] = f[3][4] = f[2][5] = f[3][6] = 1;
		else if(i == 5)
			f[1][2] = f[2][3] = f[3][4] = f[2][5] = f[2][6] = 1;
		int root = 1;
		for(int j = 1 ; j <= 6 ; j ++)
		{
			for(int k = j + 1 ; k <= 6 ; k ++)
				if(f[j][k])
				{
					build(j,k),build(k,j);
				}
		}
		max_g = INF;
		g[0] = 0;
		dfs(root,0);
		ull hs = 1;
		for(int j = 1 ; j <= g[0] ; j ++)
		{
			dfs_hash(g[j],0);
			hs *= Hash[g[j]];
		}
		MP[hs] = nam[i-1];
	}
}

int main()
{
	srand(time(0));
	for(int i = 0 ; i < N ; i ++)
		RD[i] = (ull)rand()*rand();
	
	init();
	int T;
	scanf("%d",&T);
	{
//		map < ull,int > MP;
		for(int i = 1 ; i <= T ; i ++)
		{
			for(int j = 0 ; j <= 6 ; j ++)
				edge[j].clear();
			int root = 1;
			for(int j = 1 ; j < 6 ; j ++)
			{
				int f,t;
				scanf("%d%d",&f,&t);
				build(f,t);
				build(t,f);
			}
			max_g = INF;
			g[0] = 0;
			dfs(root,0);
			ull hs = 1;
			for(int j = 1 ; j <= g[0] ; j ++)
			{
				dfs_hash(g[j],0);
				hs *= Hash[g[j]];
			}
			puts(MP[hs].c_str());
		//	printf("%s\n",MP[hs]);
		}
	}
	return 0;
}
