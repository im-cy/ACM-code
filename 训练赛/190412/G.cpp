#include<iostream>
#include<cstdio>
using namespace std;
struct point
{
	int x,y,z;
}s1,s2,e1,e2;
bool is_eq(point s1,point s2)
{
	if(s1.x == s2.x && s1.y == s2.y && s1.z == s2.z)
		return true;
	return false;
}
int main()
{
	scanf("%d%d%d%d%d%d",&s1.x,&s1.y,&s1.z,&e1.x,&e1.y,&e1.z);
	scanf("%d%d%d%d%d%d",&s2.x,&s2.y,&s2.z,&e2.x,&e2.y,&e2.z);
	while(s1.x != e1.x || s1.y != e1.y || s1.z != e1.z || s2.x != e2.x || s2.y != e2.y || s2.z != e2.z)
	{
		point temp1 = s1 , temp2 = s2;
		if(s1.x != e1.x)
		{
			if(s1.x < e1.x)
				s1.x ++;
			else
				s1.x --;
		}
		else if(s1.y != e1.y)
		{
			if(s1.y < e1.y)
				s1.y ++;
			else
				s1.y --;
		}
		else if(s1.z != e1.z)
		{
			if(s1.z < e1.z)
				s1.z ++;
			else
				s1.z --;
		}
		
		
		if(s2.z != e2.z)
		{
			if(s2.z < e2.z)
				s2.z ++;
			else
				s2.z --;
		}
		else if(s2.y != e2.y)
		{
			if(s2.y < e2.y)
				s2.y ++;
			else
				s2.y --;
		}
		else if(s2.x != e2.x)
		{
			if(s2.x < e2.x)
				s2.x ++;
			else
				s2.x --;
		}
		if(is_eq(s1,temp2) && is_eq(temp1,s2))
		{
			s1 = temp1;
			s2 = temp2;
			if(s1.x != e1.x)
			{
				if(s1.x > e1.x)
					s1.x ++;
				else
					s1.x --;
			}
			else if(s1.y != e1.y)
			{
				if(s1.y > e1.y)
					s1.y ++;
				else
					s1.y --;
			}
			else if(s1.z != e1.z)
			{
				if(s1.z > e1.z)
					s1.z ++;
				else
					s1.z --;
			}
			else
			{
				if(s2.z != e2.z)
				{
					if(s2.z > e2.z)
						s2.z ++;
					else
						s2.z --;
				}
				else if(s2.y != e2.y)
				{
					if(s2.y > e2.y)
						s2.y ++;
					else
						s2.y --;
				}
				else if(s2.x != e2.x)
				{
					if(s2.x > e2.x)
						s2.x ++;
					else
						s2.x --;
				}
			}
		}
		else if(is_eq(s1,s2))
		{
			if(is_eq(s1,e1))
				s2 = temp2;
			else
				s1 = temp1;
		}
		printf("(%d %d %d) (%d %d %d)\n",s1.x,s1.y,s1.z,s2.x,s2.y,s2.z);
	}
	return 0;
}

