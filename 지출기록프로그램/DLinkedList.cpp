#include "DLinkedList.h"
#include <iostream>

using std::cout;
using std::endl;

linkedList::linkedList()
{
	head = new node();
	comp = NULL;
	int numOfData = 0;
}

void linkedList::FInsert(LData data)
{
	node * newNode = new node(data, NULL);	// ����� ����

	newNode->setNext(head->getNext());	// �� ��尡 �ٸ� ��带 ����Ű�� ��
	head->setNext(newNode);				// ���� ��尡 �� ��带 ����Ű�� ��

	numOfData++;						// ������ �� �ϳ��� ������Ŵ
}

void linkedList::LInsert(LData data)
{
	if (comp == NULL)	// ���ı����� ���õ��� �ʾҴٸ�,
	{
		FInsert(data);	// �Ӹ��� ��带 �߰�
	}
	else {				// ���ı����� ���õǾ� �ִٸ�
		SInsert(data);	// ���ı��ؿ� �ٰ��Ͽ� ��带 �߰�
	}
}

void linkedList::SInsert(LData data)
{
	node * newNode = new node(data, NULL);	//�� ��� ����
	node * pred = head;				// pred�� ���� ��带 ����Ŵ

									// �� ��尡 �� ��ġ�� ã�� ���� �ݺ���!
	while (pred->getNext() != NULL && this->comp(data, pred->getNext()->getData()) != 0)
	{
		pred = pred->getNext();	// ���� ���� �̵�
	}

	newNode->setNext(pred->getNext());	// ������� �������� ����
	pred->setNext(newNode);				// �� ����� ������ ����

	numOfData++;						// ����� �������� �� �ϳ� ����
}

int linkedList::LFirst(LData * pdata)
{
	if (head->getNext() == NULL)	// ���̳�尡 NULL�� ����Ų�ٸ�
		return FALSE;				// ��ȯ�� �����Ͱ� ����.

	before = head;					// before�� ���� ��带 ����Ű�� ��
	cur = head->getNext();			// cur�� ù ��° ��带 ����Ű�� ��

	*pdata = cur->getData();		// ù��° ����� �����͸� ����
	return TRUE;					// ������ ��ȯ ����
}

int linkedList::LNext(LData * pdata)
{
	if (cur->getNext() == NULL)		// cur�� NULL�� ����Ų�ٸ�
		return FALSE;				// ��ȯ�� �����Ͱ� ����.

	before = cur;					// cur�� ����Ű�� ���� before�� ����Ŵ
	cur = cur->getNext();			// cur�� �� ���� ��带 ����Ŵ

	*pdata = cur->getData();		// cur�� ����Ű�� ����� ������ ����
	return TRUE;					// ������ ��ȯ ����
}

LData linkedList::LRemove()
{
	node * rpos = cur;				// �Ҹ� ����� �ּ� ���� rpos�� ����
	LData rdata = rpos->getData();	// �Ҹ� ����� �����͸� rdata�� ����

	before->setNext(cur->getNext());	// �Ҹ� ����� ����Ʈ���� ����
	cur = before;						// cur�� ����Ű�� ��ġ�� ������

	free(rpos);						// ����Ʈ���� ���ŵ� ��� �Ҹ�
	numOfData--;					// ����� �������� �� �ϳ� ����
	return rdata;					// ���ŵ� ����� ������ ��ȯ
}

int linkedList::LCount()
{
	return numOfData;
}

void linkedList::SetSortRule(int(*comp)(LData d1, LData d2))
{
	this->comp = comp;
}
