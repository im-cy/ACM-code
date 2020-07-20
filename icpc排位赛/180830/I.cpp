#include <iostream>
#include <cstdio>
using namespace std;
char c[1100000];
int s[1100000];
int naive_ans[1000100];
int ques[1000100];
int main()
{
    int n, m, x;
    scanf("%s", c + 1);
    int cut = 0;
    for(int i = 1; c[i] != 0; i ++)
    {
        n = i;
        s[i] = s[i - 1] + ((c[i] - '0') ^ 1);
        if(c[i] == '0')
        	cut ++;
    }
    scanf("%d", &m);
    int max_m = 0;
    for(int i = 1 ; i <= m ; i ++)
    	scanf("%d",&ques[i]) , max_m = max(max_m,ques[i]);
    for(int i = 0; i <= max_m ; i ++)
    {
        int p = 1, q = 0, sum = 0, ans = 0;
        while(q <= n)
        {
           // cout << "fuck " << p << " " << q << " " << sum << " " << s[q] - s[p - 1] << endl;
            ans = max(ans, s[q] - s[p - 1]);
            if(sum <= i)
            {
                q ++;
                sum += c[q] - '0';
            }
            while(sum > i)
            {
                sum -= c[p] - '0';
                p ++;
            }
        }
        naive_ans[i] = ans;
    }
    for(int i = 1 ; i <= max_m ; i ++)
    {
    	naive_ans[i] = max(naive_ans[i],naive_ans[i-1]+1);
    }
    for(int i = 1 ; i <= m ; i ++)
    {
    	printf("%d\n",min(naive_ans[ques[i]],cut));
    }
    return 0;
}

