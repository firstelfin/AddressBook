<p>
    <center><h1>AddressBook</h1></center>
	<br />
    <p align="center">
        <b>Author：&nbsp;<a href="https://github.com/firstelfin">elfin</a></b>
	</p>
</p>

---

<p name="top" id="top" >
    Basic cases of C + + Learning.
	<br />
    <b><h2>&nbsp;&nbsp;目录</h2></b>
</p>

*   <a href="https://github.com/firstelfin/AddressBook/blob/master/README.md#1%E5%88%9B%E5%BB%BA%E9%A6%96%E9%A1%B5"><b>1、创建首页</b></a>

*   **[2、创建person结构体、address结构体](#2、创建person结构体、address结构体)**

*   **[3、创建Home页面的选择函数](#3、创建Home页面的选择函数)**

*   **[4、添加成员修改函数](#4、添加成员修改函数)**

*   **[5、添加联系人](#5、添加联系人)**

*   **[6、打印联系人信息函数](#6、打印联系人信息函数)**

*   **[7、显示联系人](#7、显示联系人)**

*   **[8、检测联系人是否存在](#8、检测联系人是否存在)**

*   **[9、main函数](#9、main函数)**

    

---

## 1、创建首页 ##

```c++
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
```

这里的每个选项本来是使用了字体颜色的，但是生成的exe文件不能显示，所有去掉了相应的代码！

---

<p align="right">
    <b></b><a href="#top">Top</a></b>
	&nbsp;<b>---</b>&nbsp;
	<b></b><a href="#bottom">Bottom</a></b>
</p>

## 2、创建person结构体、address结构体 ##

**<font color=blue>person结构体</font>**：

```c++
struct person
{
	string p_name;
	string p_phone;
	string p_address;
	int p_age = 0;
	int p_sex = 1;
};
```

**<font color=blue>address结构体</font>**：

```c++
#define Max 1000

struct address
{
	int len = 0;
	struct person personArr[Max];
};
```

这里对通讯录的最大容量使用了宏变量进行定义！

---

<p align="right">
    <b></b><a href="#top">Top</a></b>
	&nbsp;<b>---</b>&nbsp;
	<b></b><a href="#bottom">Bottom</a></b>
</p>

## 3、创建Home页面的选择函数 ##

```c++
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
```

这一步实际上是搭好项目的框架，每个case的代码块是需要逐步完成的！

---

<p align="right">
    <b></b><a href="#top">Top</a></b>
	&nbsp;<b>---</b>&nbsp;
	<b></b><a href="#bottom">Bottom</a></b>
</p>

## 4、添加成员修改函数 ##

```c++
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
```

先写这个函数实际上是为添加联系人做准备，因为其修改部分代码一样！

---

<p align="right">
    <b></b><a href="#top">Top</a></b>
	&nbsp;<b>---</b>&nbsp;
	<b></b><a href="#bottom">Bottom</a></b>
</p>

## 5、添加联系人 ##

```c++
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
```

结合选择函数的case完成添加联系人的操作！

---

<p align="right">
    <b></b><a href="#top">Top</a></b>
	&nbsp;<b>---</b>&nbsp;
	<b></b><a href="#bottom">Bottom</a></b>
</p>

## 6、打印联系人信息函数 ##

```c++
void printPerson(person* s)
{
	cout << "姓名：" << s->p_name << "\t"
		<< "电话：" << s->p_phone << "\t"
		<< "住址：" << s->p_address << "\t"
		<< "年龄：" << s->p_age << "\t"
		<< "性别：" << (s->p_sex == 1 ? "男" : "女") << "\t"
		<< endl;
}
```

---

<p align="right">
    <b></b><a href="#top">Top</a></b>
	&nbsp;<b>---</b>&nbsp;
	<b></b><a href="#bottom">Bottom</a></b>
</p>

## 7、显示联系人 ##

```c++
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
```

---

<p align="right">
    <b></b><a href="#top">Top</a></b>
	&nbsp;<b>---</b>&nbsp;
	<b></b><a href="#bottom">Bottom</a></b>
</p>

## 8、检测联系人是否存在 ##

```c++
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
```

---

<p align="right">
    <b></b><a href="#top">Top</a></b>
	&nbsp;<b>---</b>&nbsp;
	<b></b><a href="#bottom">Bottom</a></b>
</p>

## 9、main函数 ##

```c++
int main() 
{
	// 创建通讯录结构体变量
	struct address ads;

	// 进入Home界面进行操作
	options(&ads);
	system("pause");
	return 0;
}
```

---

<p align="right">
    <b></b><a href="#top">Top</a></b>
	&nbsp;<b>---</b>&nbsp;
	<b></b><a href="#bottom">Bottom</a></b>
</p>



关于首页菜单选项中的未提及选项请参考options函数！

---
<p align="left" name="bottom" id="bottom">
    完！
</p>

