#include"Matrix.h"


int main()
{
	int szMatrix1[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int szMatrix2[3][3] = { 9,8,7,6,5,4,3,2,1 };
	CMatrix matrix1(szMatrix1);
	CMatrix matrix2(szMatrix2);

	matrix1.print();
	matrix2.print();

	matrix1 += matrix2;
	matrix1.print();

	matrix1 -= matrix2;
	matrix1.print();
	return 0;
}