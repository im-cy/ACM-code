#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    long long n,b;
    long long a = 9973;
    scanf("%d",&t);  
    for(int i = 0 ; i < t ; i ++)
	{
        scanf("%lld%lld",&n,&b);
        for(int j = 0 ; j < a ; j ++)
            if((j * b - n) % a == 0)
			{
                printf("%d\n", j);
                break;
            }
    }
    return 0;
}

