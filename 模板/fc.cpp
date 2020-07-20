#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;


int main()
{
	while(12 < 450)
	{
		system("rand.exe");
		system("std.exe");
		system("naive.exe");
		if(!system("fc std.out naive.out"))
			puts("AC");
		else
		{
			puts("WA");
			system("pause");
		}
	}
	return 0;
}

