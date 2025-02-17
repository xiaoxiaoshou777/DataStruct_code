#pragma once

#include <assert.h>

template<class T>
class Stack
{
public:
	Stack()
		:_capacity(3)
		, _size(0)
		, _data(new T[_capacity])
	{}

	~Stack()
	{
		if (_data)
		{
			delete[] _data;
		}
	}

	// 拷贝构造和赋值运算符的重载需要实现，并考虑深拷贝浅拷贝问题。(作业完成)

public:
	void Push(const T& x)
	{
		_CheckCapacity();
		_data[_size++] = x;
	}

	void Pop()
	{
		assert(_size > 0);
		--_size;
	}

	const T& Top()
	{
		assert(_size > 0);
		return _data[_size - 1];
	}

	size_t Size()
	{
		return _size;
	}

	bool Empty()
	{
		return _size == 0;
	}

	void Print()
	{
		for (size_t i = 0; i < _size; ++i)
		{
			cout << _data[i] << "->";
		}
	}

private:
	void _CheckCapacity()
	{
		if (_capacity == _size)
		{
			T* tmp = new T[_capacity];
			//
			// 如果T是自定类型的考虑深浅拷贝的问题
			// 当T是string等类型时得用operator=
			//
			//memcpy(tmp, _data, _size*sizeof(T));
			for (size_t i = 0; i < _size; ++i)
			{
				tmp[i] = _data[i];
			}
			_capacity *= 2;

			delete[] _data;
			_data = tmp;
		}
	}

private:
	size_t _size;		// 数据的个数
	size_t _capacity;	// 容量

	T* _data;			// 指向数据块的指针
};

void TestStack()
{
	Stack<int> s1;
	cout << "Stack is Empty:" << s1.Empty() << endl;

	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);

	cout << s1.Top() << endl;
	s1.Pop();

	cout << s1.Top() << endl;
	s1.Pop();

	cout << s1.Top() << endl;
	s1.Pop();

	cout << s1.Top() << endl;
	s1.Pop();

	cout << s1.Top() << endl;
	s1.Pop();
	s1.Print();
}