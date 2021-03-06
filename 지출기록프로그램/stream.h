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
	void input(expense_info exin);	// 지출 기록
	void print();	// 지출 출력
	void printCategorySum();	// 분류별 금액 총합 출력
	void printSum();	// 지출 금액 총합 출력
	string thousand_seperator(int uValue);	//천단위 콤마 변환

};
#endif // !__STREAM_H_
