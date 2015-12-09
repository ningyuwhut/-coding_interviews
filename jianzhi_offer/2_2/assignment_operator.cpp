#include "assignment_operator.h"
#include <string>

CMyString::CMyString(char * pData  ){
    m_pData= pData;
}
//复制构造函数
CMyString::CMyString(const CMyString& str){
    m_pData=new char[strlen(str.get_m_pData())+1]; //深拷贝
    if( m_pData != NULL )
	strcpy(m_pData, str.get_m_pData());
}

CMyString& CMyString::operator=(const CMyString& str){
    if( this != &str ){
	char* tmp_m_pData;
	CMyString tmp(str);
	tmp_m_pData=tmp.m_pData; //类可以访问私有成员
	tmp.m_pData=m_pData;
	m_pData=tmp_m_pData;
    }
    return *this;
}

char* CMyString::get_m_pData() const{
    return m_pData;
}
CMyString::~CMyString(void){
    if( m_pData != NULL )
	delete [] m_pData;
}
