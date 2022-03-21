#pragma once
#include "Identity.h"
#include <iostream>
#include <vector>
#include "ComputerRoom.h"
#include "OrderFile.h"
using namespace std;

class Student :
    public Identity
{
public:
    int m_Id;
    vector<ComputerRoom> vCom;

    Student();
    Student(int id, string name, string pwd);
    virtual void operMenu();
    void applyOrder();
    void showMyOrder();
    void showAllOrder();
    void cancelOrder();
};

