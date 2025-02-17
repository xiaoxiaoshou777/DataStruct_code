#pragma once
#include<assert.h>

template<class T>
class Queue
{
	struct Node
	{
		Node* _next;
		T _data;

		Node(const T& x)
			:_next(NULL)
			, _data(x)
		{}
	};

public:
	Queue()
		:_head(NULL)
		, _tail(NULL)
		, _size(0)
	{}

	~Queue()
	{
		Clear();
	}

	// 拷贝构造和赋值运算符的重载需要实现，并考虑深拷贝浅拷贝问题。(作业完成)

	void Push(const T& x)
	{
		//
		// 1.没有节点
		// 2.有节点
		//
		if (_head == NULL)
		{
			_head = new Node(x);
			_tail = _head;
		}
		else
		{
			_tail->_next = new Node(x);
			_tail = _tail->_next;
		}

		++_size;
	}

	void Pop()
	{
		assert(_head);

		//
		// 1.最后一个节点
		// 2.一个以上节点
		//
		if (_head == _tail)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
		}
		else
		{
			Node* tmp = _head;
			_head = _head->_next;
			delete tmp;
		}

		--_size;

	}

	const T& Back()
	{
		assert(_tail);

		_tail->_data;
	}

	const T& Front()
	{
		assert(_head);

		return _head->_data;
	}

	bool Empty()
	{
		return _head == NULL;
	}

	void Print()
	{
		Node* begin = _head;
		cout << "Queue Head<-";
		while (begin)
		{
			cout << begin->_data << "<-";
			begin = begin->_next;
		}
		cout << "Queue Tail" << endl;
	}

	void Clear()
	{
		while (_head)
		{
			Node* tmp = _head;
			_head = _head->_next;
			delete tmp;
		}

		_head = NULL;
		_tail = NULL;
		_size = 0;
	}

	size_t Size()
	{
		return _size;
	}

private:
	Node*  _head;
	Node*  _tail;

	int _size;
};

void TestQueue()
{
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);

	q.Print();

	q.Pop();
	q.Pop();
	q.Pop();
	q.Pop();

	q.Print();
}