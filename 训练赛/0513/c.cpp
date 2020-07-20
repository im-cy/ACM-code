#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 201;
int dp[sz][sz];
char ins[sz];
int main ()
{
    while(scanf("%s", ins + 1) != EOF)
    {
        memset(dp,0,sizeof(dp));
        if(ins[1] == 'e')
			break;
        int len = strlen(ins + 1);
        for(int i = 1; i <= len; i ++)
            for(int j = 1; j <= len - i + 1 ; j ++)
            {
                int k = j + i - 1;
                if((ins[j] == '(' && ins[k] == ')') || (ins[j] == '[' && ins[k] == ']'))
                    dp[j][k] = dp[j+1][k-1] + 2;
                for(int l = j ; l < k ; l ++)
                    dp[j][k] = max(dp[j][k], dp[j][l] + dp[l+1][k]);
            }
        printf("%d\n", dp[1][len]);
    }
    return 0;
}
