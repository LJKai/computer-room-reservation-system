#include <iostream>
#include <fstream>
#include <string>
#include "globalFile.h"
#include "Identity.h"
#include "Manager.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;

void studentMenu(Identity* &student)
{
	while (true)
	{
		student->operMenu();

		Student* stu = dynamic_cast<Student*>(student);

		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
		{
			stu->applyOrder();
		}
		break;
		case 2:
		{
			stu->showMyOrder();
		}
		break;
		case 3:
		{
			stu->showAllOrder();
		}
		break;
		case 4:
		{
			stu->cancelOrder();
		}
		break;
		default:
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void managerMenu(Identity* &manager)/*ָ��ָ������*/
{
	while (true)
	{
		manager->operMenu();

		Manager* man = dynamic_cast<Manager*>(manager);

		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
		{
			man->addPerson();
		}
			break;
		case 2:
		{
			man->showPerson();
		}
			break;
		case 3:
		{
			man->showComputer();
		}
			break;
		case 4:
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
			break;
		default:
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void teacherMenu(Identity* &teacher)
{
	while (true)
	{
		teacher->operMenu();
		Teacher* tea = dynamic_cast<Teacher*>(teacher);
		int select = 0;
		cin >> select;
		
		if (select == 1)
		{
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LoginIn(string fileName, int type)
{
	Identity* person = nullptr;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;
	
	switch (type)
	{
	case 1:
	{
		int fId = 0;
		string fName;
		string fPwd;
		/*TXT�ļ������ʽҪ��ΪANSI*/
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����¼��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}
		break;
	case 2:
	{
		int fId = 0;
		string fName;
		string fPwd;
		/*TXT�ļ������ʽҪ��ΪANSI*/
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��¼��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}
		break;
	case 3:
	{
		string fName;
		string fPwd;
		/*TXT�ļ������ʽҪ��ΪANSI*/
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��¼��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
		break;	
	}
	
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}

int main() {
	int select = 0;
	while (true)
	{
		cout << "======================  ��ӭ��������ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select;

		switch (select)
		{
		case 1:/*ѧ��*/
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:/*��ʦ*/
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:/*����Ա*/
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:/*�˳�*/
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}