#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define INF 1e9+7
using namespace std;
const int sz = 2e5+9;
const ll M=1e9+7;
int size[sz];
int minn[sz];
struct node
{
	int l,r;
}tree[sz];
int n;
int read()
{
	int x = 0;
	char in = getchar();
	while(in < '0' || in > '9')
		in = getchar();
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in  - '0';
		in = getchar();
	}
	return x;
}
void dfs(int u)
{
	size[u] = 1;
	minn[u] = u;
	if(tree[u].l)
	{
		dfs(tree[u].l);
		minn[u] = min(minn[u],minn[tree[u].l]);
	}
	if(tree[u].r)
	{
		dfs(tree[u].r);
		minn[u] = min(minn[u],minn[tree[u].r]);
	}
	size[u] += size[tree[u].l] + size[tree[u].r];
}
int cnt;
ll ans[sz];
/*
void ddfs(int u)
{
	if(!tree[u].l && !tree[u].r)
	{
		ans[u] = ++ cnt;
		return ;
	}
	else if(!tree[u].l)
	{
		if(minn[u] < minn[tree[u].r])
		{
			ans[u] = ++ cnt;
			ddfs(tree[u].r);
		}
		else
		{
			ddfs(tree[u].r);
			ans[u] = ++ cnt;
		}
	}
	else if(!tree[u].r)
	{
		if(minn[u] < minn[tree[u].l])
		{
			ans[u] = ++ cnt;
			ddfs(tree[u].l);
		}
		else
		{
			ddfs(tree[u].l);
			ans[u] = ++ cnt;
		}
	}
	else if(minn[tree[u].l] > minn[u] && minn[tree[u].r] > minn[u])
	{
		if(size[tree[u].l] < size[tree[u].r])
		{
			ddfs(tree[u].l);
			ans[u] = ++ cnt;
			ddfs(tree[u].r);
		}
		else if(size[tree[u].l] == size[tree[u].r])
		{
			if(minn[tree[u].l] < minn[tree[u].r])
			{
				ddfs(tree[u].l);
				ans[u] = ++ cnt;
				ddfs(tree[u].r);
			}
			else
			{
				ddfs(tree[u].r);
				ans[u] = ++ cnt;
				ddfs(tree[u].l);
			}
		}
		else
		{
			ddfs(tree[u].r);
			ans[u] = ++ cnt;
			ddfs(tree[u].l);
		}
	}
	else if(minn[tree[u].l] < minn[u] && minn[tree[u].r] < minn[u])
	{
		if(minn[tree[u].l] < minn[tree[u].r])
		{
			ddfs(tree[u].l);
			ans[u] = ++ cnt;
			ddfs(tree[u].r);
		}
		else
		{
			ddfs(tree[u].r);
			ans[u] = ++ cnt;
			ddfs(tree[u].l);
		} 
	}
	else
	{
		if(minn[tree[u].l] < minn[u])
		{
			ddfs(tree[u].l);
			ans[u] = ++ cnt;
			ddfs(tree[u].r);
		}
		else
		{
			ddfs(tree[u].r);
			ans[u] = ++ cnt;
			ddfs(tree[u].l);
		}
	}
}*/
void ddfs(int u)
{
	bool swaped = 0;
	if(!tree[u].l)
		swaped = (u < minn[tree[u].r]);
	else if(!tree[u].r)
		swaped = (u > minn[tree[u].l]);
	else if(minn[tree[u].l] > u && minn[tree[u].r] > u)
	{
		if(size[tree[u].l] == size[tree[u].r])
			swaped = (minn[tree[u].l] < minn[tree[u].r]);
		else
			swaped = (size[tree[u].l] < size[tree[u].r]);
	}
	else
		swaped = (minn[tree[u].l] < minn[tree[u].r]);
	if(swaped)
	{
		if(tree[u].l)
			ddfs(tree[u].l);
		ans[u] = ++ cnt;
		if(tree[u].r)
			ddfs(tree[u].r);
	}
	else
	{
		if(tree[u].r)
			ddfs(tree[u].r);
		ans[u] = ++ cnt;
		if(tree[u].l)
			ddfs(tree[u].l);
	}
}
bool is_root[sz];
int root;
int main()
{
	int T = read();
	while(T --)
	{
		cnt = 0;
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i ++)
			is_root[i] = 0,minn[i] = INF;
			
		for(int i = 1 ; i <= n ; i ++)
		{
			int f = read() , t = read();
			tree[i].l = f , tree[i].r = t;
			is_root[f] = 1;
			is_root[t] = 1;
		}
		for(int i = 1 ; i <= n ; i ++)
			if(!is_root[i])
			{
				root = i;
				break;
			}
		dfs(root);
		ddfs(root);
		ll B = 233;
		ll value = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			value = (value + (ans[i]^i)*B%M)%M;
			B = B * 233 % M;
		}
		printf("%lld\n",value);
	}
	return 0;
}
