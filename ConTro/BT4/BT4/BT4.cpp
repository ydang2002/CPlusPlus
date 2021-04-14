/*a.Cho danh sách liên  kết l, mỗi phần tử là một số nguyên. Hãy tính tổng các phần tử l.
b. Cho danh sách liên kết l,mỗi phần tử là một số nguyên.Hay kiểm tra danh sách  l  có chứa giá trị x không, nếu có trả về 1, nếu không trả về 0.
c. Cho danh sách liên kết l, môi phần tử là một số nguyên.Hãy sắp xếp các phần tử theo chiều tăng dần*/

#include <iostream>
using namespace std;

//Tạo cấu trúc dữ liệu cho danh sách liên kết đơn
struct node
{
    int info;
    struct node* next;
};

struct list
{
    node* head;
    node* tail;
};

void ThemNut(list& l, node* p)
{
    if (l.head==NULL)
    {
        l.tail = p;
        l.head = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void NhapDanhSach(list &l)
{
    int x,n;
    cout << "danh sach co bao  nhieu phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << " phan  tu thu " << i << ": ";
        cin >> x;
        node* p = new node;
        p->info = x;
        p->next = NULL;
        ThemNut(l, p);
    }
}

int TongCacPhanTu(list l)
{
    
    int Tong = 0;
    for (int i = 0; i < n; i++)
    {
        
    }
    return Tong;
}

list l;

int main()
{
    
    NhapDanhSach(l);
    cout<<" Tong cac phan tu"<<TongCacPhanTu(l);
}


