#include<bits/stdc++.h>
using namespace std;

int main()
{
	while(12 < 450)
	{
		system("datamaker.exe");
		system("C.exe");
		system("C_std.exe");
		if(system("fc naive.txt std.txt"))
		{
			puts("WA");
			system("pause");
		}
		else
			puts("AC");
	}
	return 0;
}

