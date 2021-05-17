/*Cho dãy số An (n là số nguyên dương) được biểu diễn theo công thức đệ qui sau:
A1=1;
A2=2;
A3=3;
An=24An-1 + 25An-2 + 10An-3 + 2018 mọi n >3.
a. Viết hàm tính An bằng cách sử dụng đệ qui.
b. Viết hàm tính An bằng cách không sử dụng đệ qui và cũng không sử dụng cấu trúc dữ liệu mảng.
Câu 2. (3,0 điểm)
Cho chuỗi s gồm các từ, mỗi từ cách nhau đúng một khoảng trắng (giả sử đầu và cuối
chuỗi không có khoảng trắng nào dư thừa). Từ có k ký tự gọi là từ loại k; k có thể là 1,2,3,4,5,6,7.
Hãy tìm từ loại xuất hiện nhiều lần nhất; nếu có nhiều hơn một kết quả thì hãy xuất một kết quả
đại diện.
Ví dụ chuỗi s là ”Thanh Pho Ho Chi Minh Gia Dinh” thì kết quả là từ loại 3.
Câu 3. (3,0 điểm)
Cho tập tin mang.inp chứa các số nguyên mỗi số cách nhau ít nhất một khoảng trắng. Hãy
viết chương trình hoàn chỉnh đọc các số nguyên trong mang.inp; sau đó sắp xếp các số theo thứ
tự không giảm và ghi kết quả vào tập tin mang.out.
Ví dụ:
mang.inp
7 3 1 7 9
mang.out
1 3 7 7 9
Câu 4. (2,0 điểm)
Cho tập tin mang2D.inp là mảng hai chiều a có m dòng n cột; các phần tử của a là các số
nguyên. Hãy viết hàm đọc tập tin mang2D.inp và lưu vào mảng a được cấp phát động và tính
tổng các số lẻ trên dòng k. (0<=k<n). Ví dụ : m=3, n=4
1 2 3 4
2 7 3 11
5 2 7 8
Khi k =1 thì kết quả là : 21*/

#include <iostream>
using namespace std;

int TinhAn(int n)
{
    if (n <= 3)
    {
        return n;
    }
    else
    {
        return 24 * (n - 1) + 25 * (n - 2) + 10 * (n - 3) + 2018;
    }
}

int TinhAnKhongDeQuy(int n)
{
    int a = 1;
    int b = 2;
    int c = 3;
    int k;
    if (n<=3)
    {
        return n;
    }
    else
    {
        for (int i = 4; i <= n; i++)
        {
            k = 24 * c + 25 * b + 10 * a + 2018;
            a = b;
            b = c;
            c = k;
        }
        return k;
    }
}


int main()
{
    int n;
    cout << "\nNhap n: ";
    cin >> n;
    
     cout<< TinhAnKhongDeQuy(n);
}

