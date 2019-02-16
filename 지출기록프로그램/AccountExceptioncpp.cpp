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
	cout << "[예외 메시지: 금액" << reqDep << "은(는) 유효하지 않습니다.]" << endl;
}

CategoryException::CategoryException(int myCategory) : reqCate(myCategory)
{

}

void CategoryException::ShowExceptionReason()
{
	cout << "[예외 메시지: 1~12 사이의 숫자를 입력해주세요]" << endl;
}

DateException::DateException(String s)
{
	str = s;
}

void DateException::ShowExceptionReason()
{
	cout << "[예외 메시지: " << str << "은(는) 규격에 맞지않습니다.(ex 2019-02-16)]" << endl;
}