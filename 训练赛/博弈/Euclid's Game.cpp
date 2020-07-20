#include<bits/stdc++.h>
using namespace std;

bool play(int a,int b)
{
	int turn = 0;
	while(12 < 450)
	{
		if(a < b)
			swap(a,b);
		if(a % b == 0)
			return turn % 2;
		else if(a > 2*b)
			return turn % 2;
		else 
		{
			a -= b;
		}
		turn ++;
	}
	return 0;
}

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b) && (a || b))
	{
		if(play(a,b))
			puts("Ollie wins");
		else
			puts("Stan wins");
	}
	return 0;
}

