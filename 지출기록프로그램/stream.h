#ifndef __STREAM_H_
#define __STREAM_H_

#include "library.h"
#include "expense_info.h"

class stream
{
private:
	ofstream out;
	ifstream in;
public:
	stream();
	void input(expense_info exin);	// ���� ���
	void print();	// ���� ���
	void printCategorySum();	// �з��� �ݾ� ���� ���
	void printSum();	// ���� �ݾ� ���� ���
	string thousand_seperator(int uValue);	//õ���� �޸� ��ȯ

};
#endif // !__STREAM_H_
