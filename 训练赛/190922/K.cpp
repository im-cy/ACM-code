#include<bits/stdc++.h>
using namespace std;

int main()
{
	srand(time(0));
	for(int i = 1 ; i <= 50000 ; i ++)
	{
		int op = rand() % 4;
		if(op == 0)
			putchar('U');
		else if(op == 1)
			putchar('D');
		else if(op == 2)
			putchar('L');
		else
			putchar('R');
	}
	return 0;
}

