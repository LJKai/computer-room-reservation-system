#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "globalFile.h"
using namespace std;

class OrderFile
{
public:
	int m_Size; //��¼ԤԼ����
	map<int, map<string, string>> m_orderData; //��¼����ԤԼ��Ϣ

	OrderFile();
	void updateOrder(); //����ԤԼ��¼
};

