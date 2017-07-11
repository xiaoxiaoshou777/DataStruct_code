#include<iostream>
using namespace std;

#include"SeqList.hpp"

// ²âÊÔPushBack
void Test1()
{
	SeqList<int> v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);

	v1.Print();
}

// ²âÊÔInsert
void Test2()
{
	SeqList<int> v1;
	v1.Insert(0, 1);
	v1.Insert(1, 2);
	v1.Insert(2, 3);
	v1.Insert(3, 4);

	v1.Insert(0, 0);

	v1.Print();
}

// ²âÊÔPopBack
void Test3()
{
	SeqList<int> v1;
	v1.Insert(0, 1);
	v1.Insert(1, 2);
	v1.Insert(2, 3);
	v1.Insert(3, 4);

	v1.Print();

	v1.PopBack();

	v1.Print();
}

// ²âÊÔEarse
void Test4()
{
	SeqList<int> v1;
	v1.Insert(0, 1);
	v1.Insert(1, 2);
	v1.Insert(2, 3);
	v1.Insert(3, 4);

	v1.Print();

	v1.Earse(0);
	v1.Earse(v1.GetSize() - 1);

	v1.Print();
}

// ²âÊÔoperator[]
void Test5()
{
	SeqList<int> v1;
	v1.Insert(0, 1);
	v1.Insert(1, 2);
	v1.Insert(2, 3);
	v1.Insert(3, 4);

	v1.Print();

	v1[0] = 0;
	v1[1] = 1;
	v1[2] = 2;
	v1[3] = 3;

	v1.Print();

	v1.Clear();

	v1.Print();
}

// ²âÊÔ¿½±´¹¹Ôì&operator=
void Test6()
{
	SeqList<int> v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);

	SeqList<int> v2 = v1;
	v2.Print();

	v1.PushBack(5);

	v2 = v1;
	v2.Print();
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return 0;
}