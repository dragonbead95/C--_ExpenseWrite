#ifndef __EXPENSE_COMMON_H_
#define __EXPENSE_COMMON_H_

enum {WRITE=1,ALLSEARCH,SEARCH,EXIT};	// 1. ������, 2. ������ü�˻� 3. ����
enum search {DATE_SEARCH=1,MONEY_SEARCH,CATEGORY_SEARCH,BACK,SEARCH_EXIT};
/*1.�ĺ�
	2. �����
	3. ��ź�
	4. ���ĺ�
	5. �����
	6. ��Ȱ��
	7. ������
	8. ������
	9. ������
	10. �Ƿ��
	11. �Ƿ���
	12. ��Ÿ*/
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
