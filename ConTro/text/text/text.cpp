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

void ThemVaoCuoi(node* &head, node* p)
{
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void Xuat(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        cout << "\t" << temp->data;
        temp = temp->next;
    }
}

void xuat(node* head)
{
    for (node* i = head; i != NULL; i = i->next)
    {
        cout << i->data << "\t";
    }
}


int main()
{
    node* head = NULL;
    int n;
    cout << "\n nhap so luong node can them: ";
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cout << "\n nhap gia tri so nguyen: ";
        cin >> x;
        node* p = TaoNode(x);
        cout << p->data;
        //ThemNodeVaoDau(head, p);
        ThemVaoCuoi(head, p);
    }
    
    
    cout << "\ndanh sach lien ket don";
    Xuat(head);
    return 0;
}

