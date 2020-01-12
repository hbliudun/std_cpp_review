#pragma once

#include <iostream>
using namespace std;


class CComplex
{
public:
	CComplex(int r = 0, int i = 0) :
		m_r(r), m_i(i) {}


	CComplex add(CComplex c)
	{
		return CComplex(m_r + c.m_r, m_i + c.m_i);
	}

	//CComplex operator+(const CComplex& rhs)
	//{
	//	cout << "call normal +" << endl;
	//	return CComplex(m_r + rhs.m_r, m_i + rhs.m_i);
	//}
	const CComplex operator+(const CComplex& rhs)const
	{
		cout << " call const +" << endl;
		return CComplex(m_r + rhs.m_r, m_i + rhs.m_i);
	}
	//const CComplex operator-(const CComplex& rhs)
	//{
	//	cout << " call normal -" << endl;
	//	return CComplex(m_r - rhs.m_r, m_i - rhs.m_i);
	//}

	// +=
	CComplex& operator+=(const CComplex& c) {
		m_r += c.m_r;
		m_i += c.m_i;
		return *this;
	}
	// -=
	friend CComplex& operator-=(CComplex& l, const CComplex& r);

	friend CComplex operator-(const CComplex& left, const CComplex& right);
	void print()
	{
		cout << m_r << '+' << m_i << 'i';
		cout << endl;
	}
private:
	int m_r;
	int m_i;
};

