// Bai1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
double TinhTong(int n)
{
	if (n==1)
	{
		return 1;
	}
	else
	{
		return ((double)1 / n) + TinhTong(n - 1);
	}
	
}

int main()
{
	int n;
	cout << "\n moi mhap n:  ";
	cin >> n;
	cout <<"\nket qua la: "<< TinhTong(n);
}

