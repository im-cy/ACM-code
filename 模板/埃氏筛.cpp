#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool is_prime[2000100];
int main()
{
    int n;
    scanf("%d",&n);
    is_prime[1] = 1;
    for(int i = 2 ; i <= n ; i ++)
    {
        if(!is_prime[i])
            for(int j = i * i ; j <= n ; j += i)
                is_prime[j] = 1;
    }
    return 0;
} 
