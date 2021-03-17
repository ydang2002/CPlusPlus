// Bai6.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Lấy ra chữ số ở vị trí nào đó (tính từ phải sang trái) của một số tự nhiên.
Nhập số tự nhiên: 1410
Bạn muốn lấy chữ số ở vị trí nào thứ:3
Chữ số ở vị trí thứ 3 (từ phải sang trái) của số 1410 là : 4*/

#include <iostream>
using namespace std;


int  LaySoThuK(int n,int  k)
{
    int dv;
    int dem = 0;
    if (n < 0)
    {
        return -1;
    }

    while (n != 0)
    {
        dv = n % 10;
        dem = dem + 1;
        if (k == dem)
        {
            return dv;
        }
        n = n / 10;
    }

    return -1;
}

//sử dụng đệ quy
int SoThuKDeQuy(int n, int k, int dem)
{
    int dv;
    if (n < 0)
    {
        return -1;
    }

    dv = n % 10;
    dem = dem + 1;

    if (k == dem)
    {
        return dv;
    }
    else
    {
        return SoThuKDeQuy(n / 10, k,dem);
    }
}

int main()
{
    int n, k, dem = 0;
    cout << " nhap n: ";
    cin >> n;
    cout << " nhap k: ";
    cin >> k;
    //cout<< SoThuKDeQuy(n,k,dem);
    cout << LaySoThuK(n,k);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
