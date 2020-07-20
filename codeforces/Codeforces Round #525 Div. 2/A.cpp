#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


int main()
{
	int n;
	scanf("%d",&n);
	if(n == 1)
		puts("-1");
	else
		printf("%d %d\n",n,n);
	return 0;
}

