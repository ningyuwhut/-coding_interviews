#ifndef ASSIGNMENT_OPERATOR_H
#define ASSIGNMENT_OPERATOR_H
#include <stddef.h>
class CMyString{
    public:
	CMyString( char* pData = NULL );
	CMyString(const CMyString& str );
	CMyString& operator=(const CMyString& str);
	char* get_m_pData() const; //常成员函数
	~CMyString(void);

    private:
	char * m_pData;
};
#endif
