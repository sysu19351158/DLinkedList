#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
using namespace std;


template<class T>
class DLinkedList
{
public:
	DLinkedList(ifstream &f);
	~DLinkedList();
	void init();
	int getsize() { return size; }
	bool empty() { if (size == 0) return 1; else return 0; }
	Node<T> remove(T d);
	Node<T> first() { return *front; }
	Node<T> last() { return *rear; }
	void insertAsFirst(T d);
	void insertAsLast(T d);
	Node<T> find(T d);
	void sort();
	void reverse();
	void merge(DLinkedList<T>& l);
	void show();
private:
	Node<T>* front, * rear;
	Node<T>* prevPtr, * currPtr;
	Node<int> head;
	int size;
};

template <class T>
DLinkedList<T>::DLinkedList(ifstream &f)
{
	this->init();
	string text;
	while(getline(f, text))
	{
		if (text[0] == 'd')
		{
			int d = stoi(text.substr(text.find(':')+1));
			Node<T>* p = new Node<T>(d);
			if (front == nullptr)
			{
				head.succ = p;
				front = p; rear = p;
				size += 1; 
				currPtr = p;
			}
			else
			{
				p->pred = currPtr;
				currPtr->succ = p;
				rear = p;
				size += 1;
				prevPtr = currPtr;
				currPtr = p;
			}
		}
	}

}

template <class T>
void DLinkedList<T>::init()
{
	if (size != 0)
	{
		if (front->succ == nullptr)
		{
			delete front; front = nullptr;
		}
		else
		{
			prevPtr = front;
			currPtr = prevPtr->succ;
			while (currPtr->succ != nullptr)
			{
				delete prevPtr; prevPtr = nullptr;
				prevPtr = currPtr;
				currPtr = currPtr->succ;
			}
			delete prevPtr; prevPtr = nullptr; delete currPtr; currPtr = nullptr;
		}
		prevPtr = nullptr; currPtr = nullptr;
		front = nullptr; rear = nullptr;
	}
	size = 0; 
}
template <class T>
void DLinkedList<T>::show()
{
	currPtr = front->succ;
	cout << "data" << 1 << ":" << front->data << endl;
	int i = 2;
	while (currPtr->succ != nullptr)
	{
		cout << "data" << i << ":" << currPtr->data << endl;
		i += 1;
		currPtr = currPtr->succ;
	}
	cout << "data" << i << ":" << currPtr->data << endl;
}
template <class T>
DLinkedList<T>::~DLinkedList()
{
	int i = 0;
	if (size != 0)
	{
		if (front->succ == nullptr)
		{
			delete front; i += 1; front = nullptr;
		}
		else
		{
			prevPtr = front;
			currPtr = prevPtr->succ;
			while (currPtr->succ != nullptr)
			{
				delete prevPtr; prevPtr = nullptr; i += 1;
				prevPtr = currPtr;
				currPtr = currPtr->succ;
			}
			delete prevPtr; prevPtr = nullptr; delete currPtr; currPtr = nullptr; i += 2;
		}
	}
	cout << size;
	if (i == size)
		cout << "析构成功" << endl;
}
template <class T>
Node<T> DLinkedList<T>::remove(T d)
{
	prevPtr = front;
	currPtr = prevPtr->succ;
	if (front->data == d)
	{
		Node<T> p(front->data);
		delete front; front = nullptr;
		size -= 1;
		front = currPtr;
		currPtr->pred = nullptr;
		return p;
	}
	while (currPtr->succ != nullptr)
	{
		if (currPtr->data == d)
		{
			Node<T> p (currPtr->data);
			currPtr = currPtr->succ;
			delete (prevPtr->succ); prevPtr->succ = nullptr;
			prevPtr->succ = currPtr;
			currPtr->pred = prevPtr;
			size -= 1;
			return p;
		}
		prevPtr = currPtr;
		currPtr = currPtr->succ;
	}
	if (currPtr->data == d)
	{
		Node<T> p (currPtr->data);
		delete currPtr; currPtr = nullptr;
		prevPtr->succ = nullptr;
		rear = prevPtr;
		size -= 1;
		return p;
	}
	cout << "未能找到所要删除的节点，返回空头结点" << endl; return head;
}
template <class T>
void DLinkedList<T>::insertAsFirst(T d)
{
	Node<T> *p = new Node<T>(d);
	p->succ = front;
	front->pred = p;
	p->pred = nullptr;
	front = front->pred;
	head.succ = p;
	size += 1;
}
template <class T>
void DLinkedList<T>::insertAsLast(T d)
{
	Node<T> *p = new Node<T>(d);
	p->pred = rear;
	rear->succ = p;
	p->succ = nullptr;
	rear = rear->succ;
	size += 1;
}


template <class T>
Node<T> DLinkedList<T>::find(T d)
{
	prevPtr = front;
	currPtr = front->succ;
	if (front->data == d)
		return *front;
	while (currPtr->succ != nullptr)
	{
		if (currPtr->data == d)
			return *currPtr;
		prevPtr = currPtr;
		currPtr = currPtr->succ;
	}
	if (currPtr->data == d)
		return *currPtr;
	cout << "未能找到所需节点，返回空头结点" << endl;
	return head;
}

template <class T>
void DLinkedList<T>::sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		prevPtr = front;
		currPtr = front->succ;
		for (int j = 0; (j < size - i - 1) && (currPtr->succ != nullptr); j++)
		{
			if (prevPtr->data > currPtr->data)
			{
				T d = prevPtr->data; prevPtr->data = currPtr->data; currPtr->data = d;
			}
			prevPtr = currPtr; currPtr = currPtr->succ;
		}
		if (currPtr->succ == nullptr)
			if (prevPtr->data > currPtr->data)
			{
				T d = prevPtr->data; prevPtr->data = currPtr->data; currPtr->data = d;
			}
	}
}

template <class T>
void DLinkedList<T>::reverse()
{
	prevPtr = rear;
	currPtr = rear->pred;
	prevPtr->pred = nullptr;
	while (currPtr->pred != nullptr)
	{
		Node<T>* p = currPtr->pred;
		prevPtr->succ = currPtr;
		currPtr->pred = prevPtr;
		prevPtr = currPtr;
		currPtr = p;
	}
	prevPtr->succ = currPtr;
	currPtr->pred = prevPtr;
	currPtr->succ = nullptr; 
	front = rear;
	rear = head.succ;
	head.succ = front;
}


template <class T>
void DLinkedList<T>::merge(DLinkedList<T>& l)
{
	currPtr = rear;
	l.prevPtr = l.front;
	Node<T>* n = new Node<T>(*(l.prevPtr));
	currPtr->succ = n;
	n->pred = currPtr;
	int i = 1;
	for (; i < l.size; i++)
	{
		currPtr = currPtr->succ;
		l.prevPtr = l.prevPtr->succ;
		Node<T>* m = new Node<T>(*(l.prevPtr));
		currPtr->succ= m;
		m->pred = currPtr;
	}

	size += l.size;
	this->sort();
}
#endif 