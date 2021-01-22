#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

#define Max 1000

void showHome()
{
	// show home page
	cout << "===================================================" << endl;
	cout << "===\t\t     1、添加联系人     \t\t===" << endl;
	cout << "===\t\t     2、显示联系人     \t\t===" << endl;
	cout << "===\t\t     3、删除联系人     \t\t===" << endl;
	cout << "===\t\t     4、查找联系人     \t\t===" << endl;
	cout << "===\t\t     5、修改联系人     \t\t===" << endl;
	cout << "===\t\t     6、清空联系人     \t\t===" << endl;
	cout << "===\t\t     0、退出通讯录     \t\t===" << endl;
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
	cout << "请输入联系人姓名：" << endl;
	cin >> name;
	s->p_name = name;
	string phone;
	cout << "请输入联系人电话：" << endl;
	cin >> phone;
	s->p_phone = phone;
	string location;
	cout << "请输入联系人地址：" << endl;
	cin >> location;
	s->p_address = location;
	int age;
	cout << "请输入联系人年龄：" << endl;
	cin >> age;
	s->p_age = age;
	int sex;
	cout << "请输入联系人性别：\n 1：男  2：女" << endl;
	cin >> sex;
	s->p_sex = sex;
}

void addPerson(address* s)
{
	if (s->len >= Max)
	{
		cout << "当前通讯录已满，不能添加联系人，即将返回Home菜单……" << endl;
		Sleep(1200);
		system("cls");
		return;
	}
	else
	{
		modifyPerson(&s->personArr[s->len]);
		s->len++;
		cout << "联系人添加成功"<<endl;
		cout << "即将返回Home菜单……" << endl;
		Sleep(1000);
		system("cls");
		return;
	}
}

void printPerson(person* s)
{
	cout << "姓名：" << s->p_name << "\t"
		<< "电话：" << s->p_phone << "\t"
		<< "住址：" << s->p_address << "\t"
		<< "年龄：" << s->p_age << "\t"
		<< "性别：" << (s->p_sex == 1 ? "男" : "女") << "\t"
		<< endl;
}

void showAddress(address* s)
{
	if (s->len == 0)
	{
		cout << "当前通讯录为空，即将返回Home菜单……" << endl;
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
		cout << "当前通讯录为空" << endl;
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
		cout << "当前通讯录不存在要删除的用户，即将返回Home菜单……" << endl;
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
	cout << "联系人" << name << "已经删除" << endl;
	system("pause");
	system("cls");
}

void options(address * s)
{
	while (true)
	{
		// home page选择要进行的操作
		int select = 0;
		showHome();
		cin >> select;
		switch (select)
		{
		case 1:
		{
			// 添加联系人
			addPerson(s);
			break;
		};
		case 2:
		{
			// 显示联系人
			showAddress(s);
			break;
		};
		case 3:
		{
			string name;
			cout << "输入要删除的联系人姓名：" << endl;
			cin >> name;
			int index = existPerson(s, name);
			deletePerson(s, index);
			break;
		}
		case 4:
		{
			// 查找联系人
			string name;
			cout << "输入查找的联系人姓名：" << endl;
			cin >> name;
			int index = existPerson(s, name);
			if (index == -1)
			{
				cout << "联系人"<< name << "不存在" << endl;
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
			// 修改联系人
			string name;
			cout << "输入要修改的联系人姓名：" << endl;
			cin >> name;
			int index = existPerson(s, name);
			if (index == -1)
			{
				cout << "联系人" << name << "不存在" << endl;
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
			// 清空联系人
			s->len = 0;
			cout << "已经清空通讯录" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 0:
		{
			int out = 0;
			cout << "您将要退出通讯录系统，输入\033[33m 1 \033[0m确认退出，输入 0 返回主界面" << endl;
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
				cout << "您输入的信息有误，即将返回Home菜单……" << endl;
				Sleep(1200);
				system("cls");
			}
			break;
		}

		default:
		{
			cout << "输入无效字符，请重新输入：" << endl;
			break;
		}
		}
	}
	
}


int main() 
{
	// 创建通讯录结构体变量
	struct address ads;

	// 进入Home界面进行操作
	options(&ads);
	system("pause");
	return 0;
}