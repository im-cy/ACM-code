#include<iostream>
#include<cmath>
#include<cstdio>
#include<iomanip>
using namespace std;
typedef class Node
{
	public:
		double x,y;
}location;
double det(double x1,double y1,double x2,double y2)
{
	return x1*y2-x2*y1;
}
double cross(location A,location B,location C,location D)
{
	return det(B.x-A.x , B.y-A.y , D.x-C.x , D.y-C.y);
}
double xx,yy;
void intersection(location A,location B,location C,location D)
{
	double area1=cross(A,B,A,C);
	double area2=cross(A,B,A,D);
 
	xx=(area2*C.x - area1*D.x)/(area2-area1);
	yy=(area2*C.y - area1*D.y)/(area2-area1); 
	return;
}
double area(location A,location B,location C,location D)
{
	double triangle1=fabs(0.5*cross(A,B,A,C));
	double triangle2=fabs(0.5*cross(A,B,A,D));
	return triangle1+triangle2;
}
int main()
{
	int n;
	while(scanf("%d",&n) && n)
	{
		location** node=new location*[n+2];
		node[0] = new location[n+2];
		node[n+1] = new location[n+2];
		node[0][0].x = node[0][0].y =0.0;
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> node[0][i].x;
			node[0][i].y=0.0;
		}
		node[0][n+1].x = 1.0;
		node[0][n+1].y = 0.0;
		node[n+1][0].x = 0.0;
		node[n+1][0].y = 1.0;
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> node[n+1][i].x;
			node[n+1][i].y = 1.0;
		}
		node[n+1][n+1].x = 1.0;
		node[n+1][n+1].y = 1.0;
		for(int i = 1 ; i <= n ; i ++)
		{
			node[i] = new location[n+2];
			cin >> node[i][0].y;
			node[i][0].x = 0.0;
		}
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> node[i][n+1].y;
			node[i][n+1].x = 1.0;
		}
		for(int j = 1 ; j <= n ; j ++)
			for(int i = 1 ; i <= n ; i ++)
			{
				intersection(node[0][j],node[n+1][j],node[i][0],node[i][n+1]);
				node[i][j].x = xx;
				node[i][j].y = yy;
			}
		double max_area = 0.0;
		for(int i = 1 ; i <= n + 1 ; i ++)
			for(int j = 1 ; j <= n + 1 ; j ++)
			{
				double temp = area(node[i-1][j-1],node[i][j],node[i][j-1],node[i-1][j]);
				if(max_area < temp)
					max_area = temp;
			}
		cout << fixed << setprecision(6) << max_area << endl;
	}
	return 0;
}
