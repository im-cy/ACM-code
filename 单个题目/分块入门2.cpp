#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define ll long long
using namespace std;
const int sz = 200010;
int n;//���鳤�� 
ll num[sz];//��ʼ���� 
int find_block[sz];//��i�������ڵ�find_block[i]�� 
struct block_
{
	ll num;
}block[sz];//��¼������Ϣ
vector < int > ve[sz];
int block_num;//��������� 
void block_init()
{
	block_num = sqrt(n); 
	for(int i = 1 ; i <= n ; i ++)
	{
		find_block[i] = (i-1) / block_num + 1;
		ve[find_block[i]].push_back(num[i]);
	}
	for(int i = 1 ; i <= find_block[n] ; i ++)
		sort(ve[i].begin(),ve[i].end());
	return ;
}
void reset(int x)//��x���� 
{
	ve[x].clear();
	int l = (x-1) * block_num + 1 , r = min(x*block_num,n);
	for(int i = l ; i <= r ; i ++)
		ve[x].push_back(num[i]);
	sort(ve[x].begin(),ve[x].end());
}
//�ҵ�x����������Ҷ˵� 
int block_l(int x)
{
	return (find_block[x]-1) * block_num + 1;
}
int block_r(int x)
{
	return find_block[x] * block_num;
}
void change(int l,int r,int c)
{
	for(int i = l ; i <= min(r,block_r(l)) ; i ++) //���ڱ��� 
		num[i] += c;
	reset(find_block[l]);
	if(find_block[l] != find_block[r]) //���غϵĻ����Ҷ˵�Ŀ�Ҳ�������� 
	{
		for(int i = block_l(r) ; i <= r ; i ++) 
			num[i] += c;
		reset(find_block[r]);
	}
	for(int i = find_block[l] + 1 ; i <= find_block[r] - 1 ; i ++)//ÿ���� O(1) 
		block[i].num += c;
	return ; 
}
int ask(int l,int r,int c)//��ѯlr��С��c�ĸ��� 
{
	int ans = 0;
	for(int i = l ; i <= min(r,block_r(l)) ; i ++) //���ڱ��� 
		if(num[i] + block[find_block[l]].num < c)
			ans ++;
	if(find_block[l] != find_block[r]) //���غϵĻ����Ҷ˵�Ŀ�Ҳ�������� 
	{
		for(int i = block_l(r) ; i <= r ; i ++) 
			if(num[i] + block[find_block[r]].num < c)
				ans ++;
	}
	for(int i = find_block[l] + 1 ; i <= find_block[r] - 1 ; i ++)//ÿ���� O(1) 
	{
		int x = c - block[i].num;
		ans += lower_bound(ve[i].begin(),ve[i].end(),x) - ve[i].begin();
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%lld",&num[i]);
	block_init();
	for(int i = 1 ; i <= n ; i ++)
	{
		int opt,l,r;
		ll c;
		scanf("%d%d%d%lld",&opt,&l,&r,&c);
		if(opt == 0)
			change(l,r,c);
		if(opt == 1)
			printf("%d\n",ask(l,r,c*c));
	} 
	return 0;
}
