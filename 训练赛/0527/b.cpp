#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct gtnd
{
    int num,v;
}ins[20];
int dp[100010];
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n) != EOF)
    {
    	for(int i = 1 ; i <= n ; i ++)
            scanf("%d%d",&ins[i].num,&ins[i].v);
    	if(!m || !n)
    	{
    		puts("0");
    		continue;
    	}
    	memset(dp,0,sizeof(dp));
        dp[0] = 1;
        int maxn = 0;
        for(int i = 1; i <= n ; i ++)
            for(int j = maxn ; j >= 0 ; j --)
                if(dp[j])
                    for(int k = 1 ; k <= ins[i].num ; k ++)
                    {
                        int temp = j + k * ins[i].v;
                        if(temp > m)
	                        continue;
                        dp[temp] = 1;
                        if(temp > maxn)
                        	maxn = temp;
                    }
        printf("%d\n",maxn);
    }
    return 0;
}

