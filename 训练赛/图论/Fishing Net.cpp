#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int sz = 200010;
vector < int > l[sz];
void build(int f,int t)
{
	l[f].push_back(t);
	l[t].push_back(f);
}
int R[sz],SA[sz],lab[sz],col[sz];
priority_queue <pair<int,int> > q;
int n,m;
bool T[sz];
vector < int > p;

bool check()
{
	for(int i = n - 1 ; i >= 1 ; i --)
	{
		int u = SA[i];
		p.push_back(SA[i+1]);
		for(int j = 0 ; j < l[u].size() ; j ++)
		{
			int v = l[u][j];
			T[v] = 1;
		}
		for(int j = 0 ; j < p.size() ; j ++)
		{
			if(!T[p[j]])
				return false;
		}
		for(int j = 0 ; j < l[u].size() ; j ++)
		{
			int v = l[u][j];
			T[v] = 0;
		}
	}
	return true;
}
int main()
{
	while(scanf("%d%d",&n,&m) && (n || m))
	{
		p.clear();
		for(int i = 1 ; i <= n + 5 ; i ++)
			l[i].clear();
		memset(SA,0,sizeof(SA));
		while(!q.empty())
			q.pop();
		
		for(int i = 1 ; i <= m ; i ++)
		{
			int f,t;
			scanf("%d%d",&f,&t);
			build(f,t);
		}
		memset(R,-1,sizeof(R));
		memset(lab,0,sizeof(lab));
		for(int i = 1 ; i <= n ; i ++)
		{
			q.push(make_pair(0,i));
		}
		for(int i = n ; i >= 1;)
		{
			int now = q.top().second;
			q.pop();
			if(R[now] != -1)
				continue;
			SA[i] = now;
			R[now] = i --;
			for(int j = 0 ; j < l[now].size() ; j ++)
			{
				int v = l[now][j];
				if(R[v] != -1)
					continue;
				lab[v] ++;
				q.push(make_pair(lab[v],v));
			}
		}
		bool ans = check();
		if(ans)
			puts("Perfect");
		else
			puts("Imperfect");
		puts("");
	}
	return 0;
}
/*
4 4
1 2
2 3
3 4
4 1
3 3
1 2
2 3
3 1
0 0
*/



