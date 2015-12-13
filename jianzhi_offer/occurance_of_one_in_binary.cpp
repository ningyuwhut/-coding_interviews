#include <iostream>
using namespace std;

//通过右移的方式获得1的个数,但是对于负数会陷入死循环
int occurance_of_one_in_binary_right_shift(int number);
//循环次数是固定的,32位的整数要循环32次
int occurance_of_one_in_binary_left_shift(int number);
int occurance_of_one_in_binary(int number);
int main(){
    int number;
    int occurance;
    number=9;
    while( true ){
	cout << "input a number" << endl;
	cin >> number;
	//occurance=occurance_of_one_in_binary_right_shift(number);
//	occurance=occurance_of_one_in_binary_left_shift(number);
	occurance=occurance_of_one_in_binary(number);
	cout << number << ":" << occurance << endl;
    }
}

int occurance_of_one_in_binary_right_shift(int number){
    int occurance=0;
    while( number != 0 ){
	occurance+= number & 1;
	number >>= 1; //移位操作的效率比除法要高
    }
    return occurance;
}

int occurance_of_one_in_binary_left_shift(int number){
    int mask=1;
    int occurance=0;
    while( mask ){
	if( number & mask )
	    occurance++;
	mask = mask << 1;
    }
    return occurance;
}
int occurance_of_one_in_binary(int number){
    int occurance=0;
    while( number ){
	occurance+=1;
	number=(number-1)&number;
    }
    return occurance;
}
