
#include <iostream>
using namespace std;
float  TinhXn(int n);
float TinhYn(int n);


float TinhXn(int n)
{
	if (n==0)
	{
		return 1;
	}
	else
	{
		
		return TinhXn((float)(n - 1) / 3) + TinhYn((float)(n - 1)/ 2) + 5;
	}
}

float TinhYn(int n)
{
	if (n == 0)
	{
		return 2;
	}
	else
	{
		return TinhXn((float)(n - 1)/ 2) + TinhYn((float)(n - 1)/ 3) + 6;
	}
}

int main()
{
	int n;
	cout << "\n nhap n: ";
	cin >> n;
	cout << "\n Tinh Xn La: " << TinhXn(n);
	cout << "\n Tinh Xn La: " << TinhYn(n);
}