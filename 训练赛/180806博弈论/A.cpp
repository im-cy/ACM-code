#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n) && n)
	{
		if(n > 2)
			puts("Bob");
		else
			puts("Alice");
	}
	return 0;
}
