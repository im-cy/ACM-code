
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
int n, m, label[10005], R[10005], SA[10005];
vector<int> G[10005];
priority_queue<pair<int, int> > q;
void Color(int u) 
{
	int i, v;
	for(i=0;i<G[u].size();i++)
	{
		v = G[u][i];
		if(label[v]==-1)
			continue;
		R[label[v]] = u;
	}
	for(i=1;label[u]==-1;i++)
	{
		if(R[i]!=u)
			label[u] = i;
	}
}
int main(void)
{
	int i, u, v, id, now, ans;
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		while(q.empty()==0)
			q.pop();
		for(i=1;i<=n;i++)
			G[i].clear();
		while(m--)
		{
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		memset(R, -1, sizeof(R));
		memset(label, 0, sizeof(label));
		for(i=1;i<=n;i++)
			q.push(make_pair(0, i));
		for(id=n;id>=1;)
		{
			now = q.top().second;
			q.pop();
			if(R[now]!=-1)
				continue;
			SA[id] = now;
			R[now] = id--;
			for(i=0;i<G[now].size();i++)
			{
				u = G[now][i];
				if(R[u]!=-1) 
					continue;
				label[u]++;
				q.push(make_pair(label[u], u));
			}
		}
		memset(R, -1, sizeof(R));
		memset(label, -1, sizeof(label));
		
		for(i=n;i>=1;i--)
			Color(SA[i]);
		puts("lab");
		for(int i = 1 ; i <= n ; i ++)
			printf("%d ",label[i]);
		puts("");
		ans = 0;
		for(i=1;i<=n;i++)
			ans = max(ans, label[i]);
		printf("%d\n", ans);
	}
	return 0;
}

