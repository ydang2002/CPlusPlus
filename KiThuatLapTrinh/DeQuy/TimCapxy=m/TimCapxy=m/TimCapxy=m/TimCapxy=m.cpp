// TimCapxy=m.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void Nhapmang(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << " Phan Tu" << i << ":";
        cin >> a[i];
    }
}

/*int Demcapxy(int n, int m, int a[])
{
    int Dem=0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i] == m)
                Dem = Dem + 1;
        }
    }
    return Dem;
}*/

//dem khi da sao xep
int Dem(int n,int m,int a[])
{
    int L = 0;
    int R = n;
    int Temp,Dem=0;
    while (L < R)
    {
        Temp = a[L] + a[R];
            if (Temp < m)
            {
                L++;
            }
            else if (Temp == m)
            {
                Dem++;
                L++;
                R++;

            }
            else if (Temp > m)
            {
                R++;
            }

    }
    return Dem;
}

int main()
{
    int a[100];
    int n,m;
    cin >> n;
    cin >> m;
    Nhapmang(n,a);
    cout << Dem(n, m,a);
    
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
