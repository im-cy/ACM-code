#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int sz = 2000100;
deque < int > q;
int num[sz];
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1 ; i <= n ; i ++)
        scanf("%d",&num[i]);
    for(int i = 1 ; i <= k ; i ++)
    {
        while(!q.empty() && num[q.back()] < num[i])
            q.pop_back();
        q.push_back(i);
    }
    printf("%d\n",num[q.front()]);
    for(int i = k + 1 ; i <= n ; i ++)
    {
        while(!q.empty() && q.front() < i - k + 1)
            q.pop_front();
        while(!q.empty() && num[q.back()] < num[i])
            q.pop_back();
        q.push_back(i);
        printf("%d\n",num[q.front()]);
    }
    return 0;
}
