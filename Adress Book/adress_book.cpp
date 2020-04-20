#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

//��ϵ�˽ṹ��
struct Person
{
	string Name;	//����
	string Sex;		//�Ա�
	int Age;		//����
	string PhoneNum;//�绰����
	string Adress;	//��ͥסַ
};
//ͨѶ¼�ṹ��
struct AdressBooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼����ϵ�˸���
	int Size;
};

//�����ϵ���Ƿ���ڣ�������򷵻�λ��
//����1��ͨѶ¼������2����Ҫ��������
int IfExit(AdressBooks *pers,string name)
{
	for (int i = 0; i < pers->Size; i++)
	{
		if (pers->personArray[i].Name == name)
		{
			return i;	//�ҵ��˷���λ��
		}
	}
	return -1;	//���û���ҵ��ͷ���-1
}
//�˵���ʾ����
void ShowMenu()
{
	cout << "*************************************" << endl;
	cout << "*****\t\t\t\t*****" << endl;
	cout << "*****\t1�������ϵ��\t\t*****" << endl;
	cout << "*****\t2����ʾ������ϵ��\t*****" << endl;
	cout << "*****\t3��ɾ����ϵ��\t\t*****" << endl;
	cout << "*****\t4��������ϵ��\t\t*****" << endl;
	cout << "*****\t5���޸���ϵ��\t\t*****" << endl;
	cout << "*****\t6�������ϵ���б�\t*****" << endl;
	cout << "*****\t0���˳�ͨѶ¼\t\t*****" << endl;
	cout << "*****\t\t\t\t*****" << endl;
	cout << "*************************************" << endl;
}
//1�������ϵ��
void AddPerson(AdressBooks *pers)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (pers->Size == MAX)
	{
		cout << "ͨѶ¼�������޷�������ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		//����
		cout << "������������" << endl;
		cin >> pers->personArray[pers->Size].Name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cin >> pers->personArray[pers->Size].Sex;
		//����
		cout << "���������䣺" << endl;
		cin >> pers->personArray[pers->Size].Age;
		//�绰����
		cout << "������绰���룺" << endl;
		cin >> pers->personArray[pers->Size].PhoneNum;
		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		cin >> pers->personArray[pers->Size].Adress;
		//������һ
		pers->Size++;
		//��ʾ�½���ϵ�˳ɹ�
		cout << "�½���ϵ�˳ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//2����ʾ������ϵ��
void ShowPerson(AdressBooks *pers)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0
	if (pers->Size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < pers->Size; i++)
		{
			cout << "������" << pers->personArray[i].Name
				 << "\t�Ա�" << pers->personArray[i].Sex
				 << "\t���䣺" << pers->personArray[i].Age
				 << "\t�绰����" << pers->personArray[i].PhoneNum
				 << "\t��ͥסַ" << pers->personArray[i].Adress << endl;
		}
	}
	system("pause");
	system("cls");	//�����Ļ
}
//3��ɾ����ϵ��
void DelPerson(AdressBooks *pers)
{
	string name;
	cout << "������Ҫɾ����ϵ�˵�������" << endl;
	cin >> name;
	//�����ϵ���Ƿ����
	int ret = IfExit(pers, name);
	if (ret == -1)	//δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}
	else
	{
		//�鵽���ˣ�����ɾ��
		for (int i = ret; i < pers->Size; i++)
		{
			pers->personArray[i] = pers->personArray[i + 1];
		}
		//��ȥ����
		pers->Size--;
		//��ʾ��ɾ����ϵ��
		cout << "��ɾ����ϵ�ˣ�" << endl;
	}
	system("pause");
	system("cls");
}
//4��������ϵ��
void FindPerson(AdressBooks *pers)
{
	string name;
	cout << "������Ҫ���ҵ���ϵ�����֣�" << endl;
	cin >> name;
	//�����ϵ���Ƿ����
	int ret = IfExit(pers, name);
	if (ret != -1)	//�ҵ���ϵ��
	{
		cout << "������" << pers->personArray[ret].Name
			<< "\t�Ա�" << pers->personArray[ret].Sex
			<< "\t���䣺" << pers->personArray[ret].Age
			<< "\t�绰����" << pers->personArray[ret].PhoneNum
			<< "\t��ͥסַ" << pers->personArray[ret].Adress << endl;
	}
	else	//δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void ChangePerson(AdressBooks *pers)
{
	string name;
	cout << "������Ҫ�޸ĵ���ϵ�����֣�" << endl;
	cin >> name;
	//�����ϵ���Ƿ����
	int ret = IfExit(pers, name);
	if (ret == -1)	//δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}
	else	//�ҵ���ϵ��
	{
		//�޸���ϵ��
		//����
		cout << "������������" << endl;
		cin >> pers->personArray[ret].Name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cin >> pers->personArray[ret].Sex;
		//����
		cout << "���������䣺" << endl;
		cin >> pers->personArray[ret].Age;
		//�绰����
		cout << "������绰���룺" << endl;
		cin >> pers->personArray[ret].PhoneNum;
		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		cin >> pers->personArray[ret].Adress;
		//��ʾ�޸����
		cout << "��ϵ�����޸���ɣ�" << endl;
	}
	system("pause");
	system("cls");
}
//6�������ϵ���б�
void ClearList(AdressBooks *pers)
{
	pers->Size = 0;
	cout << "ͨѶ¼����գ�" << endl;
	system("pause");
	system("cls");
}

int main()
{
	
	int select = 0;//�����û��������
	//����ͨѶ¼�ṹ�����
	AdressBooks pers;
	//��ʼ��ͨѶ¼�ṹ��
	pers.Size = 0;

	while (true)
	{
		
		//�˵�����
		ShowMenu();
		cin >> select;
		switch (select)
		{
		case 1: //1�������ϵ��
			AddPerson(&pers);
			break;
		case 2: //2����ʾ������ϵ��
			ShowPerson(&pers);
			break;
		case 3: //3��ɾ����ϵ��
			DelPerson(&pers);
			break;
		case 4: //4��������ϵ��
			FindPerson(&pers);
			break;
		case 5: //5���޸���ϵ��
			ChangePerson(&pers);
			break;
		case 6: //6�������ϵ���б�
			ClearList(&pers);
			break;
		case 0: //0���˳�ͨѶ¼
			cout << "���򼴽��˳�\n��ӭ�ٴ�ʹ��" << endl;
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