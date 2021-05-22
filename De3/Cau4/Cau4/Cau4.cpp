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