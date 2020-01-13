#pragma once
#include<iostream>
using namespace std;


class CLazy
{
public:
	static CLazy& getInstance(void);
	void release(void);

private:
	CLazy(int data = 0) :m_data(data) {
		
		cout << "CLazy::CLazy(int)" << endl;
	}
	~CLazy()
	{
		cout << "CLazy::~CLazy()" << endl;
		s_instance = NULL;
	}

private:
	int m_data;
	static CLazy* s_instance;
	static int s_counter;
};

