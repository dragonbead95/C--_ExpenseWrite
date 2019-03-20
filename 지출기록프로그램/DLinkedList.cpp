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
	node * newNode = new node(data, NULL);	// 새노드 생성

	newNode->setNext(head->getNext());	// 새 노드가 다른 노드를 가리키게 함
	head->setNext(newNode);				// 더미 노드가 새 노드를 가리키게 함

	numOfData++;						// 데이터 수 하나를 증가시킴
}

void linkedList::LInsert(LData data)
{
	if (comp == NULL)	// 정렬기준이 마련되지 않았다면,
	{
		FInsert(data);	// 머리에 노드를 추가
	}
	else {				// 정렬기준이 마련되어 있다면
		SInsert(data);	// 정렬기준에 근거하여 노드를 추가
	}
}

void linkedList::SInsert(LData data)
{
	node * newNode = new node(data, NULL);	//새 노드 생성
	node * pred = head;				// pred는 더미 노드를 가리킴

									// 새 노드가 들어갈 위치를 찾기 위한 반복문!
	while (pred->getNext() != NULL && this->comp(data, pred->getNext()->getData()) != 0)
	{
		pred = pred->getNext();	// 다음 노드로 이동
	}

	newNode->setNext(pred->getNext());	// 새노드의 오른쪽을 연결
	pred->setNext(newNode);				// 새 노드의 왼쪽을 연결

	numOfData++;						// 저장된 데이터의 수 하나 증가
}

int linkedList::LFirst(LData * pdata)
{
	if (head->getNext() == NULL)	// 더미노드가 NULL을 가리킨다면
		return FALSE;				// 반환할 데이터가 없다.

	before = head;					// before는 더미 노드를 가리키게 함
	cur = head->getNext();			// cur은 첫 번째 노드를 가리키게 함

	*pdata = cur->getData();		// 첫번째 노드의 데이터를 전달
	return TRUE;					// 데이터 반환 성공
}

int linkedList::LNext(LData * pdata)
{
	if (cur->getNext() == NULL)		// cur이 NULL을 가리킨다면
		return FALSE;				// 반환할 데이터가 없다.

	before = cur;					// cur이 가리키던 것을 before가 가리킴
	cur = cur->getNext();			// cur은 그 다음 노드를 가리킴

	*pdata = cur->getData();		// cur이 가리키는 노드의 데이터 전달
	return TRUE;					// 데이터 반환 성공
}

LData linkedList::LRemove()
{
	node * rpos = cur;				// 소멸 대상의 주소 값을 rpos에 저장
	LData rdata = rpos->getData();	// 소멸 대상의 데이터를 rdata에 저장

	before->setNext(cur->getNext());	// 소멸 대상을 리스트에서 제거
	cur = before;						// cur이 가리키는 위치를 재조정

	free(rpos);						// 리스트에서 제거된 노드 소멸
	numOfData--;					// 저장된 데이터의 수 하나 감소
	return rdata;					// 제거된 노드의 데이터 반환
}

int linkedList::LCount()
{
	return numOfData;
}

void linkedList::SetSortRule(int(*comp)(LData d1, LData d2))
{
	this->comp = comp;
}
