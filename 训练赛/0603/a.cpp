#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int sz = 200100;
int nxt[sz];
void getnxt(char s[])
{
    nxt[0] = nxt[1] = 0;
    int l = strlen(s);
    for(int i = 1;i < l;i ++)
    {
        int j = nxt[i];
        while(j && s[i] != s[j]) j = nxt[j];
        nxt[i + 1] = s[i] == s[j] ? j + 1 : 0;
    }
}
char ins[sz];
int dp[sz];
int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		int n;
		memset(ins,0,sizeof(ins));
		memset(dp,0,sizeof(dp));
		memset(nxt,0,sizeof(nxt));
		scanf("%d",&n);
		scanf("%s",ins);
		getnxt(ins);
		for(int i = 1 ; i <= n ; i ++)
			dp[i] = dp[nxt[i]] + 1;
//		for(int i = 1 ; i <= n ; i ++)
//			printf("%d ",dp[i]);
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++)
			ans += dp[i] % 10007 , ans %= 10007;
		printf("%d\n",ans);
	}
	
	return 0;
}
