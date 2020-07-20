#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll x = 0 , f = 1;
	char in = getchar();
	while(in < '0'  || in > '9')
	{
		if(in == '-')
			f = -1;
		in = getchar();
	}
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in - '0';
		in = getchar();
	}
	return x * f;
}
const int sz = 200010;
ll num[sz];
char ins[sz];
stack <char> s;
int n;
int check(int l,int r)
{
	swap(ins[l],ins[r]);
	while(!s.empty())
		s.pop();
	for(int i = 1 ; i <= n ; i ++)
	{
		if(ins[i] == '(')
			s.push(ins[i]);
		else
		{
			if(s.empty())
				return -1;
			else
				s.pop();
		}
	}
	if(!s.empty())
		return -1;
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(ins[i] == '(')
			s.push(ins[i]);
		else
			s.pop();
		if(!s.size())
			ans ++;
	}
	return ans;
}
int main()
{
	n = read();
	int tot = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		char in = getchar();
		while(in != '(' && in != ')')
			in = getchar();
		if(in == '(')
			break;
		tot ++;
	}
	int ss = 1;
	if(tot != n)
	{
		ins[1] = '(';
		ss ++;
	}
		
	for(int i = ss ; i <= n - tot ; i ++)
	{
		char in = getchar();
		while(in != '(' && in != ')')
			in = getchar();
		ins[i] = in;
	}
	for(int i = n-tot+1 ; i <= n ; i ++)
		ins[i] = ')';
	int ans = 0;
	int l = 1 , r = 1;
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = i + 1 ; j <= n ; j ++)
		{
			int temp = check(i,j);
			swap(ins[i],ins[j]);
			if(temp > ans)
			{
				ans = temp;
				l = i , r = j;
			}
		}
	}
	l = l + tot;
	r = r + tot;
	while(l > n)
		l -= n;
	while(r > n)
		r -= n;
	printf("%d\n%d %d\n",ans,l,r);
	return 0;
}
