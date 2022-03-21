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
	int m_Size; //记录预约条数
	map<int, map<string, string>> m_orderData; //记录所有预约信息

	OrderFile();
	void updateOrder(); //更新预约记录
};

