/*Danh sách liên kết đơn (DSLK) là một trong những cấu trúc dữ liệu thường được dùng để lưu
trữ và xử lý một tập các đối tượng mà số lượng các đối tượng không được xác định trước.
a. Xem mỗi đối tượng như là một số nguyên (có giá trị là một số nguyên), hãy định nghĩa (khai
báo) cấu trúc dữ liệu danh sách liên kết đơn LIST (trong C/C++) và viết giải thuật để chèn một
đối tượng có giá trị k vào đầu của DSLK.
b. Viết một giải thuật để chèn một đối tượng có giá trị k vào cuối DSLK. Tính độ phức tạp của
giải thuật đã viết.
c. Giả sử các đối tượng trong DSLK có giá trị đôi một khác nhau, hãy viết một giải thuật để
tìm nút lưu trữ đối tượng có giá trị chẵn lớn nhất trong DSLK.
d. Giả sử các đối tượng trong DSLK có giá trị đôi một khác nhau, hãy viết một giải thuật để tìm
nút trong DSLK mà lưu trữ đối tượng có giá trị nhỏ nhất lớn hơn một giá trị k nguyên cho
trước.*/
#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

struct list
{
    node* head;
    node* tail;
};

void KhoiTao(list& l)
{
    l.head = NULL;
    l.tail = NULL;
}

node* TaoNODE(int x)
{
    node* p = new node;
    p->data = x;
    p->next = NULL;
    return p;
}

void ThemNODEVaoDau(list& l, node* p)
{
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}

void ThemNODEVaoCuoi(list& l, node* p)
{
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void NhapNODE(list& l)
{
    int x, n;
    cout << " \n nhap so luong node vao danh sach: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\n nhap gia tri x: ";
        cin >> x;
        node* p = TaoNODE(x);
        cout << p->data << endl;
        ThemNODEVaoCuoi(l, p);
    }
}

void Xuat(list l)
{
    node* temp = l.head;
    while (temp != NULL)
    {
        cout << "\t" << temp->data;
        temp = temp->next;
    }
}

int TimMax(list l)
{
    int max = -1;
    for (node* i = l.head; i != NULL; i = i->next)
    {
        if (i->data>max)
        {
            max = i->data;
        }
    }
    return max;
}

//vode* Find_maxNode(node* head)
//{
//    int max = head->data;
//    node* maxNode = head;
//    node* temp = head;
//    while (temp != NULL)
//    {
//        if (temp->data > max)
//        {
//            max = temp->data;
//            maxNode = temp;
//        }
//        temp = temp->next;
//    }
//    return maxNode;
//}
//
//node* timmaxchan(linkedlist* l)
//{
//    node* temp = new node;
//    node* f = l->head;
//    int max = -1;
//    while (f != NULL)
//    {
//        if (f->data % 2 == 0)
//        {
//            if (f->data > max)
//            {
//                max = f->data;
//                temp->data = f->data;
//            }
//        }
//        f = f->next;
//    }
//    return temp;
//}

void TimMaxChan(list l)
{
    for (node* i = l.head; i != NULL; i = i->next)
    {
        if (i->data==TimMax(l) && i->data % 2 == 0)
        {
            cout << "\n phan tu chan va lon nhat: " << i->data;
        }
    }
}

int TimMinVaLonHonK(list l,int k)
{
    int min = 10000;
    for (node* i = l.head; i != NULL; i = i->next)
    {
        if (i->data <min&&i->data>k)
        {
            min = i->data;
        }
    }
    return min;
}

int main()
{
    list(l);
    KhoiTao(l);
    NhapNODE(l);
    int k;
    //cau a
    cout << "\ncau a";
    cout << "\nthem node k vao dau danh sach: ";
    cin >> k;
    node* p = TaoNODE(k);
    ThemNODEVaoDau(l,p);
    Xuat(l);
    //cau b
    cout << "\ncau b";
    cout << "\nthem node k vao cuoi danh sach: ";
    cin >> k;
    node* f = TaoNODE(k);
    ThemNODEVaoCuoi(l, f);
    Xuat(l);
    //cau c
    cout << "\ncau c";
    TimMaxChan(l);
    //cau d
    cout << "\ncau d";
    cout << "\n nhap k: ";
    cin >> k;
    cout << " \ngia tri nho nhat lon hon mot gia tri k: ";
    cout << TimMinVaLonHonK(l, k);
}