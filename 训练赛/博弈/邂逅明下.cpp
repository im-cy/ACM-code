#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(int n,int p,int q)
{
	int turn = 0;
	if(n%(p+q) == 0)
		return turn % 2;
	else if(n%(p+q) <= p)
		return (turn+1) % 2;
	else
		return turn % 2;	
}

int main()
{
	int n,p,q;
	while(scanf("%d%d%d",&n,&p,&q) != EOF)
	{
		if(check(n,p,q))
			puts("LOST");
		else
			puts("WIN");
	}
	return 0;
}
