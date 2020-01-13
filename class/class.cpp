#include<iostream>
using namespace std;
#include<cstdio>
#include<string>
#include"Complex.h"
#include"Integer.h"
#include"Hungry.h"
#include"Lazy.h"


// explicit
class Integer {
public:
	Integer(void) {
		cout << "无参构造" << endl;
		m_data = 0;
	}
	//类型转换构造函数
	/*explicit要求必须做显示转换*/
	explicit Integer(const int& data) {
		cout << "单参构造函数" << endl;
		m_data = data;
	}
	void print(void) {
		cout << m_data << endl;
	}
private:
	int m_data;
};

//常函数 and mutable
class A {
public:
	A(int data = 0) :m_data(data) {}
	void show(void)const {//常函数
		cout << m_data++ << endl;
		/*mutable修饰的变量在使用时会去除
		常属性，类似如下:*/
		//cout << const_cast<A*>(this)->
		//    m_data++ << endl;

	}
	void func(void) const {
		cout << "func常版本" << endl;
	}
	void func(void) {
		cout << "func非常版本" << endl;
	}
private:
	/*mutable修饰变量可以在常函数中修改*/
	mutable int m_data;
};

class Student {
public:
	Student(const string& name = "",double b = 1.0f) :
		m_name(name) {}

	void who(void) {
		cout << m_name << endl;
	}
	void setName(string strName)
	{
		m_name = strName;
	}

	double m_d;
	string m_name;
};

CHungry CHungry::s_instance(123);
CLazy* CLazy::s_instance = NULL;
int CLazy::s_counter = 0;

int main()
{
	// Integer  CInteger
	{
		cout << "*******explicit 修饰的函数参数必需显示转换类型*********" << endl;
		Integer I1;
		I1.print();
		//	I1 = 100;	//error
		I1.print();
		I1 = Integer(2);
		I1.print();
		cout << "*******mutable修饰的成员能够在常函数中被修改*********" << endl;
		A a(1234);
		a.show();
		a.show();
		A a1;
		A const& r = a1;
		a1.func();
		r.func();

		cout << "************************深拷贝-浅拷贝*******************" << endl;
	/*	CInteger c1(2);
		CInteger c2(3);
		c1.print(c2);
		cout << "c2 = " << c2.get() << endl;
		CInteger c3 = c2;
		cout << "c3 = " << c3.get() << endl;*/
	}
	// 成员变量指针  成员函数值指针
	{
		cout << "******************成员指针****************" << endl;
		string Student::*pname =
			&Student::m_name;
		Student s1("张飞");
		Student s2("赵云");
		//.* 成员指针解引用运算符
		cout << s1.*pname << endl;
		cout << s2.*pname << endl;
		Student* ps = &s2;
		//->* 间接成员指针解引用运算符
		cout << ps->*pname << endl;

		printf("pname=%p\n", pname);
		printf("&s1=%p\n", &s1);
		printf("&s1.m_name=%p\n", &s1.m_name);

		cout << "****************pd**************" << endl;
		double Student::*pd = &Student::m_d;
		cout << s1.*pd << endl;
		cout << s2.*pd << endl;
		cout << ps->*pd << endl;
		printf("pd=%p\n", pd);
		printf("&s1=%p\n", &s1);
		printf("&s1.m_d=%p\n", &s1.m_d);
		cout << "**************pfunction************" << endl;
		void (Student::*pwho)() = &Student::who;
		(s1.*pwho)();
		Student* pf = &s2;
		(pf->*pwho)();
	}

	// Complex
	{
		CComplex c1(1, 2);
		CComplex c2(3, 4);
		c1.print();
		c2.print();
		CComplex c3 = c1.add(c2);
		c3.print();
		CComplex c4 = c1 + c2 + c3;
		c4.print();

		CComplex c5 = c4 - c1;
		c5.print();

		c5 -= c2;
		c5.print();
	}

	// ++i   i++  --i  i--
	{
		cout << "***************Integer**********************" << endl;
		CInteger c1(1);
		cout << "c1 ： ";
		c1.print();
		c1++;
		cout << "c1++ ： ";
		c1.print();
		++c1;
		cout << "++c1 ： = ";
		c1.print();

		c1--;
		cout << "++c1 ： = ";
		c1.print();
		--c1;
		cout << "++c1 ： = ";
		c1.print();

	}
	//  <<   >>
	{
		//CInteger c;
		//cin >> c;
		//cout << c << endl;
	}
	// 懒汉模式
	{

	}
	// 饿汉模式
	{
		CHungry& a1 = CHungry::getInstance();
		CHungry& a2 = CHungry::getInstance();

		cout << &a1 << "," << &a2 << endl;
	}
	//懒汉模式
	{
		CLazy& l1 = CLazy::getInstance();
		CLazy& l2 = CLazy::getInstance();

		cout << &l1 << "," << &l2 << endl;
		l1.release();
		l1.release();
	}










	return 0;


 }