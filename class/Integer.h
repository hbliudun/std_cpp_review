#pragma once
#include<iostream>
using namespace std;

class CInteger {
public:
	CInteger(int i = 0) :m_i(i) {}
	void print(void)const {
		cout << m_i << endl;
	}

	// 前++
	friend CInteger& operator++(CInteger& i);
	// 前--
	CInteger& operator--(void)
	{
		--this->m_i;
		return *this;
	}
	// 后++
	friend CInteger& operator++(CInteger& i, int);
	// 后--
	CInteger& operator--(int)
	{
		CInteger old = *this;
		--m_i;
		return old;
	}

private:
	int m_i;
};

//class CInteger
//{
//public:
//	// 缺省构造函数
//	CInteger(int a) :m_pData(new int(a))
//	{
//
//	}
//	//// 缺省拷贝函数
//	//CInteger& operator=(const CInteger& that)
//	//{
//	//	m_pData = that.m_pData;
//	//}
//
//	//深拷贝
//	CInteger(const CInteger& that) :m_pData(new int(*that.m_pData))
//	{
//
//	}
//	//深拷贝赋值
//	CInteger& operator=(const CInteger& that)
//	{
//		if (this != &that)
//		{
//			//释放资源
//			delete m_pData;
//			m_pData = new int(*that.m_pData);
//		}
//		return *this;
//	}
//
//	void print(const CInteger& data)
//	{
//		cout << *data.m_pData << endl;
//	}
//	int get()
//	{
//		return *m_pData;
//	}
//private:
//	int* m_pData;
//};

