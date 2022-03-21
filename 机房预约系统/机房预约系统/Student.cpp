#include "Student.h"

Student::Student()
{
	m_Id = 0;
}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	ComputerRoom com;
	ifstream ifs;//初始化机房信息
	ifs.open(COMPUTER_FILE, ios::in);
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.emplace_back(com);//将读取的信息放入到 容器中
	}
	ifs.close();
}

void Student::operMenu()
{
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Student::applyOrder()
{
	cout << "请输入预约时间，1~5为周一到周五" << endl;
	int date = 0;
	int interval = 0;//上下午
	int room = 0;
	while (true)
	{
		cin >> date;
		if (date <= 5 && date >= 1)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "请输入时间段，1为上午，2为下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval <= 2 && interval >= 1)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "请选择机房:" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "号机房容量：" << vCom[i].m_MaxNum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room <= 3 && room >= 1)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " "
		<< "interval:" << interval << " "
		<< "stuId:" << this->m_Id << " "
		<< "stuName:" << this->m_Name << " "
		<< "roomId:" << room << " "
		<< "status:" << 1 << endl;
	ofs.close();
	cout << "预约成功,审核中" << endl;

	system("pause");
	system("cls");
}

void Student::showMyOrder()
{
	OrderFile of;
	if (!of.m_Size)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	for (int i = 0; i < of.m_Size; i++)
	{
		// string  转 int
		// string 利用 .c_str() 转 const char *
		//利用 atoi ( const char *) 转 int
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) //找到自身预约
		{
			cout << "预约日期： 周" << of.m_orderData[i]["date"];
			cout << " 时间段： " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房号： " << of.m_orderData[i]["roomId"];
			string status = "状态： ";
			// 1 审核中  2 已预约  -1 预约失败  0 取消预约
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "预约失败，审核未通过";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}

	system("pause");
	system("cls");
}

void Student::showAllOrder()
{
	OrderFile of;
	if (!of.m_Size)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、 ";
		cout << "预约日期： 周" << of.m_orderData[i]["date"];
		cout << " 时间段： " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号： " << of.m_orderData[i]["stuId"];
		cout << " 姓名： " << of.m_orderData[i]["stuName"];
		cout << " 机房编号： " << of.m_orderData[i]["roomId"];
		string status = " 状态：";
		// 1 审核中 2 已预约  -1预约失败  0 取消预约
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败，审核未通过";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

void Student::cancelOrder()
{
	OrderFile of;
	if (!of.m_Size)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核或预约成功的记录可以取消，请输入要取消的记录" << endl;
	int index = 1;
	vector<int>v; //存放在最大容器中的下标编号,也就是第几条
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.emplace_back(i);
				cout << index++ << "、 ";
				cout << "预约日期： 周" << of.m_orderData[i]["date"];
				cout << " 时间段： " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房编号： " << of.m_orderData[i]["roomId"];
				string status = " 状态： ";
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录，0代表返回" << endl;
	int select = 0;

	while (true)
	{
		cin >> select;

		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] = "0";

				of.updateOrder();

				cout << "已取消预约" << endl;
				break;
			}
		}

		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
}
