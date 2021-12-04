/*������� �7. ������� ���� �� 15 ����� �����. �������� ���������, ������� ��������� ����� ��������� ����������� � ���-��������,
���������� �� ������ ������� � ��������. ������� ������, ���������� � ����� � ���-�������. ������� ����������� ���-������� �� �����.
������������ ����� ������ � ���-�������. ���������� ������ ������ ������� �� �����. ����� ������� ���������� ����, ������� ����
��������� ��� ������.*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#define ELEM_NUM 15 //���������� ��������� ���-������� (������ �������������)
using namespace std;

struct list { //��������� ������
	int data;
	struct list *ptr;
};

struct list * addelem(list *lst, int number); //������� ���������� �������� � ������ lst � ������������ data = number
int hashf(int num); //���-������� (�� ��������)
void hesh_search(struct list *hash_table); //������� ������ ����� � ���-�������

int main() {
	setlocale(LC_ALL, "Rus");
	list hash_table[ELEM_NUM];
	for (int i = 0; i < ELEM_NUM; i++) {
		hash_table[i].data = 0;
		hash_table[i].ptr = NULL;
	}
		
	int num; //����������� �����
	int hash; //��� ��������


	ifstream input("input.txt"); 
	if (!input.is_open()) {
		cout << "������ �������� �����";
	}
	else
	{
		while (input.eof() != true) 
		{
			input >> num;
			hash = hashf(num);
			if (hash_table[hash].data == 0)	{ //���� ������ ����, �� ����� data
				hash_table[hash].data = num;
			}
			else { //����� ��������� ������� � ����� ������
				addelem(&hash_table[hash], num);
			}			
		}
		input.close();
	}


	cout << "#hash  " << setw(6) << left << "#_1" //���������� ����� ���-�������
				   << setw(6) << "#_2"
				   << setw(6) << "#_3"
				   << endl;
	list *lptr;
	for (int i = 0; i < ELEM_NUM; i++) 
	{
		lptr = &hash_table[i];
		cout << setw(2) << i << "->   ";
		if (lptr->ptr == NULL) cout << setw(6) << lptr->data << endl;
		else {
			while (lptr->ptr != NULL) {
				cout << setw(6) << lptr->data;
				lptr = lptr->ptr;
			}
			cout << setw(6) << lptr->data << endl;
		}
	}

	hesh_search(hash_table); //����� ������� ������ ��������


	return 0;
}


struct list * addelem(list *lst, int number)
{
	struct list *temp, *p = lst;
	temp = (struct list*)malloc(sizeof(list));
	while (p->ptr != NULL) {
		p = p->ptr;
	}
	p->ptr = temp;

	temp->data = number;
	temp->ptr = NULL;
	return(temp);
}


int hashf(int num) {
	return (num % ELEM_NUM);
}


void hesh_search(struct list *hash_table) {
	int key, hash, count=0;
	struct list *lptr= hash_table;
	cout << "������� �����, ������� ������ �����: ";
	cin >> key;
	hash = hashf(key);
	while (lptr[hash].data != key)
	{
		if (lptr[hash].ptr != NULL) lptr[hash] = *lptr[hash].ptr;
		else {
			cout << "���������� ����� �� ����������!\n";
			return;
		}
		count++;
	}
	count++;
	cout << "\n���-��������: " << hash << "   ���������� ����: " << count << "   ��������� �����: " << lptr[hash].data << endl;
	return;
}