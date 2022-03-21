#pragma once
class PCB
{
private:
	int pid;		//�������
	int runTime;	//����������ʱ��
	int claimTime;  //������������ʱ��
	int priority;   //�������ȼ�
public:
	PCB(int id, int p, int ct);
	int getPid();
	int getRunTime();
	int getClaimTime();
	int getPriority();
	void run(); //�������к���
	bool isFinished(); //����״̬�жϺ���
	bool operator<(const PCB& p) const;//�����<�����غ���

};

