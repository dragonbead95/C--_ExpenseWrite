#ifndef __DLINKED_LIST_H_
#define __DLINKED_LIST_H_
#include <iostream>
#include "expense_info.h"

#define TRUE 1
#define FALSE 0

typedef expense_info LData;

class node
{
private:
	LData data;
	node * next;
public:
	node()
	{
		next = NULL;
	}
	node(LData d, node * n)
	{
		data = d;
		next = n;
	}
	LData getData() const
	{
		return data;
	}
	void setData(LData d)
	{
		data = d;
	}
	void setNext(node * n)
	{
		next = n;
	}
	node * getNext() const
	{
		return next;
	}
};

class linkedList
{
private:
	node * head;
	node * cur;
	node * before;
	int numOfData;
	int(*comp)(LData d1, LData d2);
public:
	linkedList();
	void FInsert(LData data);
	void LInsert(LData data);
	void SInsert(LData data);
	int LFirst(LData * pdata);
	int LNext(LData * pdata);
	LData LRemove();
	int LCount();
	void SetSortRule(int(*comp)(LData d1, LData d2));
};

typedef linkedList List;


#endif
