// Bài.2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void EnterArray(int a[], int& n)
// ham nhap cac phan tu trong mang
{
	cout << "Enter the number of elements in the array: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the A" << i << " element of the array:";
		cin >> a[i];
	}
}

int  CheckElement(int a[], int n)
// ham kiem tra xem co tim ra max2 khong?
{
	if (n <= 1)
		return false;
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] != a[0])
				return true;
		}
		return false;
	}
}

void EngineSup(int& max1, int& max2, int m)
{

	if (m > max1)
	{
		max2 = max1;
		max1 = m;
	}
	else
	{
		if (m > max2)
			max2 = m;
	}
}
//dung
void EngineMain(int& max1, int& max2, int n, int A[])
{
	if (n == 2)
	{
		EngineSup(max1, max2, A[n - 1]);
	}
	else
	{
		EngineMain(max1, max2, n - 1, A);
		EngineSup(max1, max2, A[n - 1]);
	}
}

void Choose(int a[], int n, int& max1, int& max2)
{
	int i = 0;
	max1 = a[0];
	max2 = a[1];
	while (a[i] == a[i + 1] && i < n)
	{
		max1 = a[i++];
		max2 = a[i];
	}
}

int main()
{
	int a[100];
	int n, max1, max2;
	bool Flag;
	EnterArray(a, n);
	Choose(a, n, max1, max2);
	Flag = CheckElement(a, n);
	if (Flag == false)
	{
		cout << "2nd largest number is: -1 ";
	}
	else
	{
		EngineMain(max1, max2, n, a);
		cout << "2nd largest number is: " << max2;
	}
}


