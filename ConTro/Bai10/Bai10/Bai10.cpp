/*Cho danh sách liên kết L, mỗi phần tử chứa một số nguyên dương.
a. Tính tổng các phần tử của L.
b. Thêm 1 phần tử vào đầu danh sách
c. Thêm 1 phần tử vào cuối danh sách
d. Thêm 1 phần tử vào vị trí k trong danh sách
e. Đếm xem danh sách L có bao nhiêu số nguyên tố ?
f. Tìm xem x có trong danh sách L hay không ? (trả về 0/1)
g. Tách danh sách L thành 2 danh sách chẵn,lẻ.
h. Đảo ngược các phần tử trong danh sách L. Xuất danh sách L.
i. Xóa các số nguyên tố trong danh sách L. Xuất danh sách L.*/
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
	node* tail;
};

void KhoiTao(list& l)
{
	l.head = NULL;
	l.tail = NULL;
}

node* TaoNode(int x)
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

void Xuat(list l)
{
	node* temp = l.head;
	while (temp != NULL)
	{
		cout << "\t" << temp->data;
		temp = temp->next;
	}
}

void xuat(list l)
{
	for (node* i = l.head; i != NULL; i = i->next)
	{
		cout << i->data << "\t";
	}
}
//vi tri cua k khi them vao danh sach lien ket
void ViTriK(list l, node* p, int vitri,int n)
{
	
	//danh sach rong
	if (l.head == NULL || vitri == 1)
	{
		ThemNODEVaoDau(l, p);
	}
	else if (vitri == n + 1)
	{
		ThemNODEVaoCuoi(l, p);
	}
	else // vi tri nam trong doan[2,n]
	{
		int dem = 0; //xac dinh vitri can them
		node* g = new node;
		for (node* k = l.head; k != NULL; k = k->next)
		{
			dem++;
			if (dem == vitri)
			{
				node* h = TaoNode(p->data);
				h->next = k;
				g->next = h;
				break;
			}
			g = k;
		}
	}
}
//kiem tra so nguyen to
bool check(int n)
{
	if (n <= 1)
	{
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

//tim gia tri x 
int TimX(list l)
{
	//nhap gia tri x can tim
	int x;
	cout << "\nNhap gia tri x can tim:";
	cin >> x;
	node* p = TaoNode(x);
	for (node* i = l.head; i != NULL; i = i->next)
	{
		if (x == i->data)
		{
			return 1;
		}
	}
	return 0;
}
/*void split_arr(int A[], int n, int B[], int* m, int C[], int *k)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        if(A[i]%2 != 0) // odd number
        {
            B[(*m)++] = A[i];
        }
        else //even number
        {
            C[(*k)++] = A[i];
        }
    }
}
 */

//Tách danh sách L thành 2 danh sách chẵn,lẻ.	
	void TachDSLK(list l, list & l1, list & l2,node* p)
	{
		list head = l;
		list head1 = l1;
		list head2 = l2;
		if (l.head == NULL)
		{
			l.head = l.tail =p;
		}
		else
			for (node* i = l.head; i != NULL; i = i->next)
			{
				if (i->data % 2 == 0)
				{
					ThemNODEVaoCuoi(l1, p);
					i = i->next;
				}
				else
				{
					ThemNODEVaoCuoi(l2, p);
					i = i->next;
				}
			}
	}
	

void menu(list l,list l1,list l2)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\t1. them node vao danh sach";
		cout << "\n\t2. xuat danh sach lien ket don";
		cout << "\n\t3.them node sau vi tri k";
		cout << "\n\t4.Dem so nguyen to";
		cout << "\n\t5.Tim x trong danh sach lien ket don";
		cout << "\n\t6.Tach danh sach l thanh 2 danh sach chan le";
		cout << "\n\t7.them node vao dau";
		cout << "\n\t0.thoat";
		cout << "\n nhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 7)
		{
			cout << "\n lua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			int x;
			cout << "\nNhap gia tri so nguyen:";
			cin >> x;
			node* p = TaoNode(x);
			ThemNODEVaoCuoi(l, p);
		}
		else if (luachon == 2)
		{
			Xuat(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			int n = 0;
				node* temp = l.head;
				while (temp != NULL)
				{
					n++;
					temp = temp->next;
				}
			
			int x;
			cout << "\nNhap gia tri node can them:";
			cin >> x;
			node* p = TaoNode(x);

			//nhap vi tri k
			int vitri;
			do
			{
				cout << "\n nhap vi tri can them node";
				cin >> vitri;
				if (vitri<1 || vitri>n + 1)
				{
					cout << "\n vi tri can them phai nam trong doan [1;" << n + 1 << "]";
					system("pause");
				}
			}
			while (vitri<1 || vitri>n + 1);

			ViTriK(l, p, vitri, n);
		}
		else if (luachon==4)
		{
			//dem so nguyen to trong danh sach lien ket
			
				int dem = 0;
				for (node* i = l.head; i != NULL; i = i->next)
				{
					if (check(i->data) == true)
					{
						dem++;
					}
				}
				cout << "\n Co " << dem << " so nguyen to"<<endl;
				system("pause");
			
		}
		else if (luachon==5)
		{
			cout << TimX(l) << endl;
			system("pause");
		}
		else if (luachon==6)
		{
			node* p = NULL;
			TachDSLK(l, l1, l2, p);
			Xuat(l1);
			system("pause");
		}
		else if (luachon==7)
		{
			int x;
			cout << "\nNhap gia tri so nguyen:";
			cin >> x;
			node* p = TaoNode(x);
			ThemNODEVaoCuoi(l, p);
		}
		else
		{
			break;// thoat khoi vong lap
		}
	}
}

int main()
{
	list l, l1{}, l2{};
	KhoiTao(l);
	menu(l,l1,l2);
}

/*void NhapCacPhan(list l)
{
	int n,x;
	cout << "nhap so luong node: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "\nNhap gia tri so nguyen:";
		cin >> x;
		node* p = TaoNode(x);
	}
}

//dem so luong node
int dem(list l)
{
	int n = 0;

	for (node* k = l.head; k !=NULL; k=k->next)
	{
		n++;
	}
}

void ThemNODEVaoViTriK(list l)
{
	NhapCacPhan(l);
	int n = 0;
				node* temp = l.head;
				while (temp != NULL)
				{
					n++;
					temp = temp->next;
				}
			
			int x;
			cout << "\nNhap gia tri node can them:";
			cin >> x;
			node* p = TaoNode(x);

			//nhap vi tri k
			int vitri;
			do
			{
				cout << "\n nhap vi tri can them node";
				cin >> vitri;
				if (vitri<1 || vitri>n + 1)
				{
					cout << "\n vi tri can them phai nam trong doan [1;" << n + 1 << "]";
					system("pause");
				}
			}
			while (vitri<1 || vitri>n + 1);

			ViTriK(l, p, vitri, n);
}

int main()
{
	int n{};
	list l;
	KhoiTao(l);
	//NhapCacPhan(l);
	//dem(l,n);
	ThemNODEVaoViTriK(l);
	Xuat(l);
	//system("pause");


}*/
