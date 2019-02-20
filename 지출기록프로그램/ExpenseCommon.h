#ifndef __EXPENSE_COMMON_H_
#define __EXPENSE_COMMON_H_

enum {WRITE=1,ALLSEARCH,SEARCH,EXIT};	// 1. 지출기록, 2. 지출전체검색 3. 종료
enum search {DATE_SEARCH=1,MONEY_SEARCH,CATEGORY_SEARCH,BACK,SEARCH_EXIT};
/*1.식비
	2. 교통비
	3. 통신비
	4. 간식비
	5. 유흥비
	6. 생활비
	7. 도서비
	8. 교육비
	9. 문구비
	10. 의료비
	11. 의류비
	12. 기타*/
enum{FOOD=1,
	PUBLIC_TRANSFER,
	POSTAGE,
	SNACK,
	ENTERTAINMENT,
	LIFE,
	BOOK,
	EDUCATION,
	STATIONARY,
	MEDICAL,
	CLOTHES,
	ETC};

#endif // !__EXPENSE_COMMON_H_
