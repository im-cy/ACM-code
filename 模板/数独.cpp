#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#define tr(i,j) ((i-1)/3*3+(j-1)/3+1)
using namespace std;

struct item
{
	int x,y;
}O[85];

int L[10][10],H[10][10],N[10][10],G[10][10],en,res=-1;
bool used[10][10];

inline int get_ans()
{
	int tmp=0;
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
			tmp+=G[i][j]*6;
	for(int i=2;i<=8;i++)
		for(int j=2;j<=8;j++)
			tmp+=G[i][j];
	for(int i=3;i<=7;i++)
		for(int j=3;j<=7;j++)
			tmp+=G[i][j];
	for(int i=4;i<=6;i++)
		for(int j=4;j<=6;j++)
			tmp+=G[i][j];
	tmp+=G[5][5];
	return tmp;
}

void dfs(int p)
{
	if(p>en)
	{
		res=max(res,get_ans());
		return ;
	}
	int &x=O[p].x;
	int &y=O[p].y;
	for(int i=1;i<=9;i++)
		if(L[x][i]==0&&H[y][i]==0&&N[tr(x,y)][i]==0)
		{
			L[x][i]++;
			H[y][i]++;
			N[tr(x,y)][i]++;
			G[x][y]=i;
			dfs(p+1);
			G[x][y]=0;
			L[x][i]--;
			H[y][i]--;
			N[tr(x,y)][i]--;
		}
}

int main()
{
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
		{
			scanf("%d",&G[i][j]);
			if(G[i][j]>0)
			{
				L[i][G[i][j]]++;
				H[j][G[i][j]]++;
				N[tr(i,j)][G[i][j]]++;
			}
			else
				en++;
		}
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
		{
			L[i][0]+=L[i][j];
			H[i][0]+=H[i][j];
			N[i][0]+=N[i][j];
		}
	for(int p=1,maxp;p<=en;p++)
	{
		maxp=0;
		for(int i=1;i<=9;i++)
			for(int j=1;j<=9;j++)
				if(G[i][j]==0&&!used[i][j]&&maxp<L[i][0]+H[j][0]+N[tr(i,j)][0])
				{
					maxp=L[i][0]+H[j][0]+N[tr(i,j)][0];
					O[p].x=i;
					O[p].y=j;
				}
		L[O[p].x][0]++;
		H[O[p].y][0]++;
		N[tr(O[p].x,O[p].y)][0]++;
		used[O[p].x][O[p].y]=true;
	}
	dfs(1);
	for(int i = 1 ; i <= 9 ; i ++)
	{
		for(int j = 1 ; j <= 9 ; j ++)
			printf("%d",G[i][j]);
		puts("");
	}
	return 0;
}
