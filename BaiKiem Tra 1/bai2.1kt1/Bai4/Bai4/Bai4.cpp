#include <iostream>
using namespace std;

void forFun(int x)
{
	if (x> 0)
	{
		forFun(--x);
		cout << "\t" << x;
		forFun(--x);
	}
}

int main()
{
	int a = 4;
	forFun(a);
	return 0;
}