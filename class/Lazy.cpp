#include "Lazy.h"

CLazy & CLazy::getInstance(void)
{
	// TODO: 在此处插入 return 语句
	if (s_instance == NULL)
	{
		s_instance = new CLazy(123);
	}
	s_counter++;
	return *s_instance;
}

void CLazy::release(void)
{
	if (s_instance && --s_instance == 0)
	{
		delete this;
	}
}
