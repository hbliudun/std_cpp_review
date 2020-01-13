#pragma once
#include<iostream>
using namespace std;




class CHungry
{
public:
	static CHungry& getInstance(void);
private:
	CHungry(int data = 0):m_data(data)
	{
		cout << "CHungry::CHungry(int)" << endl;
	}
	CHungry(CHungry const& that) {}
private:
	int m_data;
	static CHungry s_instance;

};


