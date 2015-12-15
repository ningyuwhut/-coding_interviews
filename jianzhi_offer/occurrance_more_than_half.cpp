#include <iostream>
using namespace std;
bool occurrance_more_than_half( int* array, int length, int& target);
int partition(int* array, int begin, int end);//闭区间
int main(int argc, char** argv){
    int array[] = {1,2,3,3,2,2,5,4};
    int length=sizeof(array)/sizeof(array[0]);
    cout << "length: " << length << endl;
    int target;
    if( occurrance_more_than_half( array, length, target ) )
	cout << "success " << target << endl;
    else
	cout << "failure" << target << endl;
    return 0;
}

bool occurrance_more_than_half( int* array, int length, int& target){
    if( array == NULL || length <= 0 )
	return false;

    int i=0,j=length-1, middle=length>>1;
    int pivot;

    pivot=partition(array, i, j);//闭区间
    while( pivot != middle ){
	if( pivot < middle )
	    pivot=partition(array, pivot+1, j );
	else
	    pivot=partition(array, i, pivot-1);
    }
    target=array[pivot];
    i=0;
    int count=0;
    while( i < length ){
	cout << "ee " << array[i] << endl;
	if( array[i] == target ){
	    cout << i << " " << array[i] << endl;
	    ++count;
	}
	++i;
    }
    cout << "count " << count << endl;
    if( count > length>> 1 )
	return true;
    return false;
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
