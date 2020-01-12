#pragma once
#include<iostream>
using namespace std;

class CInteger {
public:
	CInteger(int i = 0) :m_i(i) {}
	void print(void)const {
		cout << m_i << endl;
	}

	// ǰ++
	friend CInteger& operator++(CInteger& i);
	// ǰ--
	CInteger& operator--(void)
	{
		--this->m_i;
		return *this;
	}
	// ��++
	friend CInteger& operator++(CInteger& i, int);
	// ��--
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
//	// ȱʡ���캯��
//	CInteger(int a) :m_pData(new int(a))
//	{
//
//	}
//	//// ȱʡ��������
//	//CInteger& operator=(const CInteger& that)
//	//{
//	//	m_pData = that.m_pData;
//	//}
//
//	//���
//	CInteger(const CInteger& that) :m_pData(new int(*that.m_pData))
//	{
//
//	}
//	//�����ֵ
//	CInteger& operator=(const CInteger& that)
//	{
//		if (this != &that)
//		{
//			//�ͷ���Դ
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

