#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
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
int block_num;//��������� 
void block_init()
{
	block_num = sqrt(n); 
	for(int i = 1 ; i <= n ; i ++)
	{
		find_block[i] = (i-1) / block_num + 1; 
	}
	return ;
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
	if(find_block[l] != find_block[r]) //���غϵĻ����Ҷ˵�Ŀ�Ҳ�������� 
		for(int i = block_l(r) ; i <= r ; i ++) 
			num[i] += c;
	for(int i = find_block[l] + 1 ; i <= find_block[r] - 1 ; i ++)//ÿ���� O(1) 
		block[i].num += c;
	return ; 
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
			printf("%lld\n",num[r]+block[find_block[r]].num);
	} 
	return 0;
}
/*
10
1 1 1 1 1 1 1 1 1 1
*/
