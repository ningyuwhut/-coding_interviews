#include <iostream>
class A
{
    private:
	int value;
    public:
	A(int n) { value=n;}
	A( A other) { value= other.value; } 
	#此处会有编译错误:
	#error: copy constructor must pass its first argument by reference
	#拷贝构造函数必须传递引用，否则会造成拷贝构造函数的递归调用而导致栈溢出
	void Print() { std::cout << value << std::endl; }
};

int main( int argc, char ** argv ){
    A a=10;
    A b=a;
    b.Print();
    return 0;
}
