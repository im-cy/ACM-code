#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* 
0 plain
1 swamp
2 mountain
3 island
4 forest
*/
int Hand[5] = {3,4,2,0,1};
int Drop[5] = {2,1,3,4,0};
struct Player
{
	Player()
	{
		dpos = 1;
		hnum = 0;
		memset(hand,0,sizeof(hand));
		memset(deck,0,sizeof(deck));
		memset(field,0,sizeof(field));
		memset(grave,0,sizeof(grave));
	}
	
	void Draw()
	{
		if(dpos <= 25)
		{
			hand[deck[dpos]] ++;
			dpos ++;
			hnum ++;
		}
	}
	void discard()
	{
		int max = 0 , kind = -1;
		for(int i = 0 ; i <= 4 ; i ++)
		{
			if(hand[i] > max)
			{
				kind = i;
				max = hand[i];
			}
			else if(hand[i] == max && Drop[i] > Drop[kind])
				kind = i;
		}
		hand[kind] --;
		hnum --;
		gnum ++;
	}///////////////////////
	int hand[5],hnum;
	int deck[31],dpos;
	int field[31],fnum;
	int grave[31],gnum;
	int proity[5];
};
bool counter(Player &a,Player &b)
{
	int kind = 0;
	for(int i = 0 ; i <= 4 ; i ++)
		if(a.field[i])
			kind ++;
	if(kind == 4 && b.hand[3] && b.hnum >= 2)
	{
		b.field[3] ++;
		b.hnum --;
		b.discard();
		a.gnum ++;
		return true;
	}
	return false;
}
void work(Player &a,Player &b,int kind)
{
	if(kind == 0)
		a.draw();
	else if(kind == 1)
		b.discard();
	else if(kind == 2)
		b.destory();
	else if(kind == 3)
		return ;
	else
		a.recycle();
}
void Main(Player &a,Player &b)
{
	if(a.hnum <= 0)
		return ;
	memset(a.prority,0,sizeof(a.protity));
	for(int i = 0 ; i <= 4 ; i ++)
	{
		if(a.hand[i])
		{
			if(!a.field[i])
				a.prority[i] ++;
		}
	}
	if(a.hand[0])
		a.proryty[0] ++;
	if(a.hand[1] && b.hnum)
		a.prority[1] ++;
	if(a.hand[2] && b.fnum)
		a.prority[2] ++;
	if(a.hand[4] && a.gnum)
		a.prority[4] ++;
	int max = 0 , kind = -1;
	for(int i = 0 ; i <= 4 ; i ++)
	{
		if(a.prority[i] > max)
		{
			max = a.prority[i];
			kind = i;
		}
		if(a.prority[i] == max && Hand[i] > Hand[kind])
			kind = i;
	}
	if(kind == -1)
		return ;
	a.hnum --;
	a.hand[kind] --;
	if(!counter(a,b))
	{
		a.field[kind] ++;
		a.fnum ++;
		work(a,b,kind);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		Player a,b;
		for(int i = 1 ; i <= 25 ; i ++)
			scanf("%d",&a.deck[i]);
		for(int i = 1 ; i <= 25 ; i ++)
			scanf("%d",&b.deck[i]);
		
	}
	return 0;
}

