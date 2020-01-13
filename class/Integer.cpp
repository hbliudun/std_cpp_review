#include "Integer.h"

CInteger & operator++(CInteger & i)
{
	// TODO: 在此处插入 return 语句
	++i.m_i;
	return i;
}

// 后++ 需要一个参数表示后加加
CInteger & operator++(CInteger& i, int)
{
	// TODO: 在此处插入 return 语句
	CInteger old = i;
	// 传入的数据需要+1
	++i;
	// 返回+1前的原数据
	return old;
}

ostream & operator<<(ostream & os, const CInteger & data)
{
	// TODO: 在此处插入 return 语句
	return os << data.m_i;
}

istream & operator>>(istream & is, CInteger & data)
{
	// TODO: 在此处插入 return 语句
	return is >> data.m_i;
}
