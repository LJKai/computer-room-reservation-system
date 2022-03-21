#include <iostream>
#include <queue>
#include "PCB.h"
using namespace std;

int main()
{
	int timeslice = 0; //�Ѿ����ĵ�ʱ��Ƭ
	priority_queue<PCB> queue; //�������У����ȼ��ߵ���ǰ��
	for (int i = 0; i < 5; i++)//����5������
	{
		int p, t;
		cout << "�������" << i << "�Ž��̵����ȼ���";
		cin >> p;
		cout << "�������" << i << "�Ž�����Ҫ���е�ʱ�䣺";
		cin >> t;
		queue.emplace(PCB(i, p, t));
	}
	cout << "===============================================" << endl;
	//��̬�����㷨
	while (!queue.empty())
	{
		PCB pcb = queue.top();
		queue.pop();
		cout << "����" << pcb.getPid() << "�ſ�ʼ����" << endl;
		cout << "���ȼ�\t������ʱ��" << endl;
		cout << pcb.getPriority() << '\t' << pcb.getRunTime() << endl;
		pcb.run();
		cout << "����" << pcb.getPid() << "�Ž�������" << endl;
		cout << "���ȼ�\t������ʱ��" << endl;
		cout << pcb.getPriority() << '\t' << pcb.getRunTime() << endl;
		if (pcb.isFinished())
		{
			cout << pcb.getPid() << "�Ž������������" << endl;
		}
		else
		{
			queue.push(pcb);
			cout << "��������δ��ɣ����������" << endl;
		}
		timeslice++;
		cout << "----------------------------------------------" << endl;
		system("pause");
	}
	cout << "���н���������ɣ���������ʱ��ƬΪ��" << timeslice;
	return 0;
}