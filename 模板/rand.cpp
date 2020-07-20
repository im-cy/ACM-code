#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;


int main()
{
	freopen("data.txt","w",stdout);
	srand(time(0));
	int n = rand() % 1000;
	printf("%d\n",n);
	for(int i = 1 ; i <= n ; i ++)
	{
		printf("%d ",rand());
	}
	return 0;
}

