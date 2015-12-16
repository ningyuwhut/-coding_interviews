#include <iostream>
#include <time.h>
using namespace std;
void minimum_k_numbers( int* array, int length, int k, int* output);
int partition(int* array, int begin, int end);//闭区间
bool minimum_k_numbers_2( int* array, int length, int k, int* output);

int main(int argc, char** argv){
    int* array;
    int length;
    srand((unsigned)time(NULL));  
    cout << "input length of array :" << endl;
    cin >> length;
    array= new int[length];
    for( int m=0; m < length; ++m ){
	array[m]=rand()%100+1;
	cout << " " <<  array[m]; 
    }
    cout << endl;
	
    int k;
    cout << "input k :" << endl;
    cin >> k;
    int *target = new int[k];
    minimum_k_numbers( array, length, k-1, target );
    cout << "minimum k numbers " << endl;
    for( int i =0 ; i < k; ++i )
	cout << " " << target[i];
    cout << endl;
    return 0;
}
//k是从0开始的
void minimum_k_numbers( int* array, int length, int k, int* output){
    if( array == NULL || output == NULL || length <= 0  || k >= length )
	return;

    int i=0,j=length-1;
    int pivot;

    pivot=partition(array, i, j);//闭区间
    while( pivot != k ){
	if( pivot < k )
	    pivot=partition(array, pivot+1, j );
	else
	    pivot=partition(array, i, pivot-1);
    }

    i=0;
    while( i < length ){
	output[i]=array[i];
	++i;
    }
}
int partition(int* array, int begin, int end){
    int pivot_value=array[begin];
    int i=begin;
    int j=end;
    while( i < j ){
	while( i < j && array[j] >= pivot_value ){
	    --j;
	}
	if( i < j ){
	    array[i]=array[j];
	    ++i;
	}
	while( i < j && array[i] <= pivot_value ){
	    ++i;
	}
	if( i < j ){
	    array[j]=array[i];
	    --j;
	}
    }
    array[i]=pivot_value; //这句代码容易被忘掉
    return i;
}
bool minimum_k_numbers_2( int* array, int length, int& target){
    if( array == NULL || length <= 0  )
	return false;

    target=array[0];
    int occurrance=1;
    int i;
    for( i=1; i< length; ++i ){
	if( occurrance == 0 ){
	    target=array[i];
	    occurrance=1;
	}else{
	    if( array[i] ==target )
		++occurrance;
	    else
		--occurrance;
	}
    }

    i=0;
    int count=0;
    while( i < length ){
	if( array[i] == target ){
	    ++count;
	}
	++i;
    }
    if( count > length>> 1 )
	return true;
    return false;
}
