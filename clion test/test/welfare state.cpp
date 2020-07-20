#include<bits/stdc++.h>
using namespace std;
const int sz = 200100;
struct node
{
    int op;
    int p,x;
}ins[sz];
int a[sz];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    int q;
    cin >> q;
    for(int i = 1 ; i <= q ; i ++)
    {
        scanf("%d",&ins[i].op);
        if(ins[i].op == 1)
            scanf("%d%d",&ins[i].p,&ins[i].x);
        else
            scanf("%d",&ins[i].x);
    }
    int maxn = 0;
    for(int i = q ; i >= 1 ; i --)
    {
        if(ins[i].op == 2)
            maxn = max(maxn,ins[i].x);
        else
            ins[i].x = max(maxn,ins[i].x);
    }
    for(int i = 1 ; i <= n ; i ++)
        a[i] = max(maxn,a[i]);
    for(int i = 1 ; i <= q ; i ++)
    {
        if(ins[i].op == 1)
            a[ins[i].p] = ins[i].x;
    }
    for(int i = 1 ; i <= n ; i ++)
        printf("%d ",a[i]);

    return 0;
}
