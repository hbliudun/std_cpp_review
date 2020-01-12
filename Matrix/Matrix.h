#pragma once
#include<iostream>
using namespace std;


/*******
实现一个3x3矩阵类，支持如下运算符：
  +  -(减)  +=  -=  -(负)   ++(前后)  --(前后)  <<

1 2 3     9 8 7        30    24    18
4 5 6 *   6 5 4  =     84    69    54
7 8 9     3 2 1        138  114    90
**********/

class CMatrix
{
public:
	CMatrix() {}
	CMatrix(int a[3][3])
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				m_a[i][j] = a[i][j];
			}
		}
	}
public:
	CMatrix operator+(const CMatrix& that)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				m_a[i][j] + that.m_a[i][j];
			}
		}
		return *this;
	}
	
	CMatrix operator-(const CMatrix& that)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				m_a[i][j] - that.m_a[i][j];
			}
		}
		return *this;
	}

	CMatrix& operator+=(const CMatrix& that)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				m_a[i][j] += that.m_a[i][j];
			}
		}
		return *this;
	}
	CMatrix& operator-=(const CMatrix& that)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				m_a[i][j] -= that.m_a[i][j];
			}
		}
		return *this;
	}

public:
	void print()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				cout<<m_a[i][j]<<" ";
			}
			cout << endl;
		}
	}
private:
	int m_a[3][3];
};

