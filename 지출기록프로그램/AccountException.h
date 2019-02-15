#ifndef __ACCOUNT_EXCPETION_H_
#define __ACCOUNT_EXCPETION_H_

class ExpenseException
{
public:
	virtual void ShowExceptionReason() = 0;
};

class MinusException : public ExpenseException
{
private:
	int reqDep;	// 기록 금액
public:
	MinusException(int money);
	void ShowExceptionReason();
};

class CategoryException : public ExpenseException
{
private:
	int reqCate;	// 요청 분류
public:
	CategoryException(int myCategory);
	void ShowExceptionReason();
};

#endif // !__ACCOUNT_EXCPETION_H_
