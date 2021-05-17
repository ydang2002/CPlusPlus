#include <iostream>
#include <string>
using namespace std;

//them ki tu vao vi tri thu k
void Them(char s[], int &vitrithem, char *kituthem)
{
    kituthem = new char[100];
    cout << "\n Nhap ki tu them: ";
    fgets(kituthem, 100, stdin);
    cout << "nhap vi tri them: ";
    cin >> vitrithem;
    int n = strlen(s);//độ dài chuoi
    for (int i = n - 1; i >= vitrithem; i--)
    {
        s[i + 1] = s[i];
    }
    s[vitrithem] = *kituthem;
    s[n++] = '\0';
}

int main()
{
    int vitrithem;
    char kituthem;
    /*//nhap chuoi cah 2
    char* s = new char[100];
    cout << "\n Nhap chuoi: ";
    fgets(s, 100, stdin);
    cout << "\nChuoi vua nhap";
    cout << s;
    Them(s,vitrithem,&kituthem);
    cout << s;
    */
    //nhap chuoi canh 1
    string s;
    cout << "\n nhap chuoi: ";
    //cin.ignore();
    getline(cin, s);
    cout << "\nchuoi nhan duoc la: " << s << endl;
    //for  (int i = 0;  i <s.length();  i++)//xuat tung ki tu
    //{
    //    cout << s[i] << " ";
    //}
    //cout << "\n do dai cua chuoi: " << s.length();// xuat do dai cua chuoi
    //s.erase(s.begin() + 3);//xoa 1 ki tu trong chuoi s vi tri thu 3
    //cout << "\n chuoi sau khi xoa: " << s;
    
}
