#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[201];
char check[2];
char s_temp[201];
int t;
int main()
{
	scanf("%d",&t);
	while(t --)
	{
		int ans = 20001000;
		scanf("%s",s+1);
		int n = strlen(s+1);
		for(int a = 1 ; a <= 26 ; a ++)
		{
			for(int b = 1 ; b <= 26 ; b ++)
			{
				int temp = 0;
				check[0] = a + 'a' - 1;
				check[1] = b + 'a' - 1;
				for(int i = 1 ; i <= n ; i ++)
				{
					if(check[i%2] != s[i])
						temp ++;
				}
				ans = min(ans,temp);
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
