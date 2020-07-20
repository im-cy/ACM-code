#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b) != EOF && (a || b))
	{
		if(a < b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		int is_win = 0;
		while(b)
		{
			if(!(a % b) || a - b > b)
				break;
			else
			{
				int temp = a;
				a = b;
				b = temp - b;
				is_win ^= 1;
			}
		}
		if(!is_win)
			puts("Stan wins");
		else
			puts("Ollie wins");
	}
	
	return 0;
}

