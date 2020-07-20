#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int a[500];
int stTable[2][MAX][32];
int preLog2[MAX];
void st_prepare(int n,int *array)
{
	preLog2[1] = 0;
	for(int i = 2 ; i <= n ; i ++)
	{
		preLog2[i] = preLog2[i-1];
		if((1 << preLog2[i] + 1) == i)
		{
			++ preLog2[i];
		}
	}
	for(int i = n - 1 ; i >= 0 ; i --)
	{
		stTable[0][i][0] = array[i];
		for(int j = 1 ; (i + (1 << j) - 1) < n ; j ++)
		{
			stTable[0][i][j] = min(stTable[0][i][j-1],stTable[0][i+(1 << j-1)][j-1]);
		}
		
	}
	for(int i = n - 1 ; i >= 0 ; i --)
	{
		stTable[1][i][0] = array[i];
		for(int j = 1 ; (i + (1 << j) - 1) < n ; j ++)
		{
			stTable[1][i][j] = max(stTable[1][i][j-1],stTable[1][i+(1 << j-1)][j-1]);
		}
		
	}
}
int query_min(int l,int r)
{
	int len = r - l + 1 , k = preLog2[len];
	return min(stTable[0][l][k],stTable[0][r-(1<<k)+1][k]);
}
int query_max(int l,int r)
{
	int len = r - l + 1 , k = preLog2[len];
	return max(stTable[1][l][k],stTable[1][r-(1<<k)+1][k]);
}
int main()
{
	int n, l, r;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	st_prepare(n, a);
	while(true)
	{
		cin >> l >> r;
		cout << query_min(l - 1, r - 1) << " " << query_max(l - 1, r - 1) << endl;
	}
	return 0;
}

