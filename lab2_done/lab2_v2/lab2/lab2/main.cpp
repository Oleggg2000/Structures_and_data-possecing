#include <iostream>
#include <ostream>
using namespace std;

struct Node //�������/���� �������
{
	char *data; 
	Node *next;
};
struct Queue //�������� �������
{
	int size;
	Node *first; 
	Node *last;
};

void Add(Queue *Q, char *value);
void Delete(Queue *Q);
char *Top(Queue *Q);
int Size(Queue *Q);
void Init(Queue *Q);
bool Full(Queue *Q);
void func(Queue *Q);


int main()
{
	system("chcp 1251");
	Queue Q;
	Init(&Q);
	int number;
	do
	{
		cout << "1) �������� ��-�" << endl;
		cout << "2) ������� ��-�" << endl;
		cout << "3) ������� ������� ��-�" << endl;
		cout << "4) ������ ������ �������" << endl;
		cout << "5) ������� � ��������" << endl;
		cout << "0) Stop\n\n";
		cout << "������� �: "; 
		cin >> number;
		switch (number)
		{
			case 1: {
				char *txt= new char;
				cin >> txt;
				Add(&Q, txt);
				break;
			}

			case 2: {
				if (Full(&Q)) cout << endl << "������� �����\n\n";
				else Delete(&Q);
				break;
			}

			case 3: {
				if (Full(&Q)) cout << endl << "������� �����\n\n";
				else {
					cout << "\n��������� �������: " << Top(&Q) << "\n\n";
				}
				break;
			}

			case 4: {
				if (Full(&Q)) cout << endl << "������� �����\n\n";
				else cout << "\n������ �������: " << Size(&Q) << "\n\n";
				break;
			}

			case 5: {
				func(&Q);
				break;
			}

			case 0: break;
		}
	} while (number != 0);

	while (Q.size != 0) //�������� ������ �� �������
	{
		if ((Q.first != Q.last))
			Delete(&Q);
		else
		{
			delete Q.first->next;
			delete Q.first;
			Q.size--;
		}
	}
	return 0;
	system("pause");
}

void Init(Queue *Q) //�������� �������
{
	Q->last = Q->first = new Node;
	Q->last->next = Q->first->next = NULL;
	Q->size = 0;
}

bool Full(Queue *Q) //�������� ������� �� �������
{
	if ((Q->first == Q->last) && (Q->size == 0)) return true;
	else return false;
}

char *Top(Queue *Q) //����� ���������� ��������
{
	return Q->first->data;
}

void Add(Queue *Q, char *value) //���������� ��������
{
	Node *temp = new Node;
	Q->last->next = temp;
	temp->data = value;
	temp->next = NULL;
	Q->last = temp;
	//temp->next = Q->first;
	//temp->data = value;
	//Q->first = temp;
	if (Q->size == 0) Q->last = Q->first;
	Q->size++;
	cout << "\n������� ��������\n\n";
}
void Delete(Queue *Q) //�������� ��������
{
	Node *temp;
	temp = Q->first;
	//while (temp->next != Q->last) temp = temp->next;
	//delete Q->last;
	////Q->last = new Node;
	//temp->next->next = NULL;
	//Q->last = temp;
	Q->first = Q->first->next;
	delete temp;
	Q->size--;
	cout << "\n������� ������\n\n";
}

int Size(Queue *Q) //������ �������
{
	return Q->size;
}


void func(Queue *Q) {
	FILE *file = fopen("F.txt", "r+"), *fileG= fopen("g.txt", "w+");
	char buf[100], temp, num[10] = {'0','1','2','3','4','5','6','7','8','9'};
	int j = 0, k, count;
	while (!feof(file))
	{
		fgets(buf, 100, file);
		count = strlen(buf);
		while (count>0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (buf[j] == num[i])
				{
					temp = buf[j];
					for (k = j; k < strlen(buf)-1; k++)
						buf[k] = buf[k + 1];
					buf[strlen(buf) - 2] = temp;
					count = count - 2;
					//buf[k] = '\0';
				}
			}
			j++;
			count--;
		}
		fprintf(fileG, "%s", buf);
		j = 0;
	}
	fclose(file);
	fclose(fileG);
}