#include "MenuOption.h"
#include "library.h"

void ShowHeader()
{
	cout << "날짜" << '\t'<<'\t' << "금액" << '\t' << "용도" << '\t' << "분류" << endl;
	cout << "-------------------------------------------------" << endl;
}

void ShowMenu()
{
	cout << "1. 지출기록" << endl;
	cout << "2. 지출전체검색" << endl;
	cout << "3. 지출세부검색" << endl;
	cout << "4. 종료" << endl;
}

void ShowSearchMenu()
{
	cout << "1. 날짜별 검색" << endl;
	cout << "2. 금액별 검색" << endl;
	cout << "3. 분류별 검색" << endl;
	cout << "4. 뒤로가기" << endl;
	cout << "5. 종료" << endl;
}
