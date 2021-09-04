// Bai2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int TinhXn(int n)
{
	if (n==1 || n==2)
	{
		return 1;
	}
	else
	{
		return TinhXn(n - 1) + (n - 1) * TinhXn(n - 2);
	}
}

int TinhXnKhuDeQuy(int n)
{
	int x1 = 1, x2 = 1, xn;
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		for (int i = 3; i <= n; i++)
		{
			xn = x1 + (i - 1) * x2;
			x2 = x1;
			x1 = xn;
		}
	}
	return xn;
}

int main()
{
	int n;
	cout << "\nnhap n:";
	cin >> n;
	//cout << "ket qua la: " << TinhXn(n);
	cout << "ket qua la: " << TinhXnKhuDeQuy(n);
}

