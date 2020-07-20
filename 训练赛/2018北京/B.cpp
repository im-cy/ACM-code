#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 200010;
struct node
{
	ll x;
	int l;
}ans[sz];
string ins[251];
bool vis[251][1024];
int tong[251];
int len[sz];
int gets(int i)
{
	int j = 0;
	int in = getchar();
	while(in != '\n' && in != EOF)
	{
		ins[i][j++] = in;
		in = getchar();
	}
	len[i] = j;
	if(in == EOF)
		return -1;
	return j;
}
int n = 0;

ll check(int i,int j)
{
	ll ans = 0;
	int l = 0;
	int ei = i , ej = j;
	while(ins[ei][ej] >= '0' && ins[ei][ej] <= '9' && ej < len[ei])
	{
		ans = ans * 10 + ins[ei][ej] - '0';
		l ++;
		if(ej == len[ei] - 1 && ei < n - 1 && ins[ei+1][0] >= '0' && ins[ei+1][0] <= '9')
		{
			ei ++;
			ej = 0;
			vis[ei][ej] = 1;
		}
		else
		{
			ej ++;
			vis[ei][ej] = 1;
		}
	}
	if((j > 0 && ins[i][j-1] != ' ') || (ins[i][j] == '0' && l != 1))
		return -1;
	if(ej < len[ei] && ins[ei][ej] >= 'a' && ins[ei][ej] <= 'z')
	{
		return -1;
	}
	return ans;
}
int main()
{
	while(!cin.eof())
	{
		getline(cin,ins[n]);
		len[n] = ins[n].length();
		n ++;
	}
	n --;
	int tot = 0;
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < len[i] ; j ++)
		{
			if(!vis[i][j] && ins[i][j] >= '0' && ins[i][j] <= '9')
			{
				ll temp = check(i,j);
				if(temp != -1)
				{
					ans[++tot].x = temp;
					ans[tot].l = i;
				}
			}
		}
	}
	for(int i = 1 ; i <= tot ; i ++)
	{
		printf("%lld%c",ans[i].x, i==tot?'\n':' ');
		tong[ans[i].l] ++;
	}
	for(int i = 0 ; i < n ; i ++)
		printf("%d\n",tong[i]);
	return 0;
}
/*
151 48 99aa
123a a121
22
123aa 12
12
12
aaaaa 58
085
aabb9988
12
*/

