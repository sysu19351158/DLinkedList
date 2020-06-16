#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;


int main()
{
	ifstream infile1,infile2;
	infile1.open("./IntegerData.txt");
	infile2.open("./Merge.txt");
	if (!infile1.is_open()||!infile2.is_open())
	{cout << "文件打开失败" << endl; return 1;}
	DLinkedList<int> list1(infile1);
	DLinkedList<int> list2(infile2);
	cout << "链表大小为" << list1.getsize() << endl;
	cout << "链表数据为：" << endl;
	list1.show();
	if (list1.empty())
		cout << "这是空链表" << endl;
	else
		cout << "这不是空链表" << endl;
	list1.remove(5);
	list1.remove(32);
	cout << "删除数据为5和32的节点后链表数据为：" << endl;
	list1.show();
	list1.insertAsFirst(5);
	list1.insertAsLast(32);
	cout << "重新在链表前向插入数据为5的节点和在链表向后插入数据为32的节点后，返回首、末节点并输出节点数据：" << endl;
	list1.first().show(); list1.last().show();
	list1.show();
	cout << "寻找数据为3的节点并返回节点输出数据：";list1.find(3).show();
	cout << "排序后的链表数据为：" << endl;
	list1.sort();
	list1.show();
	cout << "反转后的有序链表数据为：" << endl;
	list1.reverse();
	list1.show();
	cout << "合并另一有序链表后的链表数据为：" << endl;
	list1.merge(list2);
	list1.show();


	return 0;
}