#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "OrderFile.h"
#include "globalFile.h"
using namespace std;

class Identity
{
public:
	string m_Name;
	string m_Pwd;

	virtual void operMenu() = 0;
};

