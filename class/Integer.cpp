#include "Integer.h"

CInteger & operator++(CInteger & i)
{
	// TODO: �ڴ˴����� return ���
	++i.m_i;
	return i;
}

// ��++ ��Ҫһ��������ʾ��Ӽ�
CInteger & operator++(CInteger& i, int)
{
	// TODO: �ڴ˴����� return ���
	CInteger old = i;
	// �����������Ҫ+1
	++i;
	// ����+1ǰ��ԭ����
	return old;
}
