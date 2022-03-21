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
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void managerMenu(Identity* &manager)/*指针指向引用*/
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
			cout << "清空预约" << endl;
			man->cleanFile();
		}
			break;
		default:
			delete manager;
			cout << "注销成功" << endl;
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
			cout << "注销成功" << endl;
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
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	
	switch (type)
	{
	case 1:
	{
		int fId = 0;
		string fName;
		string fPwd;
		/*TXT文件编码格式要改为ANSI*/
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生登录验证成功" << endl;
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
		/*TXT文件编码格式要改为ANSI*/
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师登录验证成功" << endl;
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
		/*TXT文件编码格式要改为ANSI*/
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员登录验证成功" << endl;
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
	
	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;
}

int main() {
	int select = 0;
	while (true)
	{
		cout << "======================  欢迎来到机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select;

		switch (select)
		{
		case 1:/*学生*/
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:/*老师*/
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:/*管理员*/
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:/*退出*/
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}