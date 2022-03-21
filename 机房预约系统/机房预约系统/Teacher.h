#pragma once
#include "Identity.h"
#include <iostream>
#include <vector>
using namespace std;

class Teacher :
    public Identity
{
public:
    int m_EmpId;

    Teacher();
    Teacher(int empId, string name, string pwd);
    virtual void operMenu();
    void showAllOrder();
    void validOrder(); //…Û∫À‘§‘º
};

