#pragma once
#include "Identity.h"
#include <iostream>
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include "ComputerRoom.h"
using namespace std;

class Manager :
	public Identity
{
public:
	Manager();
	Manager(string name, string pwd);
	virtual void operMenu();
	void addPerson();
	void showPerson();
	void showComputer();
	void cleanFile();
	void initVector();
	bool checkRepeat(int id, int type);

	vector<Student>vStu;
	vector<Teacher>vTea;
	vector<ComputerRoom>vCom;
};

