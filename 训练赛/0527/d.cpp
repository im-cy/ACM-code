#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool used[1010][1010];
bool uset[1010][1010];
int n;
struct point
{
	int x,y;
};
point getnxt(point k,int pos)
{
	if(pos == 0)
		k.y ++;
	if(pos == 1)
		k.x --;
	if(pos == 2)
		k.y --;
	if(pos == 3)
		k.x ++;
	return k;
}
int main()
{
	while(scanf("%d",&n) && n)
	{
		memset(used,0,sizeof(used));
		memset(uset,0,sizeof(uset));
		point don,tig;
		int d_p,t_p;
		scanf("%d%d%d%d%d%d",&don.x,&don.y,&d_p,&tig.x,&tig.y,&t_p);
		used[don.x][don.y] = 1;
		uset[tig.x][tig.y] = 1;
		bool flagd = 0 , flagt = 0;
		while(12 < 450)
		{
			point nxtd = don;
			point nxtt = tig;
			nxtd = getnxt(don,d_p);
			nxtt = getnxt(tig,t_p);
			if(d_p == -1 && t_p == -1 && (don.x != tig.x || don.y != tig.y))
			{
				puts("-1");
				break;
			}
			if(don.x == tig.x && don.y == tig.y)
			{
				printf("%d %d\n",don.x,don.y);
				break;
			}
			
			if(nxtd.x >= 0 && nxtd.x < n && nxtd.y >= 0 && nxtd.y < n && !used[nxtd.x][nxtd.y])
			{
				don = nxtd;
				used[nxtd.x][nxtd.y] = 1;
				if(d_p != -1)
					flagd = 0;
			}
			else
			{
				if(!flagd)
				{
					flagd = 1;
					d_p --;
					if(d_p < 0)
						d_p += 4;
				}
				else
					d_p = -1;
			}
			
			if(nxtt.x >= 0 && nxtt.x < n && nxtt.y >= 0 && nxtt.y < n && !uset[nxtt.x][nxtt.y])
			{
				tig = nxtt;
				uset[nxtt.x][nxtt.y] = 1;
				if(t_p != -1)
					flagt = 0;
			}
			else
			{
				if(!flagt)
				{
					flagt = 1;
					t_p ++;
					t_p %= 4;
				}
				else
					t_p = -1;
			}
			
		}
	} 
	
	return 0;
}

