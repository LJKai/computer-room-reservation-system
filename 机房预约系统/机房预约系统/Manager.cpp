#include "Manager.h"

Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector(); //获取所有文件中老师和学生的信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in); //初始化机房的信息
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Manager::addPerson()
{
	cout << "请输入添加账号的类型，1为学生，2为老师" << endl;
	string fileName; //操作的文件名
	string tip;	//提示ID号
	string errorTip; //输入重复的错误提示
	ofstream ofs;
	int select = 0; //接受用户的选项
	cin >> select;

	if (select == 1)
	{	
		/*添加的是学生*/
		fileName = STUDENT_FILE;
		tip = "请输入学号";
		errorTip = "学号重复，请重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号";
		errorTip = "职工号重复，请重新输入";
	}

	ofs.open(fileName, ios::out | ios::app);//以追加的方式写文件

	int id = 0;
	string name;
	string pwd;
	
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)//有重复
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;//向文件中添加数据
	cout << "添加成功" << endl;

	system("pause");
	system("cls");
	ofs.close();
	this->initVector();//调用初始化容器接口，从新获取文件中的数据
}

void printStudent(Student& s)
{
	cout << "学号：" << s.m_Id << " 姓名:" << s.m_Name << " 密码:" << s.m_Pwd << endl;
}

void printTeacher(Teacher& s)
{
	cout << "职工号:" << s.m_EmpId << " 姓名:" << s.m_Name << " 密码:" << s.m_Pwd << endl;
}

void printComputerRoom(ComputerRoom& s)
{
	cout << "机房编号：" << s.m_ComId << " 机房最大容量：" << s.m_MaxNum << endl;
}

void Manager::showPerson()
{
	cout << "选择查看内容，1学生，2老师" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有老师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for_each(vCom.begin(), vCom.end(), printComputerRoom);
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	vStu.clear();
	vTea.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "学生文件读取失败" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "老师文件读取失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}
