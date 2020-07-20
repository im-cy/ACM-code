#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		if(n%(m+1))
			puts("first");
		else
			puts("second");
	}
	
	return 0;
}

