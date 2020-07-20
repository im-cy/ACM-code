#include<bits/stdc++.h>
using namespace std;
const int asz = 30;
const int bsz = 30;
int n = 5,r;
int main()
{
	srand(time(0));
	r = rand() % asz + 1;
	printf("%d %d\n",n,r);
	for(int i = 1 ; i <= n ; i ++)
	{
		int a = rand()%asz + 1;
		int b = rand()%bsz;
		int f = rand() % 2;
		if(f)
			b *= -1;
		printf("%d %d\n",a,b);
	}
	return 0;
}

