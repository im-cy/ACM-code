#include<bits/stdc++.h>
using namespace std;
const int sz = 200010;
int n;
int num[sz],vis[sz];
struct node
{
	int len;
	long long pos;
};
queue < node > q;
int maxnum[sz];
void bfs()
{
	while(!q.empty())
	{
		node f = q.front();
		q.pop();
		if(f.len == n)
		{
			continue;
		}
		if(num[f.pos] == maxnum[f.len])
		{
			if(vis[f.pos] == f.len)
				continue;
			vis[f.pos] = f.len; 
			node nxt = f;
			nxt.len ++;
			nxt.pos = (f.pos * f.pos + 1) % n;
			if(maxnum[nxt.len] <= num[nxt.pos])
			{
				maxnum[nxt.len] = num[nxt.pos];
				q.push(nxt);
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	int Casi = 0;
	while(T --)
	{
		scanf("%d",&n);
		int maxn = 0;
		for(int i = 0 ; i < n ; i ++)
		{
			char in = getchar();
			while(in < '0' || in > '9')
				in = getchar();
			num[i] = in - '0';
			maxn = max(num[i],maxn);
		}
		maxnum[1] = maxn;
		for(int i = 0 ; i < n ; i ++)
		{
			if(num[i] == maxn)
			{
				node nxt;
				nxt.len = 1;
				nxt.pos = i;
				q.push(nxt);
			}
		}
		printf("Case #%d: ",++Casi);
		
		bfs();
		while(!q.empty())
			q.pop();
		for(int i = 1 ; i <= n ; i ++)
			printf("%d",maxnum[i]);
		puts("");
		for(int i = 0 ; i < n + 5 ; i ++)
			maxnum[i] = -1;
		for(int i = 0 ; i < n + 5 ; i ++)
			vis[i] = -1;
	}
	return 0;
}

