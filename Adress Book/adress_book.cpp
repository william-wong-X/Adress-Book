#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

//联系人结构体
struct Person
{
	string Name;	//姓名
	string Sex;		//性别
	int Age;		//年龄
	string PhoneNum;//电话号码
	string Adress;	//家庭住址
};
//通讯录结构体
struct AdressBooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录的联系人个数
	int Size;
};

//检测联系人是否存在，如存在则返回位置
//参数1：通讯录，参数2：需要检测的姓名
int IfExit(AdressBooks *pers,string name)
{
	for (int i = 0; i < pers->Size; i++)
	{
		if (pers->personArray[i].Name == name)
		{
			return i;	//找到了返回位置
		}
	}
	return -1;	//如果没有找到就返回-1
}
//菜单显示界面
void ShowMenu()
{
	cout << "*************************************" << endl;
	cout << "*****\t\t\t\t*****" << endl;
	cout << "*****\t1、添加联系人\t\t*****" << endl;
	cout << "*****\t2、显示所有联系人\t*****" << endl;
	cout << "*****\t3、删除联系人\t\t*****" << endl;
	cout << "*****\t4、查找联系人\t\t*****" << endl;
	cout << "*****\t5、修改联系人\t\t*****" << endl;
	cout << "*****\t6、清空联系人列表\t*****" << endl;
	cout << "*****\t0、退出通讯录\t\t*****" << endl;
	cout << "*****\t\t\t\t*****" << endl;
	cout << "*************************************" << endl;
}
//1、添加联系人
void AddPerson(AdressBooks *pers)
{
	//判断通讯录是否已满
	if (pers->Size == MAX)
	{
		cout << "通讯录已满，无法继续添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人
		//姓名
		cout << "请输入姓名：" << endl;
		cin >> pers->personArray[pers->Size].Name;
		//性别
		cout << "请输入性别：" << endl;
		cin >> pers->personArray[pers->Size].Sex;
		//年龄
		cout << "请输入年龄：" << endl;
		cin >> pers->personArray[pers->Size].Age;
		//电话号码
		cout << "请输入电话号码：" << endl;
		cin >> pers->personArray[pers->Size].PhoneNum;
		//家庭住址
		cout << "请输入家庭住址：" << endl;
		cin >> pers->personArray[pers->Size].Adress;
		//人数加一
		pers->Size++;
		//提示新建联系人成功
		cout << "新建联系人成功" << endl;
	}
	system("pause");
	system("cls");
}
//2、显示所有联系人
void ShowPerson(AdressBooks *pers)
{
	//判断通讯录中人数是否为0
	if (pers->Size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < pers->Size; i++)
		{
			cout << "姓名：" << pers->personArray[i].Name
				 << "\t性别：" << pers->personArray[i].Sex
				 << "\t年龄：" << pers->personArray[i].Age
				 << "\t电话号码" << pers->personArray[i].PhoneNum
				 << "\t家庭住址" << pers->personArray[i].Adress << endl;
		}
	}
	system("pause");
	system("cls");	//清空屏幕
}
//3、删除联系人
void DelPerson(AdressBooks *pers)
{
	string name;
	cout << "请输入要删除联系人的姓名：" << endl;
	cin >> name;
	//检查联系人是否存在
	int ret = IfExit(pers, name);
	if (ret == -1)	//未找到联系人
	{
		cout << "查无此人" << endl;
	}
	else
	{
		//查到此人，进行删除
		for (int i = ret; i < pers->Size; i++)
		{
			pers->personArray[i] = pers->personArray[i + 1];
		}
		//减去人数
		pers->Size--;
		//显示已删除联系人
		cout << "已删除联系人！" << endl;
	}
	system("pause");
	system("cls");
}
//4、查找联系人
void FindPerson(AdressBooks *pers)
{
	string name;
	cout << "请输入要查找的联系人名字：" << endl;
	cin >> name;
	//检查联系人是否存在
	int ret = IfExit(pers, name);
	if (ret != -1)	//找到联系人
	{
		cout << "姓名：" << pers->personArray[ret].Name
			<< "\t性别：" << pers->personArray[ret].Sex
			<< "\t年龄：" << pers->personArray[ret].Age
			<< "\t电话号码" << pers->personArray[ret].PhoneNum
			<< "\t家庭住址" << pers->personArray[ret].Adress << endl;
	}
	else	//未找到联系人
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void ChangePerson(AdressBooks *pers)
{
	string name;
	cout << "请输入要修改的联系人名字：" << endl;
	cin >> name;
	//检查联系人是否存在
	int ret = IfExit(pers, name);
	if (ret == -1)	//未找到联系人
	{
		cout << "查无此人" << endl;
	}
	else	//找到联系人
	{
		//修改联系人
		//姓名
		cout << "请输入姓名：" << endl;
		cin >> pers->personArray[ret].Name;
		//性别
		cout << "请输入性别：" << endl;
		cin >> pers->personArray[ret].Sex;
		//年龄
		cout << "请输入年龄：" << endl;
		cin >> pers->personArray[ret].Age;
		//电话号码
		cout << "请输入电话号码：" << endl;
		cin >> pers->personArray[ret].PhoneNum;
		//家庭住址
		cout << "请输入家庭住址：" << endl;
		cin >> pers->personArray[ret].Adress;
		//显示修改完成
		cout << "联系人以修改完成！" << endl;
	}
	system("pause");
	system("cls");
}
//6、清空联系人列表
void ClearList(AdressBooks *pers)
{
	pers->Size = 0;
	cout << "通讯录已清空！" << endl;
	system("pause");
	system("cls");
}

int main()
{
	
	int select = 0;//创建用户输入变量
	//创建通讯录结构体变量
	AdressBooks pers;
	//初始化通讯录结构体
	pers.Size = 0;

	while (true)
	{
		
		//菜单调用
		ShowMenu();
		cin >> select;
		switch (select)
		{
		case 1: //1、添加联系人
			AddPerson(&pers);
			break;
		case 2: //2、显示所有联系人
			ShowPerson(&pers);
			break;
		case 3: //3、删除联系人
			DelPerson(&pers);
			break;
		case 4: //4、查找联系人
			FindPerson(&pers);
			break;
		case 5: //5、修改联系人
			ChangePerson(&pers);
			break;
		case 6: //6、清空联系人列表
			ClearList(&pers);
			break;
		case 0: //0、退出通讯录
			cout << "程序即将退出\n欢迎再次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}