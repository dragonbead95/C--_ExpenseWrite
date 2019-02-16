#include <iostream>
#include "AccountException.h"
#include "expense.h"

using std::cout;
using std::endl;

MinusException::MinusException(int money) : reqDep(money)
{

}
void MinusException::ShowExceptionReason()
{
	cout << "[���� �޽���: �ݾ�" << reqDep << "��(��) ��ȿ���� �ʽ��ϴ�.]" << endl;
}

CategoryException::CategoryException(int myCategory) : reqCate(myCategory)
{

}

void CategoryException::ShowExceptionReason()
{
	cout << "[���� �޽���: 1~12 ������ ���ڸ� �Է����ּ���]" << endl;
}

DateException::DateException(String s)
{
	str = s;
}

void DateException::ShowExceptionReason()
{
	cout << "[���� �޽���: " << str << "��(��) �԰ݿ� �����ʽ��ϴ�.(ex 2019-02-16)]" << endl;
}