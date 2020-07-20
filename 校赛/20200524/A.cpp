#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 200100;
//				  1	   3    4    6    8    9    11
string tb[56] = {"A1","B1","C1","D1","E1","F1","G1",
//				13   15    16   18  20    21   23 
			   "A2","B2","C2","D2","E2","F2","G2",
// 				25   27    28   30   32   33  35 
			   "A3","B3","C3","D3","E3","F3","G3",
//			 	37   39   40
			   "A4","B4","C4","D4","E4","F4","G4",
			   "A5","B5","C5","D5","E5","F5","G5",
			   "A6","B6","C6","D6","E6","F6","G6",
			   "A7","B7","C7","D7","E7","F7","G7",
			   "A8","B8","C8","D8","E8","F8","G8"};
int block[11] = {10,22,34,46,58,214748364};
ll num[sz];
char ins[11];
int n;
int main()
{
	int cnt = -1;
	for(int i = 0 ; i <= 55 ; i ++)
	{
		if(i%7 == 2 || i % 7 == 5)
		{
			cnt ++;
		}
		else
		{
			cnt += 2;
		}
		num[i] = cnt;
	}
	scanf("%d",&n);
	ll ans = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%s",ins);
		int a = ins[0] - 'A';
		int b = ins[1] - '1';
		int pos = b * 7 + a;
		int temp = num[pos];
		if(strlen(ins) == 3)
		{
			if(ins[2] == '#')
			{
				temp ++; 
			}
			else
			{
				temp --;
			}
		}
		int block_ = 0;
		for(int j = 0 ; j <= 5 ; j ++)
		{
			if(block[j] > temp)
			{
				block_ = block[j-1];
				break;
			}
		}
		ans += temp - block_;
	}
	printf("%lld\n",ans);
	return 0;
}

