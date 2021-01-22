#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

#define Max 1000

void showHome()
{
	// show home page
	cout << "===================================================" << endl;
	cout << "===\t\t     1�������ϵ��     \t\t===" << endl;
	cout << "===\t\t     2����ʾ��ϵ��     \t\t===" << endl;
	cout << "===\t\t     3��ɾ����ϵ��     \t\t===" << endl;
	cout << "===\t\t     4��������ϵ��     \t\t===" << endl;
	cout << "===\t\t     5���޸���ϵ��     \t\t===" << endl;
	cout << "===\t\t     6�������ϵ��     \t\t===" << endl;
	cout << "===\t\t     0���˳�ͨѶ¼     \t\t===" << endl;
	cout << "===================================================" << endl;
}

struct person
{
	string p_name;
	string p_phone;
	string p_address;
	int p_age = 0;
	int p_sex = 1;
};

struct address
{
	int len = 0;
	struct person personArr[Max];
};

void modifyPerson(person* s)
{
	string name;
	cout << "��������ϵ��������" << endl;
	cin >> name;
	s->p_name = name;
	string phone;
	cout << "��������ϵ�˵绰��" << endl;
	cin >> phone;
	s->p_phone = phone;
	string location;
	cout << "��������ϵ�˵�ַ��" << endl;
	cin >> location;
	s->p_address = location;
	int age;
	cout << "��������ϵ�����䣺" << endl;
	cin >> age;
	s->p_age = age;
	int sex;
	cout << "��������ϵ���Ա�\n 1����  2��Ů" << endl;
	cin >> sex;
	s->p_sex = sex;
}

void addPerson(address* s)
{
	if (s->len >= Max)
	{
		cout << "��ǰͨѶ¼���������������ϵ�ˣ���������Home�˵�����" << endl;
		Sleep(1200);
		system("cls");
		return;
	}
	else
	{
		modifyPerson(&s->personArr[s->len]);
		s->len++;
		cout << "��ϵ����ӳɹ�"<<endl;
		cout << "��������Home�˵�����" << endl;
		Sleep(1000);
		system("cls");
		return;
	}
}

void printPerson(person* s)
{
	cout << "������" << s->p_name << "\t"
		<< "�绰��" << s->p_phone << "\t"
		<< "סַ��" << s->p_address << "\t"
		<< "���䣺" << s->p_age << "\t"
		<< "�Ա�" << (s->p_sex == 1 ? "��" : "Ů") << "\t"
		<< endl;
}

void showAddress(address* s)
{
	if (s->len == 0)
	{
		cout << "��ǰͨѶ¼Ϊ�գ���������Home�˵�����" << endl;
		Sleep(1200);
		system("cls");
		return;
	}
	else {
		for (int i = 0; i < s->len; i++)
		{
			printPerson(&s->personArr[i]);
		}
		system("pause");
		system("cls");
	}
}

int existPerson(address* s, string name)
{
	if (s->len == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��" << endl;
		return -1;
	}
	else {
		for (int i = 0; i < s->len; i++)
		{
			if (s->personArr[i].p_name == name)
			{
				return i;
			}
		}
		return -1;
	}
}

void deletePerson(address* s, int index)
{
	if (index == -1)
	{
		cout << "��ǰͨѶ¼������Ҫɾ�����û�����������Home�˵�����" << endl;
		Sleep(1200);
		system("cls");
		return;
	}
	string name = s->personArr[index].p_name;
	for (int i = index; i < s->len; i++)
	{
		if (i == s->len - 1)
		{
			struct person temp;
			s->personArr[i] = temp;
		}
		else
		{
			s->personArr[i] = s->personArr[i + 1];
		}
	}
	s->len--;
	cout << "��ϵ��" << name << "�Ѿ�ɾ��" << endl;
	system("pause");
	system("cls");
}

void options(address * s)
{
	while (true)
	{
		// home pageѡ��Ҫ���еĲ���
		int select = 0;
		showHome();
		cin >> select;
		switch (select)
		{
		case 1:
		{
			// �����ϵ��
			addPerson(s);
			break;
		};
		case 2:
		{
			// ��ʾ��ϵ��
			showAddress(s);
			break;
		};
		case 3:
		{
			string name;
			cout << "����Ҫɾ������ϵ��������" << endl;
			cin >> name;
			int index = existPerson(s, name);
			deletePerson(s, index);
			break;
		}
		case 4:
		{
			// ������ϵ��
			string name;
			cout << "������ҵ���ϵ��������" << endl;
			cin >> name;
			int index = existPerson(s, name);
			if (index == -1)
			{
				cout << "��ϵ��"<< name << "������" << endl;
				system("pause");
				system("cls");
				break;
			}
			printPerson(&s->personArr[index]);
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			// �޸���ϵ��
			string name;
			cout << "����Ҫ�޸ĵ���ϵ��������" << endl;
			cin >> name;
			int index = existPerson(s, name);
			if (index == -1)
			{
				cout << "��ϵ��" << name << "������" << endl;
				system("pause");
				system("cls");
				break;
			}
			printPerson(&s->personArr[index]);

			modifyPerson(&s->personArr[index]);
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			// �����ϵ��
			s->len = 0;
			cout << "�Ѿ����ͨѶ¼" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 0:
		{
			int out = 0;
			cout << "����Ҫ�˳�ͨѶ¼ϵͳ������\033[33m 1 \033[0mȷ���˳������� 0 ����������" << endl;
			cin >> out;

			if (out == 0)
			{
				system("cls");
				break;
			}
			else if (out == 1)
			{
				return;
			}
			else
			{
				cout << "���������Ϣ���󣬼�������Home�˵�����" << endl;
				Sleep(1200);
				system("cls");
			}
			break;
		}

		default:
		{
			cout << "������Ч�ַ������������룺" << endl;
			break;
		}
		}
	}
	
}


int main() 
{
	// ����ͨѶ¼�ṹ�����
	struct address ads;

	// ����Home������в���
	options(&ads);
	system("pause");
	return 0;
}