#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 2010;
int num[sz];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d",&num[i]), num[i] += 500000;
	printf("%d\n",n+1);
	printf("1 %d 500000\n",n);
	for(int i = 1 ; i <= n ; i ++)
	{
		printf("2 %d %d\n",i,num[i]-i);
	}
	return 0;
}

