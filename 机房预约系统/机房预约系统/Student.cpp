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
	ifstream ifs;//��ʼ��������Ϣ
	ifs.open(COMPUTER_FILE, ios::in);
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.emplace_back(com);//����ȡ����Ϣ���뵽 ������
	}
	ifs.close();
}

void Student::operMenu()
{
	cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Student::applyOrder()
{
	cout << "������ԤԼʱ�䣬1~5Ϊ��һ������" << endl;
	int date = 0;
	int interval = 0;//������
	int room = 0;
	while (true)
	{
		cin >> date;
		if (date <= 5 && date >= 1)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "������ʱ��Σ�1Ϊ���磬2Ϊ����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval <= 2 && interval >= 1)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "��ѡ�����:" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "�Ż���������" << vCom[i].m_MaxNum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room <= 3 && room >= 1)
		{
			break;
		}
		cout << "������������������" << endl;
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
	cout << "ԤԼ�ɹ�,�����" << endl;

	system("pause");
	system("cls");
}

void Student::showMyOrder()
{
	OrderFile of;
	if (!of.m_Size)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	for (int i = 0; i < of.m_Size; i++)
	{
		// string  ת int
		// string ���� .c_str() ת const char *
		//���� atoi ( const char *) ת int
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) //�ҵ�����ԤԼ
		{
			cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
			cout << " ʱ��Σ� " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " �����ţ� " << of.m_orderData[i]["roomId"];
			string status = "״̬�� ";
			// 1 �����  2 ��ԤԼ  -1 ԤԼʧ��  0 ȡ��ԤԼ
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ�ܣ����δͨ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
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
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "�� ";
		cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
		cout << " ʱ��Σ� " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ� " << of.m_orderData[i]["stuId"];
		cout << " ������ " << of.m_orderData[i]["stuName"];
		cout << " ������ţ� " << of.m_orderData[i]["roomId"];
		string status = " ״̬��";
		// 1 ����� 2 ��ԤԼ  -1ԤԼʧ��  0 ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
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
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "��˻�ԤԼ�ɹ��ļ�¼����ȡ����������Ҫȡ���ļ�¼" << endl;
	int index = 1;
	vector<int>v; //�������������е��±���,Ҳ���ǵڼ���
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.emplace_back(i);
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
				cout << " ʱ��Σ� " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ������ţ� " << of.m_orderData[i]["roomId"];
				string status = " ״̬�� ";
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼��0������" << endl;
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

				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}

		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}
