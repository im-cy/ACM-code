#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int sz = 2000010;
struct Pair
{
	int p,d;
};
queue < Pair > q;
bool use[sz];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	Pair start;
	start.p = n;
	start.d = 0;
	q.push(start);
	use[n] = 1;
	while(!q.empty())
	{
		Pair f = q.front();
		q.pop();
		if(f.p == k)
		{
			printf("%d\n",f.d);
			return 0;
		}
		if(f.p*2 <= 4 * max(n,k) && !use[f.p*2])
		{
			use[f.p*2] = 1;
			Pair nxt = f;
			nxt.p = f.p * 2;
			nxt.d = f.d + 1;
			q.push(nxt);
		}
		if(f.p + 1 <= 4 * max(n,k) && !use[f.p+1])
		{
			use[f.p+1] = 1;
			Pair nxt = f;
			nxt.p = f.p + 1;
			nxt.d = f.d + 1;
			q.push(nxt);
		}
		if(f.p - 1 >= 0 && !use[f.p-1])
		{
			use[f.p-1] = 1;
			Pair nxt = f;
			nxt.p = f.p - 1;
			nxt.d = f.d + 1;
			q.push(nxt);
		}
	}
	return 0;
}

