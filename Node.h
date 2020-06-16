#ifndef __NODE_H__
#define __NODE_H__
#include "LinkedList.h"
#include <iostream>
using namespace std;

template<class T>
class Node
{
	template <class T>
	friend class DLinkedList ;
public:
	Node(T d) :data{ d }, pred{ nullptr }, succ{ nullptr } {}
	Node() :data{ 0 }, pred{ nullptr }, succ{ nullptr }  {}
	void show() { cout << data << endl; }
private:
	Node<T>* pred, * succ;
	T data;
};
#endif