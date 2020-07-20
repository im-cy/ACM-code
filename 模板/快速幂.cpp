#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ksm(int x,int p)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return x;
    if(p == 2)
        return x * x;
    int temp = ksm(x,p/2);
    if(p % 2 == 1)
        return temp * temp * x;
    if(p % 2 == 0)
        return temp * temp;
}
int main()
{
    int x,p;
    while(scanf("%d%d",&x,&p))
        printf("%d\n",ksm(x,p));
    return 0;
}
