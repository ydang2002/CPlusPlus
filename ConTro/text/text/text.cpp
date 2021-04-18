#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct list
{
    node* head;
};

node* TaoNode(int x)
{
    node* p = new node;
    p->data = x;
    p->next = NULL;
    return p;
}

void ThemNodeVaoDau(node*& head, node* p)
{
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
}

void ThemVaoCuoi(node*& head, node* p)
{
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        node* temp = head;
        while (p->next == NULL)
        {
            temp = temp->next;
            temp->next = p;
        }
    }
}

void Xuat(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

void xuat(node* head)
{
    for (node* i = head; i != NULL; i = i->next)
    {
        cout << i->data << " ";
    }
}

int main()
{
   // node* head = new node;
    int n;
    cout << "\n nhap so luong node can them: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "\n nhap gia tri so nguyen: ";
        cin >> x;
        node* head = new node;
        node* p = TaoNode(x);
        ThemNodeVaoDau(head, p);
        cout << "\ndanh sach lien ket don";
        Xuat(head);
    }
    //cout << "\ndanh sach lien ket don";
    //Xuat(head);
}

