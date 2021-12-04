#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct BTree 
{
	int data;
	BTree *left, *right;
};

void DeleteTree(BTree *&root);
void DelElem(BTree *&root, int elem);
void Add(BTree *&root, int num);
void Show(BTree *&root, int level);
int Search(BTree *&root, int SearchElement, int Koll);
int MaxElem(BTree *&root);

int main()
{
	system("chcp 1251");
	BTree *Root = new BTree;
	if (Root == nullptr)
	{
		cout << "������ �� ����������";
		return 0;
	}	//�������� �� ��������� ������
	Root = nullptr;
	
	int num;
	cout << "��������:" << endl;
	cout << "1-�� �����" << endl;
	cout << "2-���������" << endl;
	cout << "3-������ ����" << endl;

		cin >> num;
		switch (num)
		{
			case(1):
			{
				ifstream file;
				int number;
				file.open("tree.txt");

				if (!file.is_open())
				{
					cout << "������ ��������" << endl;
				}
				while (!file.eof())
				{
					file >> number;
					Add(Root, number);
				}

				Show(Root, 0);
				file.close();
				break;
			}
	
			case(2):
			{
				srand(time(NULL));
				int num, numElem;
				cout << "������� ���-�� ��-�: " << endl;
				cin >> numElem;
				Show(Root, 0);
				for (int i = 0; i < numElem; i++)
				{
					num = rand() % 100;
					Add(Root, num);
				}
				Show(Root, 0);
				break;
			}
			
			case(3):
			{
				int numElem, element;
				cout << "���-�� ��-� ������: " << endl;
				cin >> numElem;
				for (int i = 0; i < numElem; i++)
				{
					cout << i + 1 << " �������:";
					cin >> element;
					cout << endl;
					Add(Root, element);
				}
				Show(Root, 0);
				break;
			}
		}

		cout << "������������ ������� ������: " << MaxElem(Root) << endl;


	DeleteTree(Root);
	system("pause");
	return 0;
}

void DeleteTree(BTree *&root)
{
	if (root != nullptr)
	{
		DeleteTree(root->left);
		DeleteTree(root->right);
		delete root;
		root = nullptr;
	}
}

void Add(BTree *&root, int num)
{
	if (root == nullptr)	//���� ������ ����
	{

		root = new BTree;
		if (root == nullptr) return;	//�������� �� ��������� ������
		root->data = num;
		root->left = root->right = nullptr;
	}
	else
	{
		if (num < root->data)	//���� ������� ������, �� ���� � ����� ����
		{
			if (root->left != nullptr) 
				Add(root->left, num);
			else   //���� ����� ���� ����
			{
				root->left = new BTree;
				if (root->left == nullptr) return;	//�������� �� ��������� ������
				root->left->left = root->left->right = nullptr;
				root->left->data = num;
			}
		}
		if (num > root->data)	//���� ������� ������, �� ���� � ������ ����
		{
			if (root->right != nullptr)
				Add(root->right, num);
			else   //���� ������ ���� ����
			{
				root->right = new BTree;
				if (root->right == nullptr) return;	//�������� �� ��������� ������
				root->right->left = root->right->right = nullptr;
				root->right->data = num;
			}
		}
	}
}

void Show(BTree *&root, int level)
{
	if (root)
	{
		Show(root->right, level + 1);
		for (int i = 0; i < level; i++)
			cout << "   ";
		cout << root->data << endl;
		Show(root->left, level + 1);
	}
}

int Search(BTree *&root, int SElem, int Koll)
{
	if (root == nullptr)
	{
		return -1;
	}
	if (SElem < root->data)
	{
		Search(root->left, SElem, Koll + 1);
	}
	else
		if (SElem > root->data)
		{
			Search(root->right, SElem, Koll + 1);
		}
		else
		{
			return Koll;
		}
}

void DelElem(BTree *&root, int elem) {
	if (root == nullptr)
	{
		return;
	}
	if (elem < root->data)
	{
		DelElem(root->left, elem);
	}
	else
		if (elem > root->data)
		{
			DelElem(root->right, elem);
		}
		else if ((root->left == nullptr) && (root->right == nullptr))
		{
			delete root;
			root = nullptr;
		}
		else
		{
			DeleteTree(root);
		}
}

int MaxElem(BTree *&root) {
	BTree *ptr = root;
	while (ptr->right != nullptr)
		ptr = ptr->right;
	return ptr->data;
}