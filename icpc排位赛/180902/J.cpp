#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 200010;
int A,B;
struct dc
{
	int num;
	int col;
}card[11],stack[sz],fis,sec;
int ans[21];
int temp_tong[31];
bool cmp_num(dc a,dc b)
{
	if(a.num == b.num)
		return a.col < b.col;
	return a.num < b.num;
}
bool cmp_col(dc a,dc b)
{
	if(a.col == b.col)
		return a.num < b.num;
	return a.col < b.col;
}
int n;
bool is_same(dc a,dc b)
{
	if(a.num != b.num)
		return false;
	if(a.col != b.col)
		return false;
	return true;
}

void init()
{
	scanf("%d%d",&A,&B);
	scanf("%d%d%d%d",&card[1].num,&card[1].col,&card[2].num,&card[2].col);
	fis = card[1];
	sec = card[2];
	temp_tong[card[1].num] ++;
	temp_tong[card[2].num] ++;
	for(int i = 0 ; i < A ; i ++)
	{
		for(int j = 0 ; j < B ; j ++)
		{
			dc new_card;
			new_card.num = i;
			new_card.col = j;
			if(!is_same(new_card,card[1]) && !is_same(new_card,card[2]))
				stack[++n] = new_card;
		}
	}
	return ;
}
bool straight_flush()
{
	sort(card+1,card+6,cmp_num);
	for(int i = 2 ; i <= 5 ; i ++)
		if(card[i].num != (card[i-1].num + 1) || card[i].col != card[i-1].col)
			return false;
	return true;
}
bool four_of_a_kind()
{
	for(int i = 0 ; i < A ; i ++)
		if(temp_tong[i] == 4)
			return true;
	return false;
}
bool full_house()
{
	bool flag = 0;
	for(int i = 0 ; i < A ; i ++)
		if(temp_tong[i] == 3)
			flag = 1;
	if(!flag)
		return false;
	for(int i = 0 ; i < A ; i ++)
		if(temp_tong[i] == 2)
			return true;
	return false;
}
bool flush()
{
	for(int i = 2 ; i <= 5 ; i ++)
		if(card[i].col != card[i-1].col)
			return false;
	return true;
}
bool straight()
{
	sort(card+1,card+6,cmp_num);
	for(int i = 2 ; i <= 5 ; i ++)
		if(card[i].num != (card[i-1].num+1))
			return false;
	return true;
}
bool three_of_a_kind()
{
	for(int i = 0 ; i < A ; i ++)
		if(temp_tong[i] == 3)
			return true;
	return false;
}
bool two_pair()
{
	int tot = 0;
	for(int i = 0 ; i < A ; i ++)
		if(temp_tong[i] == 2)
			tot ++;
	if(tot == 2)
		return true;
	return false;
}
bool one_pair()
{
	for(int i = 0 ; i < A ; i ++)
		if(temp_tong[i] == 2)
			return true;
	return false;
}
int judge()
{
	if(straight_flush())
		return 1;
	if(four_of_a_kind())
		return 2;
	if(full_house())
		return 3;
	if(flush())
		return 4;
	if(straight())
		return 5;
	if(three_of_a_kind())
		return 6;
	if(two_pair())
		return 7;
	if(one_pair())
		return 8;
	return 9;
}



void get_card()
{
	for(int i = 1 ; i <= n ; i ++)
		for(int j = i + 1 ; j <= n ; j ++)
			for(int k = j + 1 ; k <= n ; k ++)
			{
				card[1] = fis;
				card[2] = sec;
				card[3] = stack[i];
				card[4] = stack[j];
				card[5] = stack[k];
				temp_tong[card[3].num] ++;
				temp_tong[card[4].num] ++;
				temp_tong[card[5].num] ++;
				ans[judge()] ++;
				temp_tong[stack[i].num] --;
				temp_tong[stack[j].num] --;
				temp_tong[stack[k].num] --;
			}
}
int main()
{
	init();
	get_card();
	for(int i = 1 ; i <= 9 ; i ++)
		printf("%d ",ans[i]);
	return 0;
}



