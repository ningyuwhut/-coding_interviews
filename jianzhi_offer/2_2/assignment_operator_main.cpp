#include <iostream>
#include "assignment_operator.h"

using namespace std;

//非常变量也可以调用常成员函数，但是常量只能调用常成员函数
int main( int argc, char ** argv ){
//    char tmp[4]="abc";
    char* tmp= new char[4];
    CMyString a(tmp);
    CMyString b=a;
    CMyString d, c;
    d=c=a;
    return 0;
}
