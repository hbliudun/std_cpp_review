#include "Complex.h"

CComplex & operator-=(CComplex & l, const CComplex & r)
{
	// TODO: �ڴ˴����� return ���
	l.m_i -= r.m_i;
	l.m_r -= r.m_r;
	return l;
}

CComplex operator-(const CComplex & left, const CComplex & right)
{
	cout << "call frind -" << endl;
	return CComplex(left.m_r - right.m_r, left.m_i - right.m_i);
}
