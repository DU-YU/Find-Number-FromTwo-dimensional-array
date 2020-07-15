#include <stdio.h>
#include <iostream>

using namespace std;
/*
	函数bool find（int *array, int rows, int columns, int number）
	参数：array：输入二维数组
		  rows：该二维数组的行
		  columns：该二维数组的列
		  number：要寻找的数
	返回值：TRUE：找到返回true
			false：找不到返回false
*/

bool Find(int *array, int rows, int columns, int number)
{
		
	bool result = false;

	if (array == nullptr || rows < 0 || columns < 0 )
	{
		return false;
	}

	int row = 0;
	int column = columns - 1;
	while (row < rows && column > 0)
	{
		if (array[row * columns + column] == number)
		{
			result = true;
			break;
		}
		else if (array[row * columns + column] > number)
		{
			--column;
		}
		else
			++row;
	}

	return result;
}



//====================测试用例=========================

void test(const char *TestName, int *array, int rows, int columns, int ExpectedNumber,bool ExpectedValue )
{
	if (TestName != nullptr || rows >= 0 || columns >= 0)
	{
		printf("%s is begin!\n", TestName);
	}
	bool result = Find(array, rows, columns, ExpectedNumber);
	if (result == ExpectedValue)
	{
		printf("FIND SUCCESSED!........\n");
	}
	else
		printf("find failure!...........\n");

}

void test1()
{
	int array[][4] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	test("test1", (int *)array, 4, 4, 3, true);
}

int main()
{
	test1();
}
