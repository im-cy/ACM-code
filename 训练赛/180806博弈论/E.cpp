#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,p,sg[(1<<20)+5],n,m;
int Check(int k,int p)
{
    for (int i = p - 1 ; i >= 0 ; i --)
        if (!(k & (1 << i)))
			return k ^ (1 << i) ^ (1 << p);
    return -1;
}

int dfs(int k)
{
    if(sg[k]!= -1)
		return sg[k];
    bool vis[25] = {0};
    for(int i = 19 ; i > 0 ; i --)
		if(k & (1 << i))
		{
       		int t = Check(k,i);
    		if(t != -1)
				vis[dfs(t)] = 1;
		}
    for(int i = 0 ; i < 25 ; i ++)
		if(!vis[i])
			return sg[k] = i;
}
int main()
{
    memset(sg,-1,sizeof(sg));
    int k = (1 << 20) -1;
    sg[k] = 0;
    for(int i = 0 ; i < 20 ; i ++)
    {
        k = (1 << (20 - i - 1)) ^ k;
        sg[k] = 0;
    }
    k = (1 << 20) - 1;
    for(int i = 0 ; i < 20 ; i ++)
    {
        k ^= (1 << i);
        dfs(k);
    }
    scanf("%d",&T);
    while (T--)
    {
        int ans = 0;
        scanf("%d",&n);
        for (int i = 0 ; i < n ; i ++)
        {
            scanf("%d",&m);
			k = 0;
            for(int j = 0 ; j < m ; j ++)
            {
                scanf("%d",&p);
                k = k ^ (1 << (20 - p));
            }
            ans ^= sg[k];
        }
        if(ans)
			printf("YES\n");
        else
			printf("NO\n");
    }
    return 0;
}
