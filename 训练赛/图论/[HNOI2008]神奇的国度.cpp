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
void color(int u)
{
	for(int i = 0 ; i < l[u].size() ; i ++)
	{
		int v = l[u][i];
		if(lab[v] == -1)
			continue;
		R[lab[v]] = u;
	}
	for(int i = 1 ; lab[u] == -1 ; i ++)
	{
		if(R[i] != u)
			lab[u] = i;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
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
	memset(R,-1,sizeof(R));
	memset(lab,-1,sizeof(lab));
	//SA为弦图的完美消除序列 
	for(int i = n ; i >= 1 ; i --)
		color(SA[i]);
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		ans = max(ans,lab[i]);
	printf("%d\n",ans);
	return 0;
}


