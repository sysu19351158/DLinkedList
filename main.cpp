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
	{cout << "�ļ���ʧ��" << endl; return 1;}
	DLinkedList<int> list1(infile1);
	DLinkedList<int> list2(infile2);
	cout << "�����СΪ" << list1.getsize() << endl;
	cout << "��������Ϊ��" << endl;
	list1.show();
	if (list1.empty())
		cout << "���ǿ�����" << endl;
	else
		cout << "�ⲻ�ǿ�����" << endl;
	list1.remove(5);
	list1.remove(32);
	cout << "ɾ������Ϊ5��32�Ľڵ����������Ϊ��" << endl;
	list1.show();
	list1.insertAsFirst(5);
	list1.insertAsLast(32);
	cout << "����������ǰ���������Ϊ5�Ľڵ������������������Ϊ32�Ľڵ�󣬷����ס�ĩ�ڵ㲢����ڵ����ݣ�" << endl;
	list1.first().show(); list1.last().show();
	list1.show();
	cout << "Ѱ������Ϊ3�Ľڵ㲢���ؽڵ�������ݣ�";list1.find(3).show();
	cout << "��������������Ϊ��" << endl;
	list1.sort();
	list1.show();
	cout << "��ת���������������Ϊ��" << endl;
	list1.reverse();
	list1.show();
	cout << "�ϲ���һ������������������Ϊ��" << endl;
	list1.merge(list2);
	list1.show();


	return 0;
}